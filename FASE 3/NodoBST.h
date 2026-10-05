#ifndef NODOBST_H
#define NODOBST_H

#include "Pelicula.h"

class NodoBST {
public:
    Pelicula pelicula;
    NodoBST* izquierdo;
    NodoBST* derecho;

    NodoBST(Pelicula p) {
        pelicula = p;
        izquierdo = nullptr;
        derecho = nullptr;
    }
};

#endif // NODOBST_H