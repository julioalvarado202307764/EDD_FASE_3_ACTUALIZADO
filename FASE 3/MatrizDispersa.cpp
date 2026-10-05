#include "MatrizDispersa.h"
#include <QDebug>
#include <QFile>
#include <QTextStream>
#include <QProcess>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <fstream>

MatrizDispersa::MatrizDispersa() {
    raiz = new NodoMatriz(0, 0, "RAIZ");
    maxFilas = 0;
    maxColumnas = 0;
}

void MatrizDispersa::vaciarMatriz() {
    if (raiz == nullptr) return;

    // 1. Liberar todos los nodos de asientos
    NodoMatriz* tempFila = raiz->abajo;
    while (tempFila != nullptr) {
        NodoMatriz* actual = tempFila->derecha;
        while (actual != nullptr) {
            NodoMatriz* aBorrar = actual;
            actual = actual->derecha;
            delete aBorrar;
        }
        tempFila = tempFila->abajo;
    }

    // 2. Liberar cabeceras de filas
    NodoMatriz* cabFila = raiz->abajo;
    while (cabFila != nullptr) {
        NodoMatriz* aBorrar = cabFila;
        cabFila = cabFila->abajo;
        delete aBorrar;
    }

    // 3. Liberar cabeceras de columnas
    NodoMatriz* cabCol = raiz->derecha;
    while (cabCol != nullptr) {
        NodoMatriz* aBorrar = cabCol;
        cabCol = cabCol->derecha;
        delete aBorrar;
    }

    // 4. Reiniciar enlaces de la raíz para la nueva función
    raiz->abajo = nullptr;
    raiz->derecha = nullptr;
}

void MatrizDispersa::cargarDesdeArchivo(QString nombre_archivo, int filas, int columnas) {
    vaciarMatriz(); // Limpiamos la memoria antes de cargar la nueva función
    maxFilas = filas;
    maxColumnas = columnas;

    QFile file(nombre_archivo);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Archivo JSON nuevo o no encontrado, la matriz inicia vacía.";
        return;
    }

    QByteArray data = file.readAll();
    file.close();

    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject obj = doc.object();
    QJsonArray asientos = obj["asientos_ocupados"].toArray();

    for (QJsonValue val : asientos) {
        QJsonObject asiento = val.toObject();
        int f = asiento["fila"].toInt();
        int c = asiento["columna"].toInt();
        QString cod = asiento["codigo_reserva"].toString();

        reservarAsiento(f, c, cod); // Insertamos solo los ocupados
    }
}

void MatrizDispersa::guardarEnArchivo(QString nombre_archivo, QString codigo_funcion) {
    QJsonObject root;
    root["codigo_funcion"] = codigo_funcion;
    QJsonArray asientosArray;

    // Recorremos la matriz para extraer las reservas activas[cite: 1]
    NodoMatriz* actualFila = raiz->abajo;
    while (actualFila != nullptr) {
        NodoMatriz* actualNodo = actualFila->derecha;
        while (actualNodo != nullptr) {
            QJsonObject asientoObj;
            asientoObj["fila"] = actualNodo->fila;
            asientoObj["columna"] = actualNodo->columna;
            asientoObj["codigo_reserva"] = actualNodo->codigo_reserva;

            asientosArray.append(asientoObj);
            actualNodo = actualNodo->derecha;
        }
        actualFila = actualFila->abajo;
    }

    root["asientos_ocupados"] = asientosArray;

    QJsonDocument doc(root);
    QFile file(nombre_archivo);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        file.write(doc.toJson());
        file.close();
    }
}

// Busca si la cabecera de la columna (eje X) ya existe
NodoMatriz* MatrizDispersa::buscarColumna(int columna) {
    NodoMatriz* actual = raiz;
    while (actual != nullptr) {
        if (actual->columna == columna) return actual;
        actual = actual->derecha;
    }
    return nullptr;
}

// Busca si la cabecera de la fila (eje Y) ya existe
NodoMatriz* MatrizDispersa::buscarFila(int fila) {
    NodoMatriz* actual = raiz;
    while (actual != nullptr) {
        if (actual->fila == fila) return actual;
        actual = actual->abajo;
    }
    return nullptr;
}

// Inserta una nueva cabecera de columna de forma ordenada
NodoMatriz* MatrizDispersa::crearColumna(int columna) {
    NodoMatriz* nuevaCabecera = new NodoMatriz(0, columna, "CAB_COL");
    NodoMatriz* actual = raiz;

    while (actual->derecha != nullptr && actual->derecha->columna < columna) {
        actual = actual->derecha;
    }

    nuevaCabecera->derecha = actual->derecha;
    if (actual->derecha != nullptr) actual->derecha->izquierda = nuevaCabecera;
    actual->derecha = nuevaCabecera;
    nuevaCabecera->izquierda = actual;

    return nuevaCabecera;
}

