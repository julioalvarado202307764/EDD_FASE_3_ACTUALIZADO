#include "ArbolAVL.h"
#include <fstream>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <cstdlib> // Para ejecutar comandos del sistema
#include <QTime>
#include <QString>
#include <QProcess>
#include "ArbolPeliculas.h"
#include <QDate>
#include "Pelicula.h"
#include <QDebug>
#include <QFile>

// Añadir en ArbolAVL.cpp
ArbolAVL::ArbolAVL() {
    raiz = nullptr;
}
// Métodos auxiliares de altura y balance
int ArbolAVL::obtenerAltura(NodoAVL* nodo) {
    if (nodo == nullptr) return 0;
    return nodo->altura;
}

int ArbolAVL::obtenerFactorBalance(NodoAVL* nodo) {
    if (nodo == nullptr) return 0;
    return obtenerAltura(nodo->izquierdo) - obtenerAltura(nodo->derecho);
}

// Rotaciones para garantizar el balanceo automático
NodoAVL* ArbolAVL::rotacionDerecha(NodoAVL* y) {
    NodoAVL* x = y->izquierdo;
    NodoAVL* T2 = x->derecho;

    x->derecho = y;
    y->izquierdo = T2;

    y->altura = std::max(obtenerAltura(y->izquierdo), obtenerAltura(y->derecho)) + 1;
    x->altura = std::max(obtenerAltura(x->izquierdo), obtenerAltura(x->derecho)) + 1;

    return x;
}

NodoAVL* ArbolAVL::rotacionIzquierda(NodoAVL* x) {
    NodoAVL* y = x->derecho;
    NodoAVL* T2 = y->izquierdo;

    y->izquierdo = x;
    x->derecho = T2;

    x->altura = std::max(obtenerAltura(x->izquierdo), obtenerAltura(x->derecho)) + 1;
    y->altura = std::max(obtenerAltura(y->izquierdo), obtenerAltura(y->derecho)) + 1;

    return y;
}

// Inserción interna del AVL. La creación física del archivo de asientos se
// controla de forma independiente mediante inicializarArchivo.
NodoAVL* ArbolAVL::insertarNodo(NodoAVL* nodo,
                                std::string codigo,
                                std::string pelicula,
                                std::string codigoPeliculaReal,
                                std::string fecha,
                                std::string codigoSede,
                                std::string hor,
                                std::string sal,
                                int f,
                                int c,
                                std::string archivoAsientos,
                                bool inicializarArchivo) {
    if (nodo == nullptr) {
        NodoAVL* nuevoNodo = new NodoAVL(codigo,
                                         pelicula,
                                         codigoPeliculaReal,
                                         fecha,
                                         codigoSede,
                                         hor,
                                         sal,
                                         f,
                                         c,
                                         archivoAsientos);

        if (inicializarArchivo) {
            inicializarArchivoAsientos(nuevoNodo);
        }

        return nuevoNodo;
    }

    if (codigo < nodo->codigo_funcion) {
        nodo->izquierdo = insertarNodo(nodo->izquierdo, codigo, pelicula, codigoPeliculaReal, fecha, codigoSede, hor, sal, f, c, archivoAsientos, inicializarArchivo);
    }
    else if (codigo > nodo->codigo_funcion) {
        nodo->derecho = insertarNodo(nodo->derecho, codigo, pelicula, codigoPeliculaReal, fecha, codigoSede, hor, sal, f, c, archivoAsientos, inicializarArchivo);
    }
    else {
        return nodo; // No se permiten funciones duplicadas
    }

    nodo->altura = 1 + std::max(obtenerAltura(nodo->izquierdo), obtenerAltura(nodo->derecho));
    int balance = obtenerFactorBalance(nodo);

    if (balance > 1 && codigo < nodo->izquierdo->codigo_funcion)
        return rotacionDerecha(nodo);
    if (balance < -1 && codigo > nodo->derecho->codigo_funcion)
        return rotacionIzquierda(nodo);
    if (balance > 1 && codigo > nodo->izquierdo->codigo_funcion) {
        nodo->izquierdo = rotacionIzquierda(nodo->izquierdo);
        return rotacionDerecha(nodo);
    }
    if (balance < -1 && codigo < nodo->derecho->codigo_funcion) {
        nodo->derecho = rotacionDerecha(nodo->derecho);
        return rotacionIzquierda(nodo);
    }

    return nodo;
}

