#ifndef ARBOLMERKLE_H
#define ARBOLMERKLE_H

#include "NodoMerkle.h"
#include "Transaccion.h"

#include <string>
#include <vector>


class ArbolMerkle {
private:
    NodoMerkle* raiz;


    void liberarSubarbol(
        NodoMerkle* nodo
        );


public:
    ArbolMerkle();

    ~ArbolMerkle();


    /*
     * Evitamos copias superficiales de un árbol propietario
     * de punteros para impedir double free.
     */
    ArbolMerkle(
        const ArbolMerkle&
        ) = delete;

    ArbolMerkle& operator=(
        const ArbolMerkle&
        ) = delete;


    void limpiar();


    /*
     * Construye respetando EXACTAMENTE el orden recibido.
     *
     * Política impar:
     * si un nivel con más de un nodo tiene cantidad impar,
     * se duplica el último HASH y se calcula:
     *
     * SHA256(ultimoHash + ultimoHash)
     *
     * Una única hoja NO se duplica:
     * ROOTMERKLE = hash(transaccion).
     */
    void construir(
        const std::vector<Transaccion>&
            transacciones
        );


    const NodoMerkle*
    obtenerRaiz() const;


    /*
     * Árbol vacío:
     * devuelve "".
     */
    std::string
    obtenerRootMerkle() const;


    bool estaVacio() const;
};

#endif // ARBOLMERKLE_H