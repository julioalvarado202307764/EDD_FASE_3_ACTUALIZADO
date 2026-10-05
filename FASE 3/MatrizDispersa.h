#ifndef MATRIZDISPERSA_H
#define MATRIZDISPERSA_H

#include "NodoMatriz.h"
#include <QString>

class MatrizDispersa {
private:
    NodoMatriz* raiz;
    int maxFilas;
    int maxColumnas;

    // Métodos privados de ayuda para organizar las cabeceras
    NodoMatriz* buscarFila(int fila);
    NodoMatriz* buscarColumna(int columna);
    NodoMatriz* crearFila(int fila);
    NodoMatriz* crearColumna(int columna);
    QString buscarAsiento(int fila, int columna);

public:
    MatrizDispersa();

    // Método para crear la sala con sus dimensiones
    void inicializarSala(int filas, int columnas);

    // Nuevos métodos de persistencia dinámica para la Fase 2
    void vaciarMatriz();
    void cargarDesdeArchivo(QString nombre_archivo, int filas, int columnas);
    void guardarEnArchivo(QString nombre_archivo, QString codigo_funcion);

    // Métodos actualizados para recibir codigo_reserva en lugar de cliente
    bool reservarAsiento(int fila, int columna, QString codigo_reserva);
    int cancelarReserva(int fila, int columna, QString codigo_reserva);

    // Generar el reporte con Graphviz[cite: 1]
    void generarReporteDOT(QString pelicula, QString horario, QString sala);
    bool estaOcupado(int fila, int columna);};

#endif // MATRIZDISPERSA_H