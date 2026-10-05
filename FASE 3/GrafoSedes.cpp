#include "GrafoSedes.h"
#include "ArbolAVL.h"
#include "NodoAVL.h"

#include <algorithm>
#include <fstream>
#include <QProcess>
#include <QStringList>
namespace {

std::string escaparDOT(const std::string& texto)
{
    std::string resultado;

    for (char c : texto) {

        switch (c) {

        case '\\':
            resultado += "\\\\";
            break;

        case '"':
            resultado += "\\\"";
            break;

        case '\n':
            resultado += "\\n";
            break;

        case '\r':
            break;

        default:
            resultado += c;
            break;
        }
    }

    return resultado;
}

}
NodoAdyacencia::NodoAdyacencia(NodoGrafo* destino, int peso)
    : destino(destino),
    peso(peso),
    siguiente(nullptr) {
}

NodoGrafo::NodoGrafo(const Sede& sede)
    : sede(sede),
    adyacencias(nullptr),
    siguiente(nullptr) {
}

ResultadoBFS::ResultadoBFS()
    : origenEncontrado(false),
    destinoEncontrado(false),
    existeCamino(false) {
}

GrafoSedes::RegistroPeliculaSede::RegistroPeliculaSede(
    const std::string& sede,
    const std::string& pelicula)
    : codigoSede(sede),
    codigoPelicula(pelicula),
    siguiente(nullptr) {
}

GrafoSedes::RegistroBFS::RegistroBFS(
    NodoGrafo* vertice,
    RegistroBFS* padre)
    : vertice(vertice),
    padre(padre),
    siguiente(nullptr) {
}

GrafoSedes::NodoColaBFS::NodoColaBFS(RegistroBFS* registro)
    : registro(registro),
    siguiente(nullptr) {
}


// ============================================================
// COLA MANUAL PARA BFS
// ============================================================

GrafoSedes::ColaBFS::ColaBFS()
    : frente(nullptr),
    final(nullptr) {
}

GrafoSedes::ColaBFS::~ColaBFS() {
    while (!vacia()) {
        desencolar();
    }
}

void GrafoSedes::ColaBFS::encolar(RegistroBFS* registro) {
    NodoColaBFS* nuevo = new NodoColaBFS(registro);

    if (final == nullptr) {
        frente = nuevo;
        final = nuevo;
        return;
    }

    final->siguiente = nuevo;
    final = nuevo;
}

GrafoSedes::RegistroBFS*
GrafoSedes::ColaBFS::desencolar() {
    if (frente == nullptr) {
        return nullptr;
    }

    NodoColaBFS* temporal = frente;
    RegistroBFS* registro = temporal->registro;

    frente = frente->siguiente;

    if (frente == nullptr) {
        final = nullptr;
    }

    delete temporal;

    return registro;
}

bool GrafoSedes::ColaBFS::vacia() const {
    return frente == nullptr;
}


// ============================================================
// GRAFO
// ============================================================

GrafoSedes::GrafoSedes()
    : primero(nullptr),
    totalSedes(0) {
}

GrafoSedes::~GrafoSedes() {
    /*
     * Primera pasada:
     * se eliminan únicamente los nodos de adyacencia.
     *
     * Los NodoAdyacencia NO son propietarios de los vértices destino,
     * solamente los referencian.
     */
    NodoGrafo* actual = primero;

    while (actual != nullptr) {
        liberarListaAdyacencia(actual);
        actual = actual->siguiente;
    }

    /*
     * Segunda pasada:
     * ya sin referencias de adyacencia, se eliminan los vértices.
     */
    actual = primero;

    while (actual != nullptr) {
        NodoGrafo* siguiente = actual->siguiente;

        delete actual;

        actual = siguiente;
    }

    primero = nullptr;
    totalSedes = 0;
}


// ============================================================
// VÉRTICES
// ============================================================

NodoGrafo* GrafoSedes::buscarSedeInterna(
    const std::string& codigo) const {

    NodoGrafo* actual = primero;

    while (actual != nullptr) {
        if (actual->sede.codigo == codigo) {
            return actual;
        }

        actual = actual->siguiente;
    }

    return nullptr;
}

