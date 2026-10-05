#include "ArbolB.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <QTableWidget>
#include <QString>

// --- Constructor del Árbol ---
ArbolB::ArbolB() {
    raiz = nullptr;
    orden = 4;
}

// --- Inserción Principal ---
void ArbolB::insertar(Cliente cliente) {
    if (raiz == nullptr) {
        raiz = new NodoB(true);
        raiz->clientes[0] = new Cliente(cliente);
        raiz->conteo_claves = 1;
    } else {
        if (raiz->conteo_claves == 3) {
            NodoB* nuevaRaiz = new NodoB(false);
            nuevaRaiz->hijos[0] = raiz;
            nuevaRaiz->dividirHijo(0, raiz);

            int i = 0;
            if (nuevaRaiz->clientes[0]->id < cliente.id) {
                i++;
            }
            nuevaRaiz->hijos[i]->insertarNoLleno(cliente);

            raiz = nuevaRaiz;
        } else {
            raiz->insertarNoLleno(cliente);
        }
    }
}

// --- Generar Reporte Graphviz ---
void ArbolB::generarReporteGraphviz() {
    std::ofstream archivo("reporte_clientes.dot");
    if (!archivo.is_open()) return;

    archivo << "digraph ArbolB {\n";
    archivo << "  node [shape=record, fontname=\"Helvetica\"];\n";

    if (raiz != nullptr) {
        generarDOTBTree(raiz, archivo);
    }

    archivo << "}\n";
    archivo.close();

    system("dot -Tpng reporte_clientes.dot -o reporte_clientes.png");
}

void ArbolB::generarDOTBTree(NodoB* nodo, std::ofstream& archivo) {
    if (nodo == nullptr) return;

    // Generamos un ID único para Graphviz usando la dirección de memoria del nodo
    std::string idNodo = "nodo" + std::to_string(reinterpret_cast<uintptr_t>(nodo));

    // --- 1. LÓGICA DE COLORES ---
    std::string color = "\"#bbdefb\""; // Azul claro por defecto (Nodos Internos)

    if (nodo == raiz && nodo->es_hoja) {
        color = "\"#a5d6a7\""; // Verde suave (Si la raíz es el único nodo/hoja del árbol)
    } else if (nodo == raiz) {
        color = "\"#64b5f6\""; // Azul más fuerte (Raíz principal con hijos)
    } else if (nodo->es_hoja) {
        color = "\"#ffe082\""; // Naranja/Amarillo claro (Hojas finales)
    }

    // --- 2. DIBUJAR NODO (CAJA CON COMPARTIMENTOS) ---
    // Usamos shape=record para dividir el nodo y | para separar cada cliente
    archivo << "  " << idNodo << " [style=filled, fillcolor=" << color << ", label=\"";

    for (int i = 0; i < nodo->conteo_claves; i++) {
        // Formato: ID \n Nombre \n Correo
        archivo << "<f" << i << "> "
                << "ID: " << nodo->clientes[i]->id << "\\n"
                << nodo->clientes[i]->nombre << "\\n"
                << nodo->clientes[i]->correo;

        // Separador de compartimentos (excepto para el último cliente del nodo)
        if (i < nodo->conteo_claves - 1) {
            archivo << " | ";
        }
    }
    archivo << "\"];\n";

    // --- 3. DIBUJAR FLECHAS (Hasta 4 hijos) ---
    if (!nodo->es_hoja) {
        for (int i = 0; i <= nodo->conteo_claves; i++) {
            if (nodo->hijos[i] != nullptr) {
                std::string idHijo = "nodo" + std::to_string(reinterpret_cast<uintptr_t>(nodo->hijos[i]));

                // Enlazar desde el compartimento específico hacia el hijo
                archivo << "  " << idNodo << ":f" << i << " -> " << idHijo << ";\n";

                generarDOTBTree(nodo->hijos[i], archivo);
            }
        }
    }
}

// --- Poblar Tabla de la UI ---
// --- Poblar Tabla de la UI con Selección de Recorrido ---
void ArbolB::poblarTablaUI(QTableWidget* tabla, QString tipoRecorrido) {
    tabla->setRowCount(0);

    if (tabla->columnCount() == 0) {
        tabla->setColumnCount(6);
        tabla->setHorizontalHeaderLabels({"ID", "Nombre", "Correo", "Teléfono", "Contraseña", "Tipo"});
    }

    // Usamos el string del ComboBox para decidir qué recursividad lanzar
    if (tipoRecorrido == "Preorden") {
        preordenTabla(raiz, tabla);
    } else if (tipoRecorrido == "Postorden") {
        postordenTabla(raiz, tabla);
    } else {
        inordenTabla(raiz, tabla); // Inorden por defecto
    }
}