// Inserta una nueva cabecera de fila de forma ordenada
NodoMatriz* MatrizDispersa::crearFila(int fila) {
    NodoMatriz* nuevaCabecera = new NodoMatriz(fila, 0, "CAB_FILA");
    NodoMatriz* actual = raiz;

    while (actual->abajo != nullptr && actual->abajo->fila < fila) {
        actual = actual->abajo;
    }

    nuevaCabecera->abajo = actual->abajo;
    if (actual->abajo != nullptr) actual->abajo->arriba = nuevaCabecera;
    actual->abajo = nuevaCabecera;
    nuevaCabecera->arriba = actual;

    return nuevaCabecera;
}

bool MatrizDispersa::reservarAsiento(int fila, int columna, QString codigo_reserva) {
    if (fila > maxFilas || columna > maxColumnas || fila <= 0 || columna <= 0) {
        qDebug() << "Error: El asiento no existe en esta sala.";
        return false;
    }

    NodoMatriz* nodoColumna = buscarColumna(columna);
    if (nodoColumna == nullptr) nodoColumna = crearColumna(columna);

    NodoMatriz* nodoFila = buscarFila(fila);
    if (nodoFila == nullptr) nodoFila = crearFila(fila);

    // ENLAZADO VERTICAL
    NodoMatriz* actualCol = nodoColumna;
    while (actualCol->abajo != nullptr && actualCol->abajo->fila < fila) {
        actualCol = actualCol->abajo;
    }

    if (actualCol->abajo != nullptr && actualCol->abajo->fila == fila) {
        qDebug() << "¡Asiento ocupado por la reserva:" << actualCol->abajo->codigo_reserva << "!";
        return false;
    }

    NodoMatriz* nuevoAsiento = new NodoMatriz(fila, columna, codigo_reserva);

    nuevoAsiento->abajo = actualCol->abajo;
    if (actualCol->abajo != nullptr) actualCol->abajo->arriba = nuevoAsiento;
    actualCol->abajo = nuevoAsiento;
    nuevoAsiento->arriba = actualCol;

    // ENLAZADO HORIZONTAL
    NodoMatriz* actualFil = nodoFila;
    while (actualFil->derecha != nullptr && actualFil->derecha->columna < columna) {
        actualFil = actualFil->derecha;
    }

    nuevoAsiento->derecha = actualFil->derecha;
    if (actualFil->derecha != nullptr) actualFil->derecha->izquierda = nuevoAsiento;
    actualFil->derecha = nuevoAsiento;
    nuevoAsiento->izquierda = actualFil;

    return true;
}

int MatrizDispersa::cancelarReserva(int fila, int columna, QString codigo_reserva) {
    if (fila > maxFilas || columna > maxColumnas || fila <= 0 || columna <= 0) return 0;

    NodoMatriz* nodoFila = buscarFila(fila);
    if (nodoFila == nullptr) return 0;

    NodoMatriz* actual = nodoFila->derecha;
    while (actual != nullptr) {
        if (actual->columna == columna) {

            if (actual->codigo_reserva.toLower() != codigo_reserva.toLower()) {
                return -1; // Asiento ocupado, pero la reserva no coincide
            }

            // Desenlace Horizontal
            actual->izquierda->derecha = actual->derecha;
            if (actual->derecha != nullptr) actual->derecha->izquierda = actual->izquierda;

            // Desenlace Vertical
            actual->arriba->abajo = actual->abajo;
            if (actual->abajo != nullptr) actual->abajo->arriba = actual->arriba;

            delete actual;
            return 1;
        }
        actual = actual->derecha;
    }
    return 0;
}