void ArbolAVL::inicializarArchivoAsientos(NodoAVL* nodo) {
    if (nodo == nullptr) return;

    std::ofstream archivo(nodo->archivo_asientos);
    if (archivo.is_open()) {
        archivo << "{\n";
        archivo << "  \"codigo_funcion\": \"" << nodo->codigo_funcion << "\",\n";
        archivo << "  \"filas\": " << nodo->filas << ",\n";
        archivo << "  \"columnas\": " << nodo->columnas << ",\n";
        archivo << "  \"asientos_ocupados\": []\n";
        archivo << "}\n";
        archivo.close();
    } else {
        std::cerr << "Error al crear el archivo JSON de la función.\n";
    }
}

// Método principal público
void ArbolAVL::generarReporteGraphviz(ArbolPeliculas* arbolPelis) {
    QFile::remove("reporte_avl.png");
    std::ofstream archivo("reporte_avl.dot");
    if (!archivo.is_open()) return;

    archivo << "digraph ArbolAVL {\n";
    archivo << "  node [shape=record, fontname=\"Helvetica\"];\n";

    QDate fechaActual = QDate::currentDate(); // Obtenemos la fecha de hoy

    if (raiz != nullptr) {
        generarDOTRecursivo(raiz, archivo, arbolPelis, fechaActual);
    }

    archivo << "}\n";
    archivo.close();

    QProcess comando;
    comando.start("dot", QStringList() << "-Tpng" << "reporte_avl.dot" << "-o" << "reporte_avl.png");
    comando.waitForFinished();
}


// Método recursivo privado
void ArbolAVL::generarDOTRecursivo(NodoAVL* nodo, std::ofstream& archivo, ArbolPeliculas* arbolPelis, QDate fechaActual) {
    if (nodo == nullptr) return;

    QString color = "#c8e6c9"; // Verde por defecto (Vigente)
    QString fechaFinStr = "NO ENCONTRADA"; // Texto por defecto por si falla

    // --- LÓGICA DE VALIDACIÓN CON EL ÁRBOL DE PELÍCULAS ---
    if (arbolPelis != nullptr) {
        // Aunque la variable se llame 'codigo_pelicula', sabemos que contiene el TÍTULO
        QString tituloBuscado = QString::fromStdString(nodo->codigo_pelicula).trimmed();

        // Llamamos al nuevo método exhaustivo
        Pelicula* pelicula = arbolPelis->buscarPeliculaPorTitulo(tituloBuscado);

        if (pelicula != nullptr) {
            // Actualizamos la variable para que Graphviz pinte la fecha real
            fechaFinStr = pelicula->fechaFin;

            QDate fechaFin = QDate::fromString(fechaFinStr, "yyyy-MM-dd");
            if (!fechaFin.isValid()) {
                fechaFin = QDate::fromString(fechaFinStr, "dd/MM/yyyy"); // Fallback
            }

            // Si la fecha de fin de la película ya venció, pintamos la función de rojo pastel
            if (fechaFin.isValid() && fechaFin < fechaActual) {
                color = "#ffcdd2";
            }
        }
    }
    // ------------------------------------------------------

    // Limpiamos los strings para evitar que un '\r' rompa Graphviz
    std::string codFunc = QString::fromStdString(nodo->codigo_funcion).trimmed().toStdString();
    std::string titPeli = QString::fromStdString(nodo->codigo_pelicula).trimmed().toStdString();

    // Declarar el nodo actual con forma circular (circle) y los nuevos campos
    // Usamos \\n para que Graphviz entienda que debe hacer un salto de línea en el texto
    archivo << "  node_" << codFunc
            << " [shape=circle, style=filled, fillcolor=\"" << color.toStdString()
            << "\", label=\""
            << "Func: " << codFunc << "\\n"
            << "Peli: " << titPeli << "\\n"
            << "Sala: " << nodo->sala << "\\n"         // <-- Agregamos Sala
            << "Horario: " << nodo->horario << "\\n"   // <-- Agregamos Horario (ajusta el nombre si tu variable se llama diferente)
            << "Vence: " << fechaFinStr.toStdString()
            << "\"];\n";

    // Conectar con el hijo izquierdo
    if (nodo->izquierdo != nullptr) {
        std::string codIzq = QString::fromStdString(nodo->izquierdo->codigo_funcion).trimmed().toStdString();
        archivo << "  node_" << codFunc << " -> node_" << codIzq << ";\n";
        generarDOTRecursivo(nodo->izquierdo, archivo, arbolPelis, fechaActual);
    }

    // Conectar con el hijo derecho
    if (nodo->derecho != nullptr) {
        std::string codDer = QString::fromStdString(nodo->derecho->codigo_funcion).trimmed().toStdString();
        archivo << "  node_" << codFunc << " -> node_" << codDer << ";\n";
        generarDOTRecursivo(nodo->derecho, archivo, arbolPelis, fechaActual);
    }
}

