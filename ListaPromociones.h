#ifndef LISTAPROMOCIONES_H
#define LISTAPROMOCIONES_H

#include "Promocion.h"
#include <QTreeWidget>

class ListaPromociones {
private:
    NodoPromocion* primero;
    NodoPromocion* ultimo;

public:
    ListaPromociones();
    void agregarPromocion(QString codigo, QString nombre, QString vigencia, QString dias);
    void agregarBeneficioAPromo(QString codigoPromo, QString tipo, QString desc, QString valor);
    void generarReporteDOT();
    void poblarArbolUI(QTreeWidget* arbol);
};

#endif // LISTAPROMOCIONES_H