// Método principal del reporte Graphviz
void MatrizDispersa::generarReporteDOT(QString pelicula, QString horario, QString sala) {
    std::ofstream archivo("reporte_matriz.dot");
    if (!archivo.is_open()) return;

    int asientosOcupados = 0;
    int asientosLibres = 0;
    int totalAsientos = maxFilas * maxColumnas;

    archivo << "digraph MatrizDispersa {\n";
    archivo << "  node [fontname=\"Helvetica\"];\n";

    // TÍTULO DEL GRAFO
    archivo << "  labelloc=\"t\";\n";
    archivo << "  label=\"Función: " << pelicula.toStdString() << " - " << horario.toStdString() << " - " << sala.toStdString() << "\";\n";
    archivo << "  fontsize=20;\n\n";

    // NODO RAÍZ (MTX - Esquina superior izquierda)
    archivo << "  MTX [label=\"Matriz\", shape=box, style=filled, fillcolor=\"#cfd8dc\", group=0];\n";

    // --- 1. CABECERAS DE COLUMNAS (Horizontales) ---
    for (int c = 1; c <= maxColumnas; c++) {
        archivo << "  C" << c << " [label=\"Col " << c << "\", shape=box, style=filled, fillcolor=\"#ffcc80\", group=" << c << "];\n";
    }
    // Enlaces de la cabecera de columnas
    archivo << "  MTX -> C1;\n";
    for (int c = 1; c < maxColumnas; c++) {
        archivo << "  C" << c << " -> C" << (c + 1) << ";\n";
    }
    // Forzar alineación de columnas (Rank Same)
    archivo << "  { rank=same; MTX; ";
    for (int c = 1; c <= maxColumnas; c++) archivo << "C" << c << "; ";
    archivo << "}\n\n";

    // --- 2. CABECERAS DE FILAS (Verticales) ---
    for (int f = 1; f <= maxFilas; f++) {
        archivo << "  F" << f << " [label=\"Fila " << f << "\", shape=box, style=filled, fillcolor=\"#ffcc80\", group=0];\n";
    }
    // Enlaces de la cabecera de filas
    archivo << "  MTX -> F1;\n";
    for (int f = 1; f < maxFilas; f++) {
        archivo << "  F" << f << " -> F" << (f + 1) << ";\n";
    }

    // --- 3. DIBUJAR LOS ASIENTOS (Ocupados y Libres) ---
    for (int f = 1; f <= maxFilas; f++) {
        for (int c = 1; c <= maxColumnas; c++) {
            QString codReserva = buscarAsiento(f, c);

            if (codReserva.isEmpty()) {
                // ASIENTO LIBRE (Transparente / Sin color de fondo)
                // Quitamos style=filled y fillcolor
                archivo << "  N_" << f << "_" << c << " [label=\"Libre\", shape=circle, group=" << c << "];\n";
                asientosLibres++;
            } else {
                // ASIENTO OCUPADO (Círculo Rojo con el código de reserva)
                archivo << "  N_" << f << "_" << c << " [label=\"Reservado\\n" << codReserva.toStdString() << "\", shape=circle, style=filled, fillcolor=\"#ffcdd2\", group=" << c << "];\n";
                asientosOcupados++;
            }
        }
    }

    // --- 4. CONECTAR Y ALINEAR FILAS (Enlaces Horizontales) ---
    for (int f = 1; f <= maxFilas; f++) {
        archivo << "  F" << f << " -> N_" << f << "_1;\n";
        for (int c = 1; c < maxColumnas; c++) {
            archivo << "  N_" << f << "_" << c << " -> N_" << f << "_" << (c + 1) << ";\n";
        }
        // Forzar alineación horizontal de esta fila en particular
        archivo << "  { rank=same; F" << f << "; ";
        for (int c = 1; c <= maxColumnas; c++) archivo << "N_" << f << "_" << c << "; ";
        archivo << "}\n";
    }

    // --- 5. CONECTAR COLUMNAS (Enlaces Verticales) ---
    for (int c = 1; c <= maxColumnas; c++) {
        archivo << "  C" << c << " -> N_1_" << c << ";\n";
        for (int f = 1; f < maxFilas; f++) {
            archivo << "  N_" << f << "_" << c << " -> N_" << (f + 1) << "_" << c << ";\n";
        }
    }

    // --- 6. NODO DE ESTADÍSTICAS ---
    archivo << "\n  stats [shape=note, style=filled, fillcolor=\"#fff9c4\", label=\"ESTADÍSTICAS\\n"
            << "Total Asientos: " << totalAsientos << "\\n"
            << "Ocupados: " << asientosOcupados << "\\n"
            << "Libres: " << asientosLibres << "\"];\n";

    archivo << "}\n";
    archivo.close();

    // Generar la imagen usando QProcess
    QProcess comando;
    comando.start("dot", QStringList() << "-Tpng" << "reporte_matriz.dot" << "-o" << "reporte_matriz.png");
    comando.waitForFinished();
}

// Añadir en MatrizDispersa.cpp
void MatrizDispersa::inicializarSala(int filas, int columnas) {
    vaciarMatriz(); // Garantiza que no haya basura en memoria
    maxFilas = filas;
    maxColumnas = columnas;
}

bool MatrizDispersa::estaOcupado(int fila, int columna) {
    NodoMatriz* nodoFila = buscarFila(fila);
    if (nodoFila == nullptr) return false; // Fila completa vacía

    NodoMatriz* actual = nodoFila->derecha;
    while (actual != nullptr) {
        if (actual->columna == columna) {
            return true; // Encontramos el nodo, está ocupado
        }
        actual = actual->derecha;
    }
    return false; // Columna libre en esta fila
}

// Método auxiliar para buscar la información de un asiento en específico
QString MatrizDispersa::buscarAsiento(int fila, int columna) {
    NodoMatriz* nodoFila = buscarFila(fila);
    if (nodoFila != nullptr) {
        NodoMatriz* actual = nodoFila->derecha;
        while (actual != nullptr) {
            if (actual->columna == columna) {
                return actual->codigo_reserva;
            }
            actual = actual->derecha;
        }
    }
    return ""; // Si retorna vacío, el asiento está libre
}