void ArbolAVL::poblarComboFunciones(QString pelicula, QComboBox* combo) {
    combo->clear(); // Limpiamos opciones anteriores
    inordenCombo(raiz, pelicula, combo);
}

void ArbolAVL::inordenCombo(NodoAVL* nodo, QString pelicula, QComboBox* combo) {
    if (nodo != nullptr) {
        // 1. Recorrer hijo izquierdo
        inordenCombo(nodo->izquierdo, pelicula, combo);

        // 2. Evaluar coincidencia exacta de la película
        if (QString::fromStdString(nodo->codigo_pelicula) == pelicula) {

            // Texto visual para el usuario: "F001 - 17:00 - Sala 2"
            QString textoVisual = QString::fromStdString(nodo->codigo_funcion) + " - " +
                                  QString::fromStdString(nodo->horario) + " - " +
                                  QString::fromStdString(nodo->sala);

            // Guardamos el código (F001) de forma invisible en el item
            QString codigoOculto = QString::fromStdString(nodo->codigo_funcion);

            combo->addItem(textoVisual, codigoOculto);
        }

        // 3. Recorrer hijo derecho
        inordenCombo(nodo->derecho, pelicula, combo);
    }
}

// API histórica de Fase 2. Mantiene exactamente el comportamiento de crear
// el archivo de asientos para una función nueva.
void ArbolAVL::insertar(std::string codigo, std::string pelicula, std::string hor, std::string sal, int f, int c) {
    this->raiz = insertarNodo(this->raiz, codigo, pelicula, "", "", "", hor, sal, f, c, "", true);
}

// Inserción extendida para una función nueva.
void ArbolAVL::insertar(std::string codigo,
                        std::string pelicula,
                        std::string codigoPeliculaReal,
                        std::string fecha,
                        std::string codigoSede,
                        std::string hor,
                        std::string sal,
                        int f,
                        int c) {
    this->raiz = insertarNodo(this->raiz, codigo, pelicula, codigoPeliculaReal, fecha, codigoSede, hor, sal, f, c, "", true);
}

// Inserción no destructiva preparada para reconstruir datos ya existentes.
void ArbolAVL::insertarExistente(std::string codigo,
                                 std::string pelicula,
                                 std::string codigoPeliculaReal,
                                 std::string fecha,
                                 std::string codigoSede,
                                 std::string hor,
                                 std::string sal,
                                 int f,
                                 int c,
                                 std::string archivoAsientos) {
    this->raiz = insertarNodo(this->raiz, codigo, pelicula, codigoPeliculaReal, fecha, codigoSede, hor, sal, f, c, archivoAsientos, false);
}

void ArbolAVL::recorrerFunciones(VisitanteFuncionAVL visita,
                                 void* contexto) const {
    if (visita == nullptr) {
        return;
    }

    recorrerFuncionesRecursivo(raiz, visita, contexto);
}

void ArbolAVL::recorrerFuncionesRecursivo(NodoAVL* nodo,
                                          VisitanteFuncionAVL visita,
                                          void* contexto) const {
    if (nodo == nullptr) {
        return;
    }

    recorrerFuncionesRecursivo(nodo->izquierdo, visita, contexto);

    visita(nodo, contexto);

    recorrerFuncionesRecursivo(nodo->derecho, visita, contexto);
}

// NUEVO: Búsqueda para obtener el nodo completo
NodoAVL* ArbolAVL::buscarFuncion(QString codigo) {
    return buscarRecursivoAVL(raiz, codigo);
}

NodoAVL* ArbolAVL::buscarRecursivoAVL(NodoAVL* nodo, QString codigo) {
    if (nodo == nullptr || QString::fromStdString(nodo->codigo_funcion) == codigo) {
        return nodo;
    }
    if (codigo < QString::fromStdString(nodo->codigo_funcion)) {
        return buscarRecursivoAVL(nodo->izquierdo, codigo);
    }
    return buscarRecursivoAVL(nodo->derecho, codigo);
}