const NodoGrafo* GrafoSedes::buscarSede(
    const std::string& codigo) const {

    return buscarSedeInterna(codigo);
}

int GrafoSedes::cantidadSedes() const {
    return totalSedes;
}

const NodoGrafo* GrafoSedes::obtenerPrimeraSede() const {
    return primero;
}

bool GrafoSedes::insertarSede(const Sede& sede) {
    /*
     * Un código vacío no constituye un vértice válido.
     * Tampoco se permiten códigos duplicados.
     */
    if (sede.codigo.empty() ||
        buscarSedeInterna(sede.codigo) != nullptr) {
        return false;
    }

    NodoGrafo* nuevo = new NodoGrafo(sede);

    if (primero == nullptr) {
        primero = nuevo;
        totalSedes++;
        return true;
    }

    NodoGrafo* actual = primero;

    while (actual->siguiente != nullptr) {
        actual = actual->siguiente;
    }

    actual->siguiente = nuevo;

    totalSedes++;

    return true;
}


// ============================================================
// LISTAS DE ADYACENCIA
// ============================================================

NodoAdyacencia* GrafoSedes::buscarAdyacencia(
    NodoGrafo* origen,
    const std::string& codigoDestino) const {

    if (origen == nullptr) {
        return nullptr;
    }

    NodoAdyacencia* actual = origen->adyacencias;

    while (actual != nullptr) {
        if (actual->destino != nullptr &&
            actual->destino->sede.codigo == codigoDestino) {
            return actual;
        }

        actual = actual->siguiente;
    }

    return nullptr;
}

void GrafoSedes::insertarOActualizarAdyacencia(
    NodoGrafo* origen,
    NodoGrafo* destino,
    int peso) {

    NodoAdyacencia* existente =
        buscarAdyacencia(origen, destino->sede.codigo);

    if (existente != nullptr) {
        existente->peso = peso;
        return;
    }

    NodoAdyacencia* nueva =
        new NodoAdyacencia(destino, peso);

    /*
     * Las adyacencias se mantienen ordenadas por código.
     *
     * Esto no es obligatorio para representar el grafo,
     * pero hace determinista BFS cuando existen varias
     * rutas con exactamente la misma cantidad de saltos.
     */
    if (origen->adyacencias == nullptr ||
        destino->sede.codigo <
            origen->adyacencias->destino->sede.codigo) {

        nueva->siguiente = origen->adyacencias;
        origen->adyacencias = nueva;
        return;
    }

    NodoAdyacencia* actual = origen->adyacencias;

    while (actual->siguiente != nullptr &&
           actual->siguiente->destino->sede.codigo <
               destino->sede.codigo) {

        actual = actual->siguiente;
    }

    nueva->siguiente = actual->siguiente;
    actual->siguiente = nueva;
}

bool GrafoSedes::crearOActualizarRelacion(
    const std::string& codigoA,
    const std::string& codigoB,
    int peso) {

    // No se permiten autoaristas.
    if (codigoA == codigoB) {
        return false;
    }

    NodoGrafo* sedeA =
        buscarSedeInterna(codigoA);

    NodoGrafo* sedeB =
        buscarSedeInterna(codigoB);

    if (sedeA == nullptr ||
        sedeB == nullptr) {
        return false;
    }

    /*
     * Una relación con peso cero no debe existir.
     *
     * Así esta misma API puede utilizarse posteriormente
     * cuando una actualización haga desaparecer la última
     * película compartida.
     */
    if (peso <= 0) {
        eliminarRelacion(codigoA, codigoB);
        return true;
    }

    /*
     * Son dos NodoAdyacencia independientes.
     *
     * Representan una sola relación lógica no dirigida.
     */
    insertarOActualizarAdyacencia(
        sedeA,
        sedeB,
        peso);

    insertarOActualizarAdyacencia(
        sedeB,
        sedeA,
        peso);

    return true;
}

