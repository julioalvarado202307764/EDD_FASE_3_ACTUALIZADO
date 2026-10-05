#include "NodoAVL.h"

NodoAVL::NodoAVL(std::string codigo,
                 std::string pelicula,
                 std::string hor,
                 std::string sal,
                 int f,
                 int c)
    : NodoAVL(codigo, pelicula, "", "", "", hor, sal, f, c, "") {
}

NodoAVL::NodoAVL(std::string codigo,
                 std::string pelicula,
                 std::string codigoPeliculaReal,
                 std::string fechaFuncion,
                 std::string codigoSede,
                 std::string hor,
                 std::string sal,
                 int f,
                 int c,
                 std::string archivoAsientos) {
    codigo_funcion = codigo;
    codigo_pelicula = pelicula;
    codigo_pelicula_real = codigoPeliculaReal;
    fecha = fechaFuncion;
    codigo_sede = codigoSede;
    horario = hor;
    sala = sal;
    archivo_asientos = archivoAsientos.empty()
                            ? codigo + "_funcion.json"
                            : archivoAsientos;

    filas = f;
    columnas = c;

    altura = 1;
    izquierdo = nullptr;
    derecho = nullptr;
}
