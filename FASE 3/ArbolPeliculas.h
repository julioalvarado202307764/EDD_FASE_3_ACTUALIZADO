#ifndef ARBOLPELICULAS_H
#define ARBOLPELICULAS_H
#include <QTextStream>
#include "NodoBST.h"
#include <QTableWidget>
#include <QDate>
#include <QComboBox> // Añade esto arriba

class ArbolPeliculas {
private:
    NodoBST* raiz;

    // Métodos recursivos privados (insertar, recorrer, buscar)
    NodoBST* insertarRecursivo(NodoBST* nodo, Pelicula p);
    void inOrdenRecursivo(NodoBST* nodo); // Para recorrer por código de película
    void generarDOTRecursivo(NodoBST* nodo, QTextStream& stream, QDate hoy);
    void poblarTablaRecursivo(NodoBST* nodo, QTableWidget* tabla, int& filaActual);
    NodoBST* buscarRecursivo(NodoBST* nodo, QString codigo);
    void recolectarAlertas(NodoBST* nodo, QDate hoy, QString& alertas);
    NodoBST* eliminarRecursivo(NodoBST* nodo, QString codigo, bool& eliminada);
    NodoBST* encontrarMinimo(NodoBST* nodo);
    void poblarComboRecursivo(NodoBST* nodo, QComboBox* combo);
    // Métodos recursivos privados
    void poblarTablaRecursivoIn(NodoBST* nodo, QTableWidget* tabla, int& filaActual);
    void poblarTablaRecursivoPre(NodoBST* nodo, QTableWidget* tabla, int& filaActual);
    void poblarTablaRecursivoPost(NodoBST* nodo, QTableWidget* tabla, int& filaActual);

    // Método auxiliar para no repetir código visual
    void insertarFilaTabla(NodoBST* nodo, QTableWidget* tabla, int& filaActual);
    Pelicula* buscarPorTituloRecursivo(NodoBST* nodo, QString titulo); // NUEVO MÉTODO
    void poblarComboCodigoTituloRecursivo(
        NodoBST* nodo,
        QComboBox* combo
        );
public:
    ArbolPeliculas();

    // Métodos públicos
    void insertar(Pelicula p);
    void mostrarInOrden();

    // Aquí luego agregaremos el método para exportar a Graphviz
    void generarReporteDOT();
    void poblarTablaInOrden(QTableWidget* tabla); // El que ya tienes (por defecto)
    void poblarTablaPreOrden(QTableWidget* tabla);
    void poblarTablaPostOrden(QTableWidget* tabla);

    Pelicula* buscarPelicula(QString codigo);
    QString obtenerAlertasExpiracion();
    bool eliminarPelicula(QString codigo);
    void poblarComboUI(QComboBox* combo);
    void poblarComboCodigoTitulo(QComboBox* combo);
    Pelicula* buscarPeliculaPorTitulo(QString titulo); // NUEVO MÉTODO
};

#endif // ARBOLPELICULAS_H