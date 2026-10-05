#ifndef LISTASOLICITUDES_H
#define LISTASOLICITUDES_H

#include "NodoSolicitud.h"
#include <QTextStream>
#include <QTableWidget>

class ListaSolicitudes {
private:
    NodoSolicitud* primero;
    NodoSolicitud* ultimo;
    int contadorId; // Variable para autogenerar el número[cite: 1]

public:
    ListaSolicitudes();

    // Método para insertar al final de la lista
    void registrarSolicitud(QString cliente, QString telefono, QString tipo, QString descripcion, QString fecha);

    // Método para generar el reporte de Graphviz
    void generarReporteDOT();

    NodoSolicitud* getPrimeraPendiente();
    void marcarComoAtendida(int id);
    void eliminarSolicitud(int id);
    void poblarTablaAdmin(QTableWidget* tabla);
    void marcarComoEnProceso(int id);
    QString buscarEstadoPorTelefono(QString telefono);
};

#endif // LISTASOLICITUDES_H