// 1. RECORRIDO INORDEN (Ordenado)
void ArbolB::inordenTabla(NodoB* nodo, QTableWidget* tabla) {
    if (nodo == nullptr) return;

    int i;
    for (i = 0; i < nodo->conteo_claves; i++) {
        if (!nodo->es_hoja) {
            inordenTabla(nodo->hijos[i], tabla);
        }

        int filaActual = tabla->rowCount();
        tabla->insertRow(filaActual);
        tabla->setItem(filaActual, 0, new QTableWidgetItem(QString::fromStdString(nodo->clientes[i]->id)));
        tabla->setItem(filaActual, 1, new QTableWidgetItem(QString::fromStdString(nodo->clientes[i]->nombre)));
        tabla->setItem(filaActual, 2, new QTableWidgetItem(QString::fromStdString(nodo->clientes[i]->correo)));
        tabla->setItem(filaActual, 3, new QTableWidgetItem(QString::fromStdString(nodo->clientes[i]->telefono)));
        tabla->setItem(filaActual, 4, new QTableWidgetItem(QString::fromStdString(nodo->clientes[i]->password)));
        tabla->setItem(filaActual, 5, new QTableWidgetItem(QString::fromStdString(nodo->clientes[i]->tipo)));
    }

    if (!nodo->es_hoja) {
        inordenTabla(nodo->hijos[i], tabla);
    }
}

// 2. RECORRIDO PREORDEN (Raíces primero, luego hojas)
void ArbolB::preordenTabla(NodoB* nodo, QTableWidget* tabla) {
    if (nodo == nullptr) return;

    // Primero: Extraemos todas las claves del nodo actual
    for (int i = 0; i < nodo->conteo_claves; i++) {
        int filaActual = tabla->rowCount();
        tabla->insertRow(filaActual);
        tabla->setItem(filaActual, 0, new QTableWidgetItem(QString::fromStdString(nodo->clientes[i]->id)));
        tabla->setItem(filaActual, 1, new QTableWidgetItem(QString::fromStdString(nodo->clientes[i]->nombre)));
        tabla->setItem(filaActual, 2, new QTableWidgetItem(QString::fromStdString(nodo->clientes[i]->correo)));
        tabla->setItem(filaActual, 3, new QTableWidgetItem(QString::fromStdString(nodo->clientes[i]->telefono)));
        tabla->setItem(filaActual, 4, new QTableWidgetItem(QString::fromStdString(nodo->clientes[i]->password)));
        tabla->setItem(filaActual, 5, new QTableWidgetItem(QString::fromStdString(nodo->clientes[i]->tipo)));
    }

    // Segundo: Bajamos a todos los hijos de izquierda a derecha
    if (!nodo->es_hoja) {
        for (int i = 0; i <= nodo->conteo_claves; i++) {
            preordenTabla(nodo->hijos[i], tabla);
        }
    }
}

// 3. RECORRIDO POSTORDEN (Hojas primero, luego raíces)
void ArbolB::postordenTabla(NodoB* nodo, QTableWidget* tabla) {
    if (nodo == nullptr) return;

    // Primero: Bajamos a todos los hijos profundamente
    if (!nodo->es_hoja) {
        for (int i = 0; i <= nodo->conteo_claves; i++) {
            postordenTabla(nodo->hijos[i], tabla);
        }
    }

    // Segundo: Al regresar de la recursividad, extraemos las claves
    for (int i = 0; i < nodo->conteo_claves; i++) {
        int filaActual = tabla->rowCount();
        tabla->insertRow(filaActual);
        tabla->setItem(filaActual, 0, new QTableWidgetItem(QString::fromStdString(nodo->clientes[i]->id)));
        tabla->setItem(filaActual, 1, new QTableWidgetItem(QString::fromStdString(nodo->clientes[i]->nombre)));
        tabla->setItem(filaActual, 2, new QTableWidgetItem(QString::fromStdString(nodo->clientes[i]->correo)));
        tabla->setItem(filaActual, 3, new QTableWidgetItem(QString::fromStdString(nodo->clientes[i]->telefono)));
        tabla->setItem(filaActual, 4, new QTableWidgetItem(QString::fromStdString(nodo->clientes[i]->password)));
        tabla->setItem(filaActual, 5, new QTableWidgetItem(QString::fromStdString(nodo->clientes[i]->tipo)));
    }
}

// --- Métodos de Búsqueda ---
Cliente* ArbolB::buscar(std::string id) {
    if (raiz == nullptr) return nullptr;
    return raiz->buscar(id);
}

Cliente* ArbolB::buscarPorCorreo(std::string correo) {
    return buscarPorCorreoRecursivo(raiz, correo);
}

Cliente* ArbolB::buscarPorCorreoRecursivo(NodoB* nodo, std::string correo) {
    if (nodo == nullptr) return nullptr;

    int i;
    for (i = 0; i < nodo->conteo_claves; i++) {
        if (!nodo->es_hoja) {
            Cliente* encontrado = buscarPorCorreoRecursivo(nodo->hijos[i], correo);
            if (encontrado != nullptr) return encontrado;
        }

        if (nodo->clientes[i]->correo == correo) {
            return nodo->clientes[i];
        }
    }

    if (!nodo->es_hoja) {
        return buscarPorCorreoRecursivo(nodo->hijos[i], correo);
    }

    return nullptr;
}

// --- Método de Eliminación ---
void ArbolB::eliminar(std::string id) {
    if (raiz == nullptr) return;

    raiz->eliminar(id);

    if (raiz->conteo_claves == 0) {
        NodoB* temporal = raiz;

        if (raiz->es_hoja) {
            raiz = nullptr;
        } else {
            raiz = raiz->hijos[0];
        }

        delete temporal;
    }
}