bool GrafoSedes::eliminarAdyacencia(
    NodoGrafo* origen,
    const std::string& codigoDestino) {

    if (origen == nullptr) {
        return false;
    }

    NodoAdyacencia* actual =
        origen->adyacencias;

    NodoAdyacencia* anterior =
        nullptr;

    while (actual != nullptr) {

        if (actual->destino != nullptr &&
            actual->destino->sede.codigo ==
                codigoDestino) {

            if (anterior == nullptr) {
                origen->adyacencias =
                    actual->siguiente;
            } else {
                anterior->siguiente =
                    actual->siguiente;
            }

            delete actual;

            return true;
        }

        anterior = actual;
        actual = actual->siguiente;
    }

    return false;
}

bool GrafoSedes::eliminarRelacion(
    const std::string& codigoA,
    const std::string& codigoB) {

    NodoGrafo* sedeA =
        buscarSedeInterna(codigoA);

    NodoGrafo* sedeB =
        buscarSedeInterna(codigoB);

    if (sedeA == nullptr ||
        sedeB == nullptr ||
        codigoA == codigoB) {
        return false;
    }

    /*
     * Eliminamos ambos sentidos incluso si, por alguna
     * inconsistencia previa, solamente existe uno.
     */
    bool eliminadoA =
        eliminarAdyacencia(sedeA, codigoB);

    bool eliminadoB =
        eliminarAdyacencia(sedeB, codigoA);

    return eliminadoA || eliminadoB;
}

int GrafoSedes::obtenerPeso(
    const std::string& codigoA,
    const std::string& codigoB) const {

    NodoGrafo* sedeA =
        buscarSedeInterna(codigoA);

    NodoAdyacencia* relacion =
        buscarAdyacencia(sedeA, codigoB);

    if (relacion == nullptr) {
        return 0;
    }

    return relacion->peso;
}

const NodoAdyacencia* GrafoSedes::obtenerAdyacencias(
    const std::string& codigoSede) const {

    NodoGrafo* sede =
        buscarSedeInterna(codigoSede);

    if (sede == nullptr) {
        return nullptr;
    }

    return sede->adyacencias;
}

void GrafoSedes::liberarListaAdyacencia(
    NodoGrafo* vertice) {

    if (vertice == nullptr) {
        return;
    }

    NodoAdyacencia* actual =
        vertice->adyacencias;

    while (actual != nullptr) {
        NodoAdyacencia* siguiente =
            actual->siguiente;

        delete actual;

        actual = siguiente;
    }

    vertice->adyacencias = nullptr;
}

void GrafoSedes::limpiarRelaciones() {
    NodoGrafo* actual = primero;

    while (actual != nullptr) {
        liberarListaAdyacencia(actual);

        actual = actual->siguiente;
    }
}


// ============================================================
// RELACIONES DERIVADAS DE LAS FUNCIONES
// ============================================================

void GrafoSedes::agregarPeliculaTemporal(
    RegistroPeliculaSede*& cabeza,
    const std::string& codigoSede,
    const std::string& codigoPelicula) const {

    if (codigoSede.empty() ||
        codigoPelicula.empty()) {
        return;
    }

    /*
     * Se verifica explícitamente que la combinación
     * sede/película no exista todavía.
     *
     * F001 P001 S001
     * F002 P001 S001
     *
     * aportan una sola entrada:
     *
     * S001/P001
     */
    RegistroPeliculaSede* actual =
        cabeza;

    while (actual != nullptr) {
        if (actual->codigoSede == codigoSede &&
            actual->codigoPelicula == codigoPelicula) {
            return;
        }

        actual = actual->siguiente;
    }

    RegistroPeliculaSede* nuevo =
        new RegistroPeliculaSede(
            codigoSede,
            codigoPelicula);

    nuevo->siguiente = cabeza;
    cabeza = nuevo;
}

