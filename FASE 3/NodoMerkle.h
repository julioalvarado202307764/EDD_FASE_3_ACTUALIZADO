#ifndef NODOMERKLE_H
#define NODOMERKLE_H

#include <string>

class NodoMerkle {
public:
    std::string hash;

    NodoMerkle* izquierdo;
    NodoMerkle* derecho;


    explicit NodoMerkle(
        const std::string& valorHash)
        : hash(valorHash),
        izquierdo(nullptr),
        derecho(nullptr)
    {
    }
};

#endif // NODOMERKLE_H