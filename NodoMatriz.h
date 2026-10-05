#ifndef NODOMATRIZ_H
#define NODOMATRIZ_H

#include <QString>

class NodoMatriz {
public:
    int fila;      // Eje Y
    int columna;   // Eje X
    QString codigo_reserva; // Único dato almacenado del asiento ocupado

    // Los 4 punteros de la matriz dispersa
    NodoMatriz* arriba;
    NodoMatriz* abajo;
    NodoMatriz* izquierda;
    NodoMatriz* derecha;

    // Constructor actualizado
    NodoMatriz(int f, int c, QString cod_res = "") {
        fila = f;
        columna = c;
        codigo_reserva = cod_res;
        arriba = nullptr;
        abajo = nullptr;
        izquierda = nullptr;
        derecha = nullptr;
    }
};

#endif // NODOMATRIZ_H