void GrafoSedes::recolectarFuncionAVL(
    const NodoAVL* funcion,
    void* contexto) {

    if (funcion == nullptr ||
        contexto == nullptr) {
        return;
    }

    ContextoRecoleccion* datos =
        static_cast<ContextoRecoleccion*>(
            contexto);

    /*
     * Únicamente se utilizan funciones cuya sede existe
     * actualmente como vértice del grafo.
     *
     * E3 será la responsable de validar esa referencia
     * durante la carga masiva real.
     */
    if (datos->grafo->buscarSedeInterna(
            funcion->codigo_sede) == nullptr) {
        return;
    }

    /*
     * IMPORTANTE:
     * usamos codigo_pelicula_real.
     *
     * No usamos el título histórico almacenado en
     * codigo_pelicula.
     */
    datos->grafo->agregarPeliculaTemporal(
        datos->cabeza,
        funcion->codigo_sede,
        funcion->codigo_pelicula_real);
}

int GrafoSedes::contarPeliculasCompartidas(
    RegistroPeliculaSede* cabeza,
    const std::string& sedeA,
    const std::string& sedeB) const {

    int compartidas = 0;

    RegistroPeliculaSede* actualA =
        cabeza;

    while (actualA != nullptr) {

        if (actualA->codigoSede == sedeA) {

            RegistroPeliculaSede* actualB =
                cabeza;

            while (actualB != nullptr) {

                if (actualB->codigoSede == sedeB &&
                    actualB->codigoPelicula ==
                        actualA->codigoPelicula) {

                    compartidas++;
                    break;
                }

                actualB =
                    actualB->siguiente;
            }
        }

        actualA =
            actualA->siguiente;
    }

    return compartidas;
}

void GrafoSedes::liberarPeliculasTemporales(
    RegistroPeliculaSede*& cabeza) const {

    while (cabeza != nullptr) {

        RegistroPeliculaSede* siguiente =
            cabeza->siguiente;

        delete cabeza;

        cabeza = siguiente;
    }
}

void GrafoSedes::recalcularRelaciones(
    const ArbolAVL& arbolFunciones) {

    /*
     * Estrategia deliberadamente simple:
     *
     * 1. borrar todas las relaciones;
     * 2. obtener pares únicos sede/película;
     * 3. comparar cada par de sedes;
     * 4. volver a construir únicamente las aristas
     *    cuyo peso sea mayor que cero.
     *
     * El AVL continúa siendo dueño de las funciones.
     */
    limpiarRelaciones();

    ContextoRecoleccion contexto;

    contexto.grafo = this;
    contexto.cabeza = nullptr;

    arbolFunciones.recorrerFunciones(
        &GrafoSedes::recolectarFuncionAVL,
        &contexto);

    NodoGrafo* sedeA = primero;

    while (sedeA != nullptr) {

        NodoGrafo* sedeB =
            sedeA->siguiente;

        while (sedeB != nullptr) {

            int peso =
                contarPeliculasCompartidas(
                    contexto.cabeza,
                    sedeA->sede.codigo,
                    sedeB->sede.codigo);

            if (peso > 0) {

                crearOActualizarRelacion(
                    sedeA->sede.codigo,
                    sedeB->sede.codigo,
                    peso);
            }

            sedeB =
                sedeB->siguiente;
        }

        sedeA =
            sedeA->siguiente;
    }

    liberarPeliculasTemporales(
        contexto.cabeza);
}


// ============================================================
// BFS
// ============================================================

GrafoSedes::RegistroBFS*
GrafoSedes::buscarRegistroBFS(
    RegistroBFS* cabeza,
    NodoGrafo* vertice) const {

    RegistroBFS* actual = cabeza;

    while (actual != nullptr) {

        if (actual->vertice == vertice) {
            return actual;
        }

        actual =
            actual->siguiente;
    }

    return nullptr;
}

void GrafoSedes::liberarRegistrosBFS(
    RegistroBFS*& cabeza) const {

    while (cabeza != nullptr) {

        RegistroBFS* siguiente =
            cabeza->siguiente;

        delete cabeza;

        cabeza = siguiente;
    }
}

