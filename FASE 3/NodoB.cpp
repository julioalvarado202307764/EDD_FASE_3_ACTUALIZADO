#include "NodoB.h"

// ==========================================
// 1. CONSTRUCTOR
// ==========================================
NodoB::NodoB(bool hoja) {
    es_hoja = hoja;
    conteo_claves = 0;

    // Inicializamos los punteros en nulo por seguridad
    for (int i = 0; i < 3; ++i) {
        clientes[i] = nullptr;
    }
    for (int i = 0; i < 4; ++i) {
        hijos[i] = nullptr;
    }
}

// ==========================================
// 2. BÚSQUEDA
// ==========================================
Cliente* NodoB::buscar(std::string id) {
    int i = 0;
    while (i < conteo_claves && id > clientes[i]->id) {
        i++;
    }
    // Si lo encontramos en este nodo, lo devolvemos
    if (i < conteo_claves && clientes[i]->id == id) {
        return clientes[i];
    }
    // Si es hoja y no lo encontramos, no existe
    if (es_hoja) {
        return nullptr;
    }
    // Si no es hoja, bajamos al hijo correspondiente
    return hijos[i]->buscar(id);
}

int NodoB::buscarClave(std::string id) {
    int idx = 0;
    while (idx < conteo_claves && clientes[idx]->id < id) {
        ++idx;
    }
    return idx;
}

// ==========================================
// 3. INSERCIÓN
// ==========================================
void NodoB::insertarNoLleno(Cliente cliente) {
    int i = conteo_claves - 1;

    if (es_hoja) {
        // Encontrar la ubicación para la nueva clave y mover las mayores un espacio adelante
        while (i >= 0 && clientes[i]->id > cliente.id) {
            clientes[i + 1] = clientes[i];
            i--;
        }
        // Insertamos el cliente dinámicamente
        clientes[i + 1] = new Cliente(cliente);
        conteo_claves++;
    } else {
        // Encontrar el hijo que va a recibir el nuevo cliente
        while (i >= 0 && clientes[i]->id > cliente.id) {
            i--;
        }
        i++; // Ajustamos al índice del hijo correcto

        // Si el hijo está lleno (3 claves), lo dividimos
        if (hijos[i]->conteo_claves == 3) {
            dividirHijo(i, hijos[i]);

            // Después de dividir, la clave del medio subió. Vemos a qué lado debemos bajar
            if (clientes[i]->id < cliente.id) {
                i++;
            }
        }
        hijos[i]->insertarNoLleno(cliente);
    }
}

void NodoB::dividirHijo(int i, NodoB* y) {
    // Crear un nuevo nodo que va a almacenar 1 clave de 'y' (Orden 4 -> max 3 claves, divide en 1 y 1)
    NodoB* z = new NodoB(y->es_hoja);
    z->conteo_claves = 1;

    // Pasamos la última clave de 'y' a 'z'
    z->clientes[0] = y->clientes[2];
    y->clientes[2] = nullptr;

    // Si no es hoja, pasamos los 2 últimos hijos de 'y' a 'z'
    if (!y->es_hoja) {
        z->hijos[0] = y->hijos[2];
        z->hijos[1] = y->hijos[3];
        y->hijos[2] = nullptr;
        y->hijos[3] = nullptr;
    }

    y->conteo_claves = 1; // 'y' se queda con 1 clave (la del índice 0)

    // Crear espacio en el nodo actual para el nuevo hijo 'z'
    for (int j = conteo_claves; j >= i + 1; j--) {
        hijos[j + 1] = hijos[j];
    }
    hijos[i + 1] = z;

    // Crear espacio en el nodo actual para la clave del medio de 'y' (índice 1)
    for (int j = conteo_claves - 1; j >= i; j--) {
        clientes[j + 1] = clientes[j];
    }
    clientes[i] = y->clientes[1];
    y->clientes[1] = nullptr;

    conteo_claves++;
}

// ==========================================
// 4. ELIMINACIÓN Y BALANCEO
// ==========================================
void NodoB::eliminar(std::string id) {
    int idx = buscarClave(id);

    if (idx < conteo_claves && clientes[idx]->id == id) {
        if (es_hoja) {
            eliminarDeHoja(idx);
        } else {
            eliminarDeNoHoja(idx);
        }
    } else {
        if (es_hoja) return;

        bool esUltimoHijo = (idx == conteo_claves);
        if (hijos[idx]->conteo_claves < 2) {
            llenar(idx);
        }

        if (esUltimoHijo && idx > conteo_claves) {
            hijos[idx - 1]->eliminar(id);
        } else {
            hijos[idx]->eliminar(id);
        }
    }
}

