#ifndef PROMOCION_H
#define PROMOCION_H

#include <QString>
#include "Beneficio.h"

class Promocion {
public:
    QString codigo; // Promo_01, Promo_02
    QString nombre;
    QString vigencia; // fecha inicio - fecha fin
    QString diasAplicables;

    // Punteros para la sub-lista interna doblemente enlazada
    NodoBeneficio* primeroBeneficio;
    NodoBeneficio* ultimoBeneficio;

    Promocion() {}
    Promocion(QString c, QString n, QString v, QString d) {
        codigo = c;
        nombre = n;
        vigencia = v;
        diasAplicables = d;
        primeroBeneficio = nullptr;
        ultimoBeneficio = nullptr;
    }

    // Método interno para agregar beneficios a ESTA promoción
    void agregarBeneficio(Beneficio b) {
        NodoBeneficio* nuevo = new NodoBeneficio(b);
        if (primeroBeneficio == nullptr) {
            primeroBeneficio = nuevo;
            ultimoBeneficio = nuevo;
        } else {
            ultimoBeneficio->siguiente = nuevo;
            nuevo->anterior = ultimoBeneficio;
            ultimoBeneficio = nuevo;
        }
    }
};

// El Nodo de la lista circular simple
class NodoPromocion {
public:
    Promocion promocion;
    NodoPromocion* siguiente; // Solo hacia adelante[cite: 1]

    NodoPromocion(Promocion p) {
        promocion = p;
        siguiente = nullptr;
    }
};

#endif // PROMOCION_H