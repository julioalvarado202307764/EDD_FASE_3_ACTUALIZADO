#include "ArbolMerkle.h"
#include "SHA256.h"


ArbolMerkle::ArbolMerkle()
    : raiz(nullptr)
{
}


ArbolMerkle::~ArbolMerkle()
{
    limpiar();
}


void ArbolMerkle::liberarSubarbol(
    NodoMerkle* nodo)
{
    if (nodo == nullptr) {
        return;
    }


    liberarSubarbol(
        nodo->izquierdo
        );

    liberarSubarbol(
        nodo->derecho
        );


    delete nodo;
}


void ArbolMerkle::limpiar()
{
    liberarSubarbol(
        raiz
        );

    raiz = nullptr;
}


void ArbolMerkle::construir(
    const std::vector<Transaccion>&
        transacciones)
{
    /*
     * Reconstruir la misma instancia siempre elimina
     * primero el árbol anterior.
     */
    limpiar();


    // =========================================================
    // 0 TRANSACCIONES
    // =========================================================

    if (transacciones.empty()) {
        return;
    }


    // =========================================================
    // CREAR HOJAS EN EL ORDEN RECIBIDO
    // =========================================================

    std::vector<NodoMerkle*>
        nivelActual;


    nivelActual.reserve(
        transacciones.size()
        );


    for (const Transaccion& transaccion :
         transacciones) {

        nivelActual.push_back(
            new NodoMerkle(
                transaccion
                    .calcularHash()
                )
            );
    }


    // =========================================================
    // 1 TRANSACCIÓN
    //
    // ROOTMERKLE = hash(tx)
    //
    // NO SHA256(H1 + H1)
    // =========================================================

    if (nivelActual.size() == 1u) {

        raiz =
            nivelActual[0];

        return;
    }


    // =========================================================
    // CONSTRUIR NIVELES INTERNOS
    // =========================================================

    while (nivelActual.size() > 1u) {

        std::vector<NodoMerkle*>
            siguienteNivel;


        siguienteNivel.reserve(
            (nivelActual.size() + 1u) /
            2u
            );


        for (std::size_t i = 0;
             i < nivelActual.size();
             i += 2u) {

            NodoMerkle* izquierdo =
                nivelActual[i];


            NodoMerkle* derecho =
                nullptr;


            if (i + 1u <
                nivelActual.size()) {

                derecho =
                    nivelActual[
                        i + 1u
                ];

            } else {

                /*
                 * POLÍTICA DE CANTIDAD IMPAR:
                 *
                 * Se duplica el último HASH del nivel.
                 *
                 * Se crea un nodo independiente para que cada
                 * puntero tenga ownership único y el destructor
                 * pueda liberar el árbol sin double free.
                 */
                derecho =
                    new NodoMerkle(
                        izquierdo->hash
                        );
            }


            /*
             * Regla de nodo interno estable para E6/E9:
             *
             * SHA256(
             *     hashIzquierdoHex +
             *     hashDerechoHex
             * )
             */
            const std::string
                hashPadre =
                SHA256::hash(
                    izquierdo->hash +
                    derecho->hash
                    );


            NodoMerkle* padre =
                new NodoMerkle(
                    hashPadre
                    );


            padre->izquierdo =
                izquierdo;

            padre->derecho =
                derecho;


            siguienteNivel.push_back(
                padre
                );
        }


        nivelActual.swap(
            siguienteNivel
            );
    }


    raiz =
        nivelActual[0];
}


const NodoMerkle*
ArbolMerkle::obtenerRaiz() const
{
    return raiz;
}


std::string
ArbolMerkle::obtenerRootMerkle() const
{
    if (raiz == nullptr) {
        return "";
    }


    return raiz->hash;
}


bool ArbolMerkle::estaVacio() const
{
    return raiz == nullptr;
}