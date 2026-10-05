#include "TablaHash.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <fstream>
#include <QProcess>
#include <QString>
#include <iostream>
// Constructor: inicializa el vector de buckets
TablaHash::TablaHash(int cap) {
    capacidad = cap;
    cantidad_elementos = 0;
    tabla.assign(capacidad, nullptr); // Vector lleno de punteros nulos
}

// Función Hash: Conversión de clave a índice
int TablaHash::funcionHash(std::string clave) {
    int hash = 0;
    // Suma de valores ASCII del codigo_reserva
    for (char c : clave) {
        hash += c;
    }
    return hash % capacidad;
}

// Inserción manejando colisiones mediante Listas Enlazadas
void TablaHash::insertar(Reserva* reserva) {
    int indice = funcionHash(reserva->codigo_reserva);
    NodoHash* nuevoNodo = new NodoHash(reserva);

    if (tabla[indice] == nullptr) {
        // Bucket vacío, inserción directa
        tabla[indice] = nuevoNodo;
    } else {
        // Manejo de colisión: inserción al inicio de la lista para O(1)[cite: 1]
        nuevoNodo->siguiente = tabla[indice];
        tabla[indice] = nuevoNodo;
    }
    cantidad_elementos++;
}

// Búsqueda para consultar o cancelar reservas[cite: 1]
Reserva* TablaHash::buscar(std::string codigo_reserva) {
    int indice = funcionHash(codigo_reserva);
    NodoHash* actual = tabla[indice];

    // Recorrido de la lista enlazada en caso de colisión[cite: 1]
    while (actual != nullptr) {
        if (actual->reserva->codigo_reserva == codigo_reserva) {
            return actual->reserva;
        }
        actual = actual->siguiente;
    }
    return nullptr; // Reserva no encontrada
}

/*
void TablaHash::generarReporteGraphviz() {
    std::ofstream archivo("reporte_hash.dot");
    if (!archivo.is_open()) return;

    // --- 1. CÁLCULO DE ESTADÍSTICAS ---
    int totalReservas = 0;
    int bucketsOcupados = 0;
    int totalColisiones = 0;

    for (int i = 0; i < capacidad; i++) {
        if (tabla[i] != nullptr) {
            bucketsOcupados++;
            int elementosEnBucket = 0;
            NodoHash* actual = tabla[i];

            while (actual != nullptr) {
                elementosEnBucket++;
                actual = actual->siguiente;
            }

            totalReservas += elementosEnBucket;
            totalColisiones += (elementosEnBucket - 1);
        }
    }

    // --- 2. CONFIGURACIÓN GRAPHVIZ ---
    archivo << "digraph TablaHash {\n";
    archivo << "  rankdir=LR;\n";
    archivo << "  node [shape=record, fontname=\"Helvetica\"];\n";

    // --- 3. DIBUJAR NODO DE ESTADÍSTICAS ---
    archivo << "  stats [shape=note, style=filled, fillcolor=\"#fff9c4\", label=\"ESTADÍSTICAS GLOBALES\\n"
            << "Tamaño de Tabla: " << capacidad << "\\n"
            << "Total Reservas: " << totalReservas << "\\n"
            << "Buckets Ocupados: " << bucketsOcupados << "\\n"
            << "Colisiones: " << totalColisiones << "\"];\n\n";

    // --- 4. DIBUJAR SOLO BUCKETS OCUPADOS Y LISTAS ENLAZADAS ---
    for (int i = 0; i < capacidad; i++) {

        // SOLO procesamos si el bucket NO está vacío
        if (tabla[i] != nullptr) {
            std::string idBucket = "bucket" + std::to_string(i);

            // Bucket Ocupado (Azul claro)
            archivo << "  " << idBucket << " [label=\"" << i << " | Ocupado\", style=filled, fillcolor=\"#bbdefb\"];\n";

            // Recorrer la lista enlazada (Colisiones)
            NodoHash* actual = tabla[i];
            int idxLista = 0;
            std::string nodoAnterior = idBucket;

            while (actual != nullptr) {
                std::string idNodoData = "data_" + std::to_string(i) + "_" + std::to_string(idxLista);

                std::string codReserva = actual->reserva->codigo_reserva;
                std::string idCliente = actual->reserva->id_cliente;
                std::string codFuncion = actual->reserva->codigo_funcion;

                // Nodo verde para representar la reserva
                archivo << "  " << idNodoData << " [label=\"{Clave: " << codReserva
                        << " | Cliente: " << idCliente
                        << " | Función: " << codFuncion
                        << "}\", style=filled, fillcolor=\"#c8e6c9\"];\n";

                archivo << "  " << nodoAnterior << " -> " << idNodoData << ";\n";

                nodoAnterior = idNodoData;
                actual = actual->siguiente;
                idxLista++;
            }
        }
    }

    // --- 5. ALINEACIÓN VERTICAL ---
    // IMPORTANTE: Ahora también filtramos aquí para alinear SOLO los buckets que se dibujaron
    archivo << "\n  { rank=same; ";
    for (int i = 0; i < capacidad; i++) {
        if (tabla[i] != nullptr) {
            archivo << "bucket" << i << "; ";
        }
    }
    archivo << "}\n";

    archivo << "}\n";
    archivo.close();

    // Generar la imagen PNG
    QProcess comando;
    comando.start("dot", QStringList() << "-Tpng" << "reporte_hash.dot" << "-o" << "reporte_hash.png");
    comando.waitForFinished();
}
*/

