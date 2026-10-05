#ifndef TABLAHASH_H
#define TABLAHASH_H
#include "NodoHash.h"
#include <string>
#include <vector>

class TablaHash {
private:
    int capacidad;
    int cantidad_elementos;
    std::vector<NodoHash*> tabla; // Vector de buckets

    // Función Hash matemática
    int funcionHash(std::string clave);

public:
    TablaHash(int cap = 97); // Número primo para reducir colisiones iniciales

    void insertar(Reserva* reserva);
    Reserva* buscar(std::string codigo_reserva);
    bool eliminar(std::string codigo_reserva);

    // Generación de reporte estadístico y visual[cite: 1]
    void generarReporteGraphviz();

};

#endif