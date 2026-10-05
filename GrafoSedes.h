#ifndef GRAFOSEDES_H
#define GRAFOSEDES_H

#include "Sede.h"
#include <string>
#include <vector>

class ArbolAVL;
class NodoAVL;
class NodoGrafo;

class NodoAdyacencia {
public:
    NodoGrafo* destino;
    int peso;
    NodoAdyacencia* siguiente;

    NodoAdyacencia(NodoGrafo* destino, int peso);
};

class NodoGrafo {
public:
    Sede sede;
    NodoAdyacencia* adyacencias;
    NodoGrafo* siguiente;

    explicit NodoGrafo(const Sede& sede);
};

struct RelacionGrafo {
    std::string sedeA;
    std::string sedeB;
    int peso;
};

struct SedeSimilar {
    Sede sede;
    int peso;
};

struct ResultadoBFS {
    bool origenEncontrado;
    bool destinoEncontrado;
    bool existeCamino;
    std::vector<std::string> ruta;

    ResultadoBFS();
};

class GrafoSedes {
private:
    NodoGrafo* primero;
    int totalSedes;

    // Lista temporal utilizada únicamente durante el recálculo.
    // Cada combinación sede/película aparece una sola vez.
    struct RegistroPeliculaSede {
        std::string codigoSede;
        std::string codigoPelicula;
        RegistroPeliculaSede* siguiente;

        RegistroPeliculaSede(const std::string& sede,
                             const std::string& pelicula);
    };

    struct ContextoRecoleccion {
        GrafoSedes* grafo;
        RegistroPeliculaSede* cabeza;
    };

    // Registros manuales utilizados por BFS.
    struct RegistroBFS {
        NodoGrafo* vertice;
        RegistroBFS* padre;
        RegistroBFS* siguiente;

        RegistroBFS(NodoGrafo* vertice, RegistroBFS* padre);
    };

    struct NodoColaBFS {
        RegistroBFS* registro;
        NodoColaBFS* siguiente;

        explicit NodoColaBFS(RegistroBFS* registro);
    };

    // Cola enlazada manual para BFS.
    class ColaBFS {
    private:
        NodoColaBFS* frente;
        NodoColaBFS* final;

    public:
        ColaBFS();
        ~ColaBFS();

        void encolar(RegistroBFS* registro);
        RegistroBFS* desencolar();
        bool vacia() const;
    };

    NodoGrafo* buscarSedeInterna(const std::string& codigo) const;

    NodoAdyacencia* buscarAdyacencia(
        NodoGrafo* origen,
        const std::string& codigoDestino) const;

    void insertarOActualizarAdyacencia(
        NodoGrafo* origen,
        NodoGrafo* destino,
        int peso);

    bool eliminarAdyacencia(
        NodoGrafo* origen,
        const std::string& codigoDestino);

    void liberarListaAdyacencia(NodoGrafo* vertice);

    void limpiarRelaciones();

    static void recolectarFuncionAVL(
        const NodoAVL* funcion,
        void* contexto);

    void agregarPeliculaTemporal(
        RegistroPeliculaSede*& cabeza,
        const std::string& codigoSede,
        const std::string& codigoPelicula) const;

    int contarPeliculasCompartidas(
        RegistroPeliculaSede* cabeza,
        const std::string& sedeA,
        const std::string& sedeB) const;

    void liberarPeliculasTemporales(
        RegistroPeliculaSede*& cabeza) const;

    RegistroBFS* buscarRegistroBFS(
        RegistroBFS* cabeza,
        NodoGrafo* vertice) const;

    void liberarRegistrosBFS(
        RegistroBFS*& cabeza) const;

public:
    GrafoSedes();
    ~GrafoSedes();

    GrafoSedes(const GrafoSedes&) = delete;
    GrafoSedes& operator=(const GrafoSedes&) = delete;

    bool insertarSede(const Sede& sede);

    const NodoGrafo* buscarSede(
        const std::string& codigo) const;

    int cantidadSedes() const;

    // Permite recorrer todos los vértices posteriormente sin exponer
    // capacidad de modificación.
    const NodoGrafo* obtenerPrimeraSede() const;

    bool crearOActualizarRelacion(
        const std::string& codigoA,
        const std::string& codigoB,
        int peso);

    bool eliminarRelacion(
        const std::string& codigoA,
        const std::string& codigoB);

    int obtenerPeso(
        const std::string& codigoA,
        const std::string& codigoB) const;

    const NodoAdyacencia* obtenerAdyacencias(
        const std::string& codigoSede) const;

    // Reconstruye todas las relaciones utilizando el estado actual del AVL.
    void recalcularRelaciones(
        const ArbolAVL& arbolFunciones);

    ResultadoBFS buscarCaminoBFS(
        const std::string& origen,
        const std::string& destino) const;

    std::vector<RelacionGrafo> obtenerRankingRelaciones() const;

    std::vector<SedeSimilar> obtenerSedesSimilares(
        const std::string& codigoSede) const;
};

#endif // GRAFOSEDES_H