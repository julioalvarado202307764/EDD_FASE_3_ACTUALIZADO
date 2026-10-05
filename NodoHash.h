#ifndef NODOHASH_H
#define NODOHASH_H
#include <string>

// Objeto de la reserva con las referencias mínimas necesarias
class Reserva {
public:
    std::string codigo_reserva;
    std::string codigo_funcion;
    std::string id_cliente;     // <--- ESTO FALTABA
    int fila;
    int columna;
    std::string fecha_reserva;

    // Constructor actualizado para recibir el id_cliente
    Reserva(std::string cod_res, std::string cod_fun, std::string id_cli, int f, int c, std::string fecha)
        : codigo_reserva(cod_res), codigo_funcion(cod_fun), id_cliente(id_cli), fila(f), columna(c), fecha_reserva(fecha) {}
};

// Nodo para la lista enlazada que manejará las colisiones
class NodoHash {
public:
    Reserva* reserva;
    NodoHash* siguiente;

    NodoHash(Reserva* res) : reserva(res), siguiente(nullptr) {}
};

#endif