void ArbolAVL::poblarTablaUI(QTableWidget* tabla) {
    tabla->setRowCount(0); // Limpiar filas

    // ---> AÑADIR ESTO: Configurar columnas y encabezados obligatoriamente <---
    if (tabla->columnCount() < 6) {
        tabla->setColumnCount(6);
        tabla->setHorizontalHeaderLabels(QStringList() << "Código" << "Película" << "Horario" << "Sala" << "Filas" << "Columnas");
    }

    int fila = 0;
    poblarTablaRecursivo(raiz, tabla, fila);

    // Opcional: Esto ajusta el ancho de las columnas al texto para que se vea mejor
    tabla->resizeColumnsToContents();
}
void ArbolAVL::poblarTablaRecursivo(NodoAVL* nodo, QTableWidget* tabla, int& fila) {
    if (nodo != nullptr) {
        poblarTablaRecursivo(nodo->izquierdo, tabla, fila);

        tabla->insertRow(fila);
        tabla->setItem(fila, 0, new QTableWidgetItem(QString::fromStdString(nodo->codigo_funcion)));
        tabla->setItem(fila, 1, new QTableWidgetItem(QString::fromStdString(nodo->codigo_pelicula)));
        tabla->setItem(fila, 2, new QTableWidgetItem(QString::fromStdString(nodo->horario)));
        tabla->setItem(fila, 3, new QTableWidgetItem(QString::fromStdString(nodo->sala)));
        tabla->setItem(fila, 4, new QTableWidgetItem(QString::number(nodo->filas)));
        tabla->setItem(fila, 5, new QTableWidgetItem(QString::number(nodo->columnas)));

        fila++;
        poblarTablaRecursivo(nodo->derecho, tabla, fila);
    }
}

// --- ELIMINACIÓN AVL Y BALANCEO AUTOMÁTICO ---

// Puente público
void ArbolAVL::eliminar(std::string codigo) {
    raiz = eliminarNodo(raiz, codigo);
}

// Método auxiliar para buscar el menor en el subárbol derecho
NodoAVL* encontrarMinimoAVL(NodoAVL* nodo) {
    NodoAVL* actual = nodo;
    while (actual->izquierdo != nullptr)
        actual = actual->izquierdo;
    return actual;
}

// Recursividad de eliminación
NodoAVL* ArbolAVL::eliminarNodo(NodoAVL* nodo, std::string codigo) {
    // 1. ELIMINACIÓN ESTÁNDAR DE BST
    if (nodo == nullptr) return nodo;

    if (codigo < nodo->codigo_funcion) {
        nodo->izquierdo = eliminarNodo(nodo->izquierdo, codigo);
    }
    else if (codigo > nodo->codigo_funcion) {
        nodo->derecho = eliminarNodo(nodo->derecho, codigo);
    }
    else {
        // Encontramos el nodo a eliminar

        // Caso A o B: Cero o un solo hijo
        if ((nodo->izquierdo == nullptr) || (nodo->derecho == nullptr)) {
            NodoAVL* temp = nodo->izquierdo ? nodo->izquierdo : nodo->derecho;

            if (temp == nullptr) { // Sin hijos
                temp = nodo;
                nodo = nullptr;
            } else { // Un hijo
                *nodo = *temp; // Copia el contenido del hijo no vacío
            }
            delete temp;
        }
        // Caso C: Dos hijos
        else {
            // Buscamos el sucesor inorden (el menor de los mayores)
            NodoAVL* temp = encontrarMinimoAVL(nodo->derecho);

            // Copiamos los datos exactos del sucesor al nodo actual
            nodo->codigo_funcion = temp->codigo_funcion;
            nodo->codigo_pelicula = temp->codigo_pelicula;
            nodo->codigo_pelicula_real = temp->codigo_pelicula_real;
            nodo->fecha = temp->fecha;
            nodo->codigo_sede = temp->codigo_sede;
            nodo->horario = temp->horario;
            nodo->sala = temp->sala;
            nodo->filas = temp->filas;
            nodo->columnas = temp->columnas;
            nodo->archivo_asientos = temp->archivo_asientos;

            // Borramos el sucesor que quedó duplicado abajo
            nodo->derecho = eliminarNodo(nodo->derecho, temp->codigo_funcion);
        }
    }

    // Si el árbol quedó vacío después de borrar el único nodo
    if (nodo == nullptr) return nodo;

    // 2. ACTUALIZAR ALTURA DEL NODO ACTUAL
    nodo->altura = 1 + std::max(obtenerAltura(nodo->izquierdo), obtenerAltura(nodo->derecho));

    // 3. OBTENER FACTOR DE BALANCE PARA VERIFICAR SI SE DESBALANCEÓ
    int balance = obtenerFactorBalance(nodo);

    // 4. RE-BALANCEO (Los 4 casos de rotación)

    // Caso Izquierda-Izquierda
    if (balance > 1 && obtenerFactorBalance(nodo->izquierdo) >= 0)
        return rotacionDerecha(nodo);

    // Caso Izquierda-Derecha
    if (balance > 1 && obtenerFactorBalance(nodo->izquierdo) < 0) {
        nodo->izquierdo = rotacionIzquierda(nodo->izquierdo);
        return rotacionDerecha(nodo);
    }

    // Caso Derecha-Derecha
    if (balance < -1 && obtenerFactorBalance(nodo->derecho) <= 0)
        return rotacionIzquierda(nodo);

    // Caso Derecha-Izquierda
    if (balance < -1 && obtenerFactorBalance(nodo->derecho) > 0) {
        nodo->derecho = rotacionDerecha(nodo->derecho);
        return rotacionIzquierda(nodo);
    }

    return nodo;
}

