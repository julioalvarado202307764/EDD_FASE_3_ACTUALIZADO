#ifndef ARBOLAVL_H
#define ARBOLAVL_H

#include "NodoAVL.h"
#include <string>
#include <fstream>
#include <QComboBox>
#include <QString>
#include <QTableWidget>
#include <QTime>
#include <QDate>

class ArbolPeliculas;
typedef void (*VisitanteFuncionAVL)(const NodoAVL*, void*);

class ArbolAVL {
private:
    NodoAVL* raiz;

    // Métodos de balanceo interno
    int obtenerAltura(NodoAVL* nodo);
    int obtenerFactorBalance(NodoAVL* nodo);
    NodoAVL* rotacionDerecha(NodoAVL* y);
    NodoAVL* rotacionIzquierda(NodoAVL* x);

    // Inserción interna. La bandera permite separar la inserción en memoria de la
    // inicialización física del archivo de asientos.
    NodoAVL* insertarNodo(NodoAVL* nodo,
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
                          bool inicializarArchivo);

    void inicializarArchivoAsientos(NodoAVL* nodo);

    NodoAVL* eliminarNodo(NodoAVL* nodo, std::string codigo);
    void generarDOTRecursivo(NodoAVL* nodo, std::ofstream& archivo, ArbolPeliculas* arbolPelis, QDate fechaActual);
    void inordenCombo(NodoAVL* nodo, QString pelicula, QComboBox* combo);

    NodoAVL* buscarRecursivoAVL(NodoAVL* nodo, QString codigo);
    void poblarTablaRecursivo(NodoAVL* nodo, QTableWidget* tabla, int& filaActual);
    void inordenTabla(NodoAVL* nodo, QTableWidget* tabla);
    void preordenTabla(NodoAVL* nodo, QTableWidget* tabla);
    void postordenTabla(NodoAVL* nodo, QTableWidget* tabla);
    void recorrerFuncionesRecursivo(NodoAVL* nodo,
                                    VisitanteFuncionAVL visita,
                                    void* contexto) const;

public:
    ArbolAVL();

    // API histórica de Fase 2. Se conserva sin cambios y continúa creando el
    // archivo de asientos de una función nueva.
    void insertar(std::string codigo,
                  std::string pelicula,
                  std::string hor,
                  std::string sal,
                  int f,
                  int c);

    // Inserción extendida para una función NUEVA de Fase 3. También inicializa
    // su archivo de asientos.
    void insertar(std::string codigo,
                  std::string pelicula,
                  std::string codigoPeliculaReal,
                  std::string fecha,
                  std::string codigoSede,
                  std::string hor,
                  std::string sal,
                  int f,
                  int c);

    // Vía preparada para reconstrucción/persistencia: inserta el nodo en memoria
    // sin crear ni sobrescribir el archivo de asientos existente.
    void insertarExistente(std::string codigo,
                           std::string pelicula,
                           std::string codigoPeliculaReal,
                           std::string fecha,
                           std::string codigoSede,
                           std::string hor,
                           std::string sal,
                           int f,
                           int c,
                           std::string archivoAsientos = "");
    // Recorrido de solo lectura utilizado por estructuras derivadas como el grafo.
    // No expone la raíz ni modifica el AVL.
    void recorrerFunciones(VisitanteFuncionAVL visita,
                           void* contexto) const;
    void eliminar(std::string codigo);

    // Búsqueda original
    NodoAVL* buscar(std::string codigo);

    // Método público de búsqueda usando QString
    NodoAVL* buscarFuncion(QString codigo);

    void poblarComboFunciones(QString pelicula, QComboBox* combo);

    // Generación de archivo DOT para el reporte visual
    void generarReporteGraphviz(ArbolPeliculas* arbolPelis);
    void poblarTablaUI(QTableWidget* tabla);
    void testConsola(NodoAVL* nodo);
    void poblarTablaFuncionesUI(QTableWidget* tabla, QString tipoRecorrido = "Inorden");
};

#endif
