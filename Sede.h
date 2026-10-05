#ifndef SEDE_H
#define SEDE_H

#include <string>

class Sede {
public:
    std::string codigo;
    std::string nombre;
    std::string direccion;
    int cantidad_salas;
    std::string telefono;

    Sede()
        : cantidad_salas(0) {}

    Sede(const std::string& cod,
         const std::string& nom,
         const std::string& dir,
         int cantidadSalas,
         const std::string& tel)
        : codigo(cod),
          nombre(nom),
          direccion(dir),
          cantidad_salas(cantidadSalas),
          telefono(tel) {}
};

#endif // SEDE_H