ResultadoBFS GrafoSedes::buscarCaminoBFS(
    const std::string& origen,
    const std::string& destino) const {

    ResultadoBFS resultado;

    NodoGrafo* nodoOrigen =
        buscarSedeInterna(origen);

    NodoGrafo* nodoDestino =
        buscarSedeInterna(destino);

    resultado.origenEncontrado =
        nodoOrigen != nullptr;

    resultado.destinoEncontrado =
        nodoDestino != nullptr;

    if (nodoOrigen == nullptr ||
        nodoDestino == nullptr) {
        return resultado;
    }

    // El camino de una sede hacia sí misma es ella misma.
    if (nodoOrigen == nodoDestino) {
        resultado.existeCamino = true;
        resultado.ruta.push_back(origen);

        return resultado;
    }

    /*
     * visitados es una lista manual.
     *
     * Cada registro almacena además quién descubrió al
     * vértice, permitiendo reconstruir el camino.
     */
    RegistroBFS* visitados =
        new RegistroBFS(
            nodoOrigen,
            nullptr);

    ColaBFS cola;

    cola.encolar(visitados);

    RegistroBFS* registroDestino =
        nullptr;

    while (!cola.vacia()) {

        RegistroBFS* actual =
            cola.desencolar();

        /*
         * IMPORTANTE:
         *
         * No se consulta actual->peso.
         *
         * BFS únicamente considera la existencia de una
         * arista y por eso minimiza cantidad de saltos.
         */
        NodoAdyacencia* adyacente =
            actual->vertice->adyacencias;

        while (adyacente != nullptr) {

            if (buscarRegistroBFS(
                    visitados,
                    adyacente->destino) == nullptr) {

                RegistroBFS* nuevo =
                    new RegistroBFS(
                        adyacente->destino,
                        actual);

                nuevo->siguiente =
                    visitados;

                visitados =
                    nuevo;

                if (adyacente->destino ==
                    nodoDestino) {

                    registroDestino =
                        nuevo;

                    break;
                }

                cola.encolar(nuevo);
            }

            adyacente =
                adyacente->siguiente;
        }

        if (registroDestino != nullptr) {
            break;
        }
    }

    if (registroDestino != nullptr) {

        resultado.existeCamino = true;

        /*
         * Pila enlazada temporal para invertir:
         *
         * destino -> ... -> origen
         *
         * y devolver:
         *
         * origen -> ... -> destino
         */
        struct NodoRutaTemporal {
            std::string codigo;
            NodoRutaTemporal* siguiente;

            explicit NodoRutaTemporal(
                const std::string& codigo)
                : codigo(codigo),
                siguiente(nullptr) {
            }
        };

        NodoRutaTemporal* ruta =
            nullptr;

        RegistroBFS* actual =
            registroDestino;

        while (actual != nullptr) {

            NodoRutaTemporal* nuevo =
                new NodoRutaTemporal(
                    actual->vertice->sede.codigo);

            nuevo->siguiente =
                ruta;

            ruta =
                nuevo;

            actual =
                actual->padre;
        }

        while (ruta != nullptr) {

            resultado.ruta.push_back(
                ruta->codigo);

            NodoRutaTemporal* siguiente =
                ruta->siguiente;

            delete ruta;

            ruta =
                siguiente;
        }
    }

    liberarRegistrosBFS(visitados);

    return resultado;
}


// ============================================================
// RANKING
// ============================================================

