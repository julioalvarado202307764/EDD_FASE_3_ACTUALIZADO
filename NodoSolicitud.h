#ifndef NODOSOLICITUD_H
#define NODOSOLICITUD_H

#include "Solicitud.h"

class NodoSolicitud {
public:
    Solicitud solicitud;
    NodoSolicitud* siguiente;
    NodoSolicitud* anterior;

    NodoSolicitud(Solicitud s) {
        solicitud = s;
        siguiente = nullptr;
        anterior = nullptr;
    }
};

#endif // NODOSOLICITUD_H