void TablaHash::generarReporteGraphviz() {
    std::ofstream archivo("reporte_hash.dot");
    if (!archivo.is_open()) return;

    // --- 1. CÁLCULO DE ESTADÍSTICAS ---
    int totalReservas = 0;
    int bucketsOcupados = 0;
    int totalColisiones = 0;

    // Recorremos el std::vector
    for (int i = 0; i < capacidad; i++) {
        if (tabla[i] != nullptr) {
            bucketsOcupados++;

            // Contamos cuántos elementos hay en la lista enlazada de este bucket
            int elementosEnBucket = 0;
            NodoHash* actual = tabla[i];

            while (actual != nullptr) {
                elementosEnBucket++;
                actual = actual->siguiente;
            }

            totalReservas += elementosEnBucket;
            // Las colisiones son los elementos extra después del primero
            totalColisiones += (elementosEnBucket - 1);
        }
    }

    // --- 2. CONFIGURACIÓN GRAPHVIZ ---
    archivo << "digraph TablaHash {\n";
    archivo << "  rankdir=LR;\n"; // De izquierda a derecha para que las listas crezcan hacia la derecha
    archivo << "  node [shape=record, fontname=\"Helvetica\"];\n";

    // --- 3. DIBUJAR NODO DE ESTADÍSTICAS ---
    archivo << "  stats [shape=note, style=filled, fillcolor=\"#fff9c4\", label=\"ESTADÍSTICAS GLOBALES\\n"
            << "Tamaño de Tabla: " << capacidad << "\\n"
            << "Total Reservas: " << totalReservas << "\\n"
            << "Buckets Ocupados: " << bucketsOcupados << "\\n"
            << "Colisiones: " << totalColisiones << "\"];\n\n";

    // --- 4. DIBUJAR BUCKETS Y LISTAS ENLAZADAS ---
    for (int i = 0; i < capacidad; i++) {
        std::string idBucket = "bucket" + std::to_string(i);

        if (tabla[i] == nullptr) {
            // Bucket Vacío (Gris claro)
            archivo << "  " << idBucket << " [label=\"" << i << " | Vacío\", style=filled, fillcolor=\"#eeeeee\"];\n";
        } else {
            // Bucket Ocupado (Azul claro)
            archivo << "  " << idBucket << " [label=\"" << i << " | Ocupado\", style=filled, fillcolor=\"#bbdefb\"];\n";

            // Recorrer la lista enlazada (Colisiones)
            NodoHash* actual = tabla[i];
            int idxLista = 0;
            std::string nodoAnterior = idBucket;

            while (actual != nullptr) {
                // Identificador único para el nodo
                std::string idNodoData = "data_" + std::to_string(i) + "_" + std::to_string(idxLista);

                // Extraemos los datos (Ajusta esto si tus variables se llaman distinto dentro de NodoHash/Reserva)
                std::string codReserva = actual->reserva->codigo_reserva;
                std::string idCliente = actual->reserva->id_cliente;
                std::string codFuncion = actual->reserva->codigo_funcion;

                // Nodo verde para representar la reserva
                archivo << "  " << idNodoData << " [label=\"{Clave: " << codReserva
                        << " | Cliente: " << idCliente
                        << " | Función: " << codFuncion
                        << "}\", style=filled, fillcolor=\"#c8e6c9\"];\n";

                // Conectar el nodo anterior (o el bucket base) con este nodo
                archivo << "  " << nodoAnterior << " -> " << idNodoData << ";\n";

                nodoAnterior = idNodoData;
                actual = actual->siguiente;
                idxLista++;
            }
        }
    }

    // --- 5. ALINEACIÓN VERTICAL DE LOS BUCKETS ---
    // Esto obliga a Graphviz a dibujar todos los buckets (del 0 al 96) en una línea recta perfecta hacia abajo
    archivo << "\n  { rank=same; ";
    for (int i = 0; i < capacidad; i++) {
        archivo << "bucket" << i << "; ";
    }
    archivo << "}\n";

    archivo << "}\n";
    archivo.close();

    // Generar la imagen PNG
    QProcess comando;
    comando.start("dot", QStringList() << "-Tpng" << "reporte_hash.dot" << "-o" << "reporte_hash.png");
    comando.waitForFinished();
}

bool TablaHash::eliminar(std::string codigo_reserva) {
    // Asumiendo que tu método de hash se llama funcionHash o calcularHash
    int indice = funcionHash(codigo_reserva);
    NodoHash* actual = tabla[indice];
    NodoHash* anterior = nullptr;

    while (actual != nullptr) {
        if (actual->reserva->codigo_reserva == codigo_reserva) {
            // Desenlazar el nodo
            if (anterior == nullptr) {
                tabla[indice] = actual->siguiente; // Era el primero del bucket
            } else {
                anterior->siguiente = actual->siguiente; // Estaba en medio de una colisión
            }

            delete actual->reserva; // Liberamos la memoria del objeto
            delete actual;          // Liberamos el nodo
            cantidad_elementos--;
            return true;
        }
        anterior = actual;
        actual = actual->siguiente;
    }
    return false; // No se encontró
}