std::vector<RelacionGrafo>
GrafoSedes::obtenerRankingRelaciones() const {

    std::vector<RelacionGrafo> relaciones;

    NodoGrafo* origen = primero;

    while (origen != nullptr) {

        NodoAdyacencia* adyacente =
            origen->adyacencias;

        while (adyacente != nullptr) {

            /*
             * Como cada arista está físicamente en ambos
             * sentidos, únicamente almacenamos la versión:
             *
             * código menor -> código mayor
             *
             * De esta manera aparece una sola vez.
             */
            if (origen->sede.codigo <
                adyacente->destino->sede.codigo) {

                RelacionGrafo relacion;

                relacion.sedeA =
                    origen->sede.codigo;

                relacion.sedeB =
                    adyacente->destino->sede.codigo;

                relacion.peso =
                    adyacente->peso;

                relaciones.push_back(
                    relacion);
            }

            adyacente =
                adyacente->siguiente;
        }

        origen =
            origen->siguiente;
    }

    /*
     * Orden:
     *
     * 1. peso descendente;
     * 2. código de sede A ascendente;
     * 3. código de sede B ascendente.
     */
    std::sort(
        relaciones.begin(),
        relaciones.end(),

        [](const RelacionGrafo& a,
           const RelacionGrafo& b) {

            if (a.peso != b.peso) {
                return a.peso > b.peso;
            }

            if (a.sedeA != b.sedeA) {
                return a.sedeA < b.sedeA;
            }

            return a.sedeB < b.sedeB;
        });

    return relaciones;
}


// ============================================================
// SEDES SIMILARES
// ============================================================

std::vector<SedeSimilar>
GrafoSedes::obtenerSedesSimilares(
    const std::string& codigoSede) const {

    std::vector<SedeSimilar> similares;

    NodoGrafo* sede =
        buscarSedeInterna(codigoSede);

    if (sede == nullptr) {
        return similares;
    }

    /*
     * Únicamente se recorren vecinos directos.
     */
    NodoAdyacencia* adyacente =
        sede->adyacencias;

    while (adyacente != nullptr) {

        SedeSimilar item;

        item.sede =
            adyacente->destino->sede;

        item.peso =
            adyacente->peso;

        similares.push_back(item);

        adyacente =
            adyacente->siguiente;
    }

    /*
     * Mayor afinidad primero.
     *
     * En empate se usa código de sede ascendente.
     */
    std::sort(
        similares.begin(),
        similares.end(),

        [](const SedeSimilar& a,
           const SedeSimilar& b) {

            if (a.peso != b.peso) {
                return a.peso > b.peso;
            }

            return a.sede.codigo <
                   b.sede.codigo;
        });

    return similares;
}

// ============================================================
// REPORTE GRAPHVIZ — GRAFO NO DIRIGIDO
// ============================================================

bool GrafoSedes::generarReporteGrafoGraphviz() const
{
    std::ofstream archivo(
        "reporte_grafo_sedes.dot"
        );

    if (!archivo.is_open()) {
        return false;
    }

    archivo << "graph GrafoSedes {\n";
    archivo << "  rankdir=LR;\n";
    archivo << "  graph [bgcolor=\"white\"];\n";
    archivo << "  node [shape=box, style=\"rounded,filled\", "
               "fillcolor=\"lightblue\"];\n";
    archivo << "  edge [fontname=\"Arial\"];\n\n";

    // --------------------------------------------------------
    // VÉRTICES
    // --------------------------------------------------------

    const NodoGrafo* vertice =
        primero;

    while (vertice != nullptr) {

        std::string codigo =
            escaparDOT(
                vertice->sede.codigo
                );

        std::string nombre =
            escaparDOT(
                vertice->sede.nombre
                );

        archivo
            << "  \""
            << codigo
            << "\" [label=\""
            << codigo
            << "\\n"
            << nombre
            << "\"];\n";

        vertice =
            vertice->siguiente;
    }

    archivo << "\n";

    // --------------------------------------------------------
    // ARISTAS
    //
    // Cada relación física existe en ambos sentidos dentro
    // de la lista de adyacencia. Se dibuja únicamente cuando
    // codigoOrigen < codigoDestino para no duplicarla.
    // --------------------------------------------------------

    vertice = primero;

    while (vertice != nullptr) {

        const NodoAdyacencia* adyacente =
            vertice->adyacencias;

        while (adyacente != nullptr) {

            if (adyacente->destino != nullptr &&
                vertice->sede.codigo <
                    adyacente->destino->sede.codigo) {

                archivo
                    << "  \""
                    << escaparDOT(
                           vertice->sede.codigo
                           )
                    << "\" -- \""
                    << escaparDOT(
                           adyacente->destino
                               ->sede.codigo
                           )
                    << "\" [label=\"Peso: "
                    << adyacente->peso
                    << "\"];\n";
            }

            adyacente =
                adyacente->siguiente;
        }

        vertice =
            vertice->siguiente;
    }

    archivo << "}\n";

    archivo.close();

    QProcess proceso;

    proceso.start(
        "dot",
        QStringList()
            << "-Tpng"
            << "reporte_grafo_sedes.dot"
            << "-o"
            << "reporte_grafo_sedes.png"
        );

    if (!proceso.waitForFinished()) {
        return false;
    }

    return
        proceso.exitStatus() ==
            QProcess::NormalExit &&
        proceso.exitCode() == 0;
}

