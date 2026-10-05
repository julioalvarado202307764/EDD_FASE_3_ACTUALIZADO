#ifndef BENEFICIO_H
#define BENEFICIO_H

#include <QString>

// Los datos requeridos para el beneficio
class Beneficio {
public:
    QString tipo; // descuento, combo, 2x1
    QString descripcion;
    QString valor; // 5%, 10%, NA

    Beneficio() {}
    Beneficio(QString t, QString d, QString v) {
        tipo = t;
        descripcion = d;
        valor = v;
    }
};

// El Nodo Doble
class NodoBeneficio {
public:
    Beneficio beneficio;
    NodoBeneficio* siguiente;
    NodoBeneficio* anterior;

    NodoBeneficio(Beneficio b) {
        beneficio = b;
        siguiente = nullptr;
        anterior = nullptr;
    }
};

#endif // BENEFICIO_H