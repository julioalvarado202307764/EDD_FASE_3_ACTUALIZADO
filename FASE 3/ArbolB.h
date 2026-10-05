#ifndef ARBOLB_H
#define ARBOLB_H
#include "NodoB.h"
#include <string>
#include <fstream> // Necesario para manejar la escritura del archivo .dot
#include <QTableWidget>

class ArbolB {
private:
    NodoB* raiz;
    int orden;

    // Método privado recursivo para recorrer el árbol y escribir el Graphviz
    void generarDOTBTree(NodoB* nodo, std::ofstream& archivo);
    void inordenTabla(NodoB* nodo, QTableWidget* tabla);
    Cliente* buscarPorCorreoRecursivo(NodoB* nodo, std::string correo);
    void preordenTabla(NodoB* nodo, QTableWidget* tabla);
    void postordenTabla(NodoB* nodo, QTableWidget* tabla);

public:
    ArbolB();

    // Búsqueda para el Login y gestión[cite: 1]
    Cliente* buscar(std::string id);

    // Operaciones principales
    void insertar(Cliente cliente);

    // Reporte para Graphviz
    void generarReporteGraphviz();

    void poblarTablaUI(QTableWidget* tabla, QString tipoRecorrido = "Inorden");
    Cliente* buscarPorCorreo(std::string correo);
    void eliminar(std::string id);
};

#endif