// ============================================================
// REPORTE GRAPHVIZ — LISTA DE ADYACENCIA
// ============================================================

bool GrafoSedes::generarReporteListaAdyacenciaGraphviz() const
{
    std::ofstream archivo(
        "reporte_lista_adyacencia.dot"
        );

    if (!archivo.is_open()) {
        return false;
    }

    archivo << "digraph ListaAdyacencia {\n";
    archivo << "  rankdir=LR;\n";
    archivo << "  graph [bgcolor=\"white\"];\n";
    archivo << "  node [shape=record];\n";
    archivo << "  edge [fontname=\"Arial\"];\n\n";

    const NodoGrafo* vertice =
        primero;

    int indiceVertice = 0;

    while (vertice != nullptr) {

        std::string idVertice =
            "vertice_" +
            std::to_string(
                indiceVertice
                );

        archivo
            << "  subgraph cluster_"
            << indiceVertice
            << " {\n";

        archivo
            << "    label=\""
            << escaparDOT(
                   vertice->sede.codigo
                   )
            << "\";\n";

        archivo
            << "    color=\"gray70\";\n";

        archivo
            << "    \""
            << idVertice
            << "\" [style=filled, "
               "fillcolor=\"lightblue\", "
               "label=\"{"
            << escaparDOT(
                   vertice->sede.codigo
                   )
            << "|"
            << escaparDOT(
                   vertice->sede.nombre
                   )
            << "}\"];\n";

        const NodoAdyacencia* adyacente =
            vertice->adyacencias;

        std::string idAnterior =
            idVertice;

        int indiceAdyacencia = 0;

        if (adyacente == nullptr) {

            std::string idNull =
                "null_" +
                std::to_string(
                    indiceVertice
                    );

            archivo
                << "    \""
                << idNull
                << "\" [shape=plaintext, "
                   "label=\"NULL\"];\n";

            archivo
                << "    \""
                << idAnterior
                << "\" -> \""
                << idNull
                << "\" [style=dashed];\n";
        }

        while (adyacente != nullptr) {

            std::string idActual =
                "ady_" +
                std::to_string(
                    indiceVertice
                    ) +
                "_" +
                std::to_string(
                    indiceAdyacencia
                    );

            archivo
                << "    \""
                << idActual
                << "\" [label=\"{"
                << escaparDOT(
                       adyacente->destino
                           ->sede.codigo
                       )
                << "|Peso: "
                << adyacente->peso
                << "}\"];\n";

            archivo
                << "    \""
                << idAnterior
                << "\" -> \""
                << idActual
                << "\";\n";

            idAnterior =
                idActual;

            indiceAdyacencia++;

            adyacente =
                adyacente->siguiente;
        }

        archivo << "  }\n\n";

        indiceVertice++;

        vertice =
            vertice->siguiente;
    }

    archivo << "}\n";

    archivo.close();

    QProcess proceso;

    proceso.start(
        "dot",
        QStringList()
            << "-Tpng"
            << "reporte_lista_adyacencia.dot"
            << "-o"
            << "reporte_lista_adyacencia.png"
        );

    if (!proceso.waitForFinished()) {
        return false;
    }

    return
        proceso.exitStatus() ==
            QProcess::NormalExit &&
        proceso.exitCode() == 0;
}