void ArbolAVL::testConsola(NodoAVL* nodo) {
    if (nodo != nullptr) {
        testConsola(nodo->izquierdo);
        qDebug() << "Encontrado en RAM:" << QString::fromStdString(nodo->codigo_funcion);
        testConsola(nodo->derecho);
    }
}

void ArbolAVL::poblarTablaFuncionesUI(QTableWidget* tabla, QString tipoRecorrido) {
    tabla->setRowCount(0); // 1. Limpiamos la tabla visualmente

    // 2. Configuramos las cabeceras si no se hizo en Qt Designer
    if (tabla->columnCount() == 0) {
        tabla->setColumnCount(4);
        tabla->setHorizontalHeaderLabels({"Código Función", "Película", "Sala", "Horario"});
    }

    // 3. Disparamos la recursividad según el ComboBox
    if (tipoRecorrido == "Preorden") {
        preordenTabla(raiz, tabla);
    } else if (tipoRecorrido == "Postorden") {
        postordenTabla(raiz, tabla);
    } else {
        inordenTabla(raiz, tabla); // Inorden por defecto
    }
}

// --- 1. INORDEN (Izquierda, Raíz, Derecha) ---
void ArbolAVL::inordenTabla(NodoAVL* nodo, QTableWidget* tabla) {
    if (nodo != nullptr) {
        inordenTabla(nodo->izquierdo, tabla);

        int fila = tabla->rowCount();
        tabla->insertRow(fila);
        tabla->setItem(fila, 0, new QTableWidgetItem(QString::fromStdString(nodo->codigo_funcion)));
        tabla->setItem(fila, 1, new QTableWidgetItem(QString::fromStdString(nodo->codigo_pelicula)));
        tabla->setItem(fila, 2, new QTableWidgetItem(QString::fromStdString(nodo->sala)));
        tabla->setItem(fila, 3, new QTableWidgetItem(QString::fromStdString(nodo->horario)));

        inordenTabla(nodo->derecho, tabla);
    }
}

// --- 2. PREORDEN (Raíz, Izquierda, Derecha) ---
void ArbolAVL::preordenTabla(NodoAVL* nodo, QTableWidget* tabla) {
    if (nodo != nullptr) {
        int fila = tabla->rowCount();
        tabla->insertRow(fila);
        tabla->setItem(fila, 0, new QTableWidgetItem(QString::fromStdString(nodo->codigo_funcion)));
        tabla->setItem(fila, 1, new QTableWidgetItem(QString::fromStdString(nodo->codigo_pelicula)));
        tabla->setItem(fila, 2, new QTableWidgetItem(QString::fromStdString(nodo->sala)));
        tabla->setItem(fila, 3, new QTableWidgetItem(QString::fromStdString(nodo->horario)));

        preordenTabla(nodo->izquierdo, tabla);
        preordenTabla(nodo->derecho, tabla);
    }
}

// --- 3. POSTORDEN (Izquierda, Derecha, Raíz) ---
void ArbolAVL::postordenTabla(NodoAVL* nodo, QTableWidget* tabla) {
    if (nodo != nullptr) {
        postordenTabla(nodo->izquierdo, tabla);
        postordenTabla(nodo->derecho, tabla);

        int fila = tabla->rowCount();
        tabla->insertRow(fila);
        tabla->setItem(fila, 0, new QTableWidgetItem(QString::fromStdString(nodo->codigo_funcion)));
        tabla->setItem(fila, 1, new QTableWidgetItem(QString::fromStdString(nodo->codigo_pelicula)));
        tabla->setItem(fila, 2, new QTableWidgetItem(QString::fromStdString(nodo->sala)));
        tabla->setItem(fila, 3, new QTableWidgetItem(QString::fromStdString(nodo->horario)));
    }
}