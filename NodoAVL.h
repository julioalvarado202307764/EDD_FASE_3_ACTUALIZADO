#ifndef NODOAVL_H
#define NODOAVL_H
#include <string>

class NodoAVL {
public:
    std::string codigo_funcion; // Clave principal del árbol AVL

    // Compatibilidad Fase 2: este campo conserva el valor histórico usado por la UI,
    // que actualmente corresponde al título de la película.
    std::string codigo_pelicula;

    // Fase 3: identificación inequívoca y nuevos datos propios de una función.
    std::string codigo_pelicula_real;
    std::string fecha;
    std::string codigo_sede;

    std::string horario;
    std::string sala;
    std::string archivo_asientos;
    int filas;
    int columnas;

    int altura;

    NodoAVL* izquierdo;
    NodoAVL* derecho;

    // Constructor compatible con Fase 2.
    NodoAVL(std::string codigo, std::string pelicula, std::string hor, std::string sal, int f, int c);

    // Constructor extendido para Fase 3. archivoAsientos puede dejarse vacío para
    // conservar la convención Fxxx_funcion.json existente.
    NodoAVL(std::string codigo,
            std::string pelicula,
            std::string codigoPeliculaReal,
            std::string fechaFuncion,
            std::string codigoSede,
            std::string hor,
            std::string sal,
            int f,
            int c,
            std::string archivoAsientos = "");
};

#endif
