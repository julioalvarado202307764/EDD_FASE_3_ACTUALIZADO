#ifndef NODOB_H
#define NODOB_H
#include <string>
#include <vector>

// Estructura para almacenar la información del cliente
struct Cliente {
    std::string id;
    std::string nombre;
    std::string correo;
    std::string telefono;
    std::string password;
    std::string tipo; // Puede ser "cliente" o "admin"

    // Solo almacena el código de reserva, no el objeto completo[cite: 1]
    std::vector<std::string> codigos_reservas;

    Cliente() {}
    Cliente(std::string _id, std::string _nombre, std::string _correo, std::string _telefono, std::string _password, std::string _tipo)
        : id(_id), nombre(_nombre), correo(_correo), telefono(_telefono), password(_password), tipo(_tipo) {}
};

class NodoB {
public:
    int conteo_claves;           // Cantidad actual de clientes en este nodo
    Cliente* clientes[3];        // Arreglo de tamaño Orden - 1 (Máximo 3 clientes por nodo)[cite: 1]
    NodoB* hijos[4];             // Arreglo de tamaño Orden (Máximo 4 hijos por nodo)[cite: 1]
    bool es_hoja;

    NodoB(bool hoja);

    // Métodos utilitarios del nodo
    void insertarNoLleno(Cliente cliente);
    void dividirHijo(int i, NodoB* y);
    int buscarClave(std::string id);
    Cliente* buscar(std::string id);
    void eliminar(std::string id);
private:
    void eliminarDeHoja(int idx);
    void eliminarDeNoHoja(int idx);
    Cliente* obtenerPredecesor(int idx);
    Cliente* obtenerSucesor(int idx);
    void llenar(int idx);
    void pedirPrestadoAnterior(int idx);
    void pedirPrestadoSiguiente(int idx);
    void fusionar(int idx);
};

#endif