void NodoB::eliminarDeHoja(int idx) {
    delete clientes[idx];
    for (int i = idx + 1; i < conteo_claves; ++i) {
        clientes[i - 1] = clientes[i];
    }
    conteo_claves--;
}

void NodoB::eliminarDeNoHoja(int idx) {
    std::string k = clientes[idx]->id;

    if (hijos[idx]->conteo_claves >= 2) {
        Cliente* pred = obtenerPredecesor(idx);
        *clientes[idx] = *pred;
        hijos[idx]->eliminar(pred->id);
    }
    else if (hijos[idx + 1]->conteo_claves >= 2) {
        Cliente* suc = obtenerSucesor(idx);
        *clientes[idx] = *suc;
        hijos[idx + 1]->eliminar(suc->id);
    }
    else {
        fusionar(idx);
        hijos[idx]->eliminar(k);
    }
}

Cliente* NodoB::obtenerPredecesor(int idx) {
    NodoB* actual = hijos[idx];
    while (!actual->es_hoja) {
        actual = actual->hijos[actual->conteo_claves];
    }
    return actual->clientes[actual->conteo_claves - 1];
}

Cliente* NodoB::obtenerSucesor(int idx) {
    NodoB* actual = hijos[idx + 1];
    while (!actual->es_hoja) {
        actual = actual->hijos[0];
    }
    return actual->clientes[0];
}

void NodoB::llenar(int idx) {
    if (idx != 0 && hijos[idx - 1]->conteo_claves >= 2) {
        pedirPrestadoAnterior(idx);
    }
    else if (idx != conteo_claves && hijos[idx + 1]->conteo_claves >= 2) {
        pedirPrestadoSiguiente(idx);
    }
    else {
        if (idx != conteo_claves) {
            fusionar(idx);
        } else {
            fusionar(idx - 1);
        }
    }
}

void NodoB::pedirPrestadoAnterior(int idx) {
    NodoB* hijo = hijos[idx];
    NodoB* hermano = hijos[idx - 1];

    for (int i = hijo->conteo_claves - 1; i >= 0; --i) {
        hijo->clientes[i + 1] = hijo->clientes[i];
    }
    if (!hijo->es_hoja) {
        for (int i = hijo->conteo_claves; i >= 0; --i) {
            hijo->hijos[i + 1] = hijo->hijos[i];
        }
    }

    hijo->clientes[0] = clientes[idx - 1];
    if (!hijo->es_hoja) {
        hijo->hijos[0] = hermano->hijos[hermano->conteo_claves];
    }

    clientes[idx - 1] = hermano->clientes[hermano->conteo_claves - 1];

    hijo->conteo_claves += 1;
    hermano->conteo_claves -= 1;
}

void NodoB::pedirPrestadoSiguiente(int idx) {
    NodoB* hijo = hijos[idx];
    NodoB* hermano = hijos[idx + 1];

    hijo->clientes[hijo->conteo_claves] = clientes[idx];
    if (!hijo->es_hoja) {
        hijo->hijos[hijo->conteo_claves + 1] = hermano->hijos[0];
    }

    clientes[idx] = hermano->clientes[0];

    for (int i = 1; i < hermano->conteo_claves; ++i) {
        hermano->clientes[i - 1] = hermano->clientes[i];
    }
    if (!hermano->es_hoja) {
        for (int i = 1; i <= hermano->conteo_claves; ++i) {
            hermano->hijos[i - 1] = hermano->hijos[i];
        }
    }

    hijo->conteo_claves += 1;
    hermano->conteo_claves -= 1;
}

void NodoB::fusionar(int idx) {
    NodoB* hijo = hijos[idx];
    NodoB* hermano = hijos[idx + 1];

    hijo->clientes[1] = clientes[idx];

    for (int i = 0; i < hermano->conteo_claves; ++i) {
        hijo->clientes[i + 2] = hermano->clientes[i];
    }

    if (!hijo->es_hoja) {
        for (int i = 0; i <= hermano->conteo_claves; ++i) {
            hijo->hijos[i + 2] = hermano->hijos[i];
        }
    }

    for (int i = idx + 1; i < conteo_claves; ++i) {
        clientes[i - 1] = clientes[i];
    }
    for (int i = idx + 2; i <= conteo_claves; ++i) {
        hijos[i - 1] = hijos[i];
    }

    hijo->conteo_claves += hermano->conteo_claves + 1;
    conteo_claves--;

    // Evitamos borrar las direcciones de memoria de los clientes en el hermano vacío
    for(int i=0; i<3; i++) hermano->clientes[i] = nullptr;

    delete hermano;
}