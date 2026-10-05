#include "ArbolPeliculas.h"
#include <QDebug>
#include <QFile>
#include <QTextStream>
#include <QProcess>
#include <QTableWidgetItem> //crea celdas

ArbolPeliculas::ArbolPeliculas() {
    raiz = nullptr;
}

void ArbolPeliculas::insertar(Pelicula p) {
    raiz = insertarRecursivo(raiz, p);
}

NodoBST* ArbolPeliculas::insertarRecursivo(NodoBST* nodo, Pelicula p) {
    // Si el nodo está vacío, encontramos el lugar correcto para insertar
    if (nodo == nullptr) {
        return new NodoBST(p);
    }

    // Comparar códigos para mantener el orden del BST
    if (p.codigo < nodo->pelicula.codigo) {
        // El código es menor, vamos a la izquierda
        nodo->izquierdo = insertarRecursivo(nodo->izquierdo, p);
    } else if (p.codigo > nodo->pelicula.codigo) {
        // El código es mayor, vamos a la derecha
        nodo->derecho = insertarRecursivo(nodo->derecho, p);
    } else {
        // Si es igual, el código ya existe.
        qDebug() << "Alerta: La película con el código" << p.codigo << "ya está registrada.";
    }

    return nodo;
}

// Método in-orden (Izquierda - Raíz - Derecha) para mostrar ordenado
void ArbolPeliculas::inOrdenRecursivo(NodoBST* nodo) {
    if (nodo != nullptr) {
        inOrdenRecursivo(nodo->izquierdo);
        qDebug() << nodo->pelicula.codigo << "-" << nodo->pelicula.titulo;
        inOrdenRecursivo(nodo->derecho);
    }
}

void ArbolPeliculas::mostrarInOrden() {
    inOrdenRecursivo(raiz);
}

// Método recursivo privado
void ArbolPeliculas::generarDOTRecursivo(NodoBST* nodo, QTextStream& stream, QDate hoy) {
    if (nodo != nullptr) {

        // --- 1. LÓGICA DE COLORES ---
        QString colorFondo = "\"#a2f0a2\""; // Verde por defecto (En cartelera)

        QDate fechaFin = QDate::fromString(nodo->pelicula.fechaFin, "yyyy-MM-dd");
        if (!fechaFin.isValid()) fechaFin = QDate::fromString(nodo->pelicula.fechaFin, "dd/MM/yyyy");

        if (fechaFin.isValid()) {
            int diasRestantes = hoy.daysTo(fechaFin);

            // Si faltan 7 días o menos (y aún no ha expirado), lo pintamos de amarillo
            if (diasRestantes >= 0 && diasRestantes <= 7) {
                colorFondo = "\"#fff59d\""; // Amarillo (Próximo a retirar)
            }
            // Opcional: Si ya expiró, rojo
            else if (diasRestantes < 0) {
                colorFondo = "\"#ffcdd2\""; // Rojo
            }
        }

        // --- 2. DIBUJAR NODO RECTANGULAR ---
        stream << "  \"" << nodo->pelicula.codigo << "\" [label=\""
               << "Código: " << nodo->pelicula.codigo << "\\n"
               << "Título: " << nodo->pelicula.titulo << "\\n"
               << "Duración: " << nodo->pelicula.duracion << " min\\n"
               << "Clasificación: " << nodo->pelicula.clasificacion
               << "\", shape=box, style=\"rounded,filled\", fillcolor=" << colorFondo << "];\n";

        // --- 3. DIBUJAR FLECHAS (Hijos) ---
        if (nodo->izquierdo != nullptr) {
            stream << "  \"" << nodo->pelicula.codigo << "\" -> \"" << nodo->izquierdo->pelicula.codigo << "\";\n";
            generarDOTRecursivo(nodo->izquierdo, stream, hoy);
        }
        if (nodo->derecho != nullptr) {
            stream << "  \"" << nodo->pelicula.codigo << "\" -> \"" << nodo->derecho->pelicula.codigo << "\";\n";
            generarDOTRecursivo(nodo->derecho, stream, hoy);
        }
    }
}

// Método público que crea el archivo y genera la imagen
// Método público
void ArbolPeliculas::generarReporteDOT() {
    if (raiz == nullptr) {
        qDebug() << "El árbol está vacío, no hay cartelera para reportar.";
        return;
    }

    QFile archivo("reporte_cartelera.dot");
    if (!archivo.open(QIODevice::WriteOnly | QIODevice::Text)) return;

    QTextStream stream(&archivo);
    stream << "digraph ArbolCartelera {\n";
    stream << "  node [fontname=\"Helvetica\"];\n";

    // Obtenemos la fecha exacta de hoy para hacer la matemática de colores
    QDate hoy = QDate::currentDate();
    generarDOTRecursivo(raiz, stream, hoy);

    stream << "}\n";
    archivo.close();

    // Generar el PNG
    QProcess comando;
    comando.start("dot", QStringList() << "-Tpng" << "reporte_cartelera.dot" << "-o" << "reporte_cartelera.png");
    comando.waitForFinished();
}


void ArbolPeliculas::poblarTablaRecursivo(NodoBST* nodo, QTableWidget* tabla, int& filaActual) {
    // Usamos recorrido InOrden para que aparezcan ordenadas por código
    if (nodo != nullptr) {
        poblarTablaRecursivo(nodo->izquierdo, tabla, filaActual);

        // Insertar una nueva fila en la tabla visual
        tabla->insertRow(filaActual);

        // Llenar las 8 columnas de esa fila[cite: 1]
        tabla->setItem(filaActual, 0, new QTableWidgetItem(nodo->pelicula.codigo));
        tabla->setItem(filaActual, 1, new QTableWidgetItem(nodo->pelicula.titulo));
        tabla->setItem(filaActual, 2, new QTableWidgetItem(nodo->pelicula.genero));
        tabla->setItem(filaActual, 3, new QTableWidgetItem(QString::number(nodo->pelicula.duracion) + " min"));
        tabla->setItem(filaActual, 4, new QTableWidgetItem(nodo->pelicula.clasificacion));
        tabla->setItem(filaActual, 5, new QTableWidgetItem(nodo->pelicula.idioma));
        tabla->setItem(filaActual, 6, new QTableWidgetItem(nodo->pelicula.fechaEstreno));
        tabla->setItem(filaActual, 7, new QTableWidgetItem(nodo->pelicula.fechaFin));

        filaActual++; // Avanzamos a la siguiente fila visual

        poblarTablaRecursivo(nodo->derecho, tabla, filaActual);
    }
}

// --- 1. BÚSQUEDA POR CÓDIGO (Cliente) ---
Pelicula* ArbolPeliculas::buscarPelicula(QString codigo) {
    NodoBST* resultado = buscarRecursivo(raiz, codigo);
    if (resultado != nullptr) return &(resultado->pelicula);
    return nullptr;
}

NodoBST* ArbolPeliculas::buscarRecursivo(NodoBST* nodo, QString codigo) {
    // Caso base: el nodo es nulo o encontramos el código
    if (nodo == nullptr || nodo->pelicula.codigo == codigo) {
        return nodo;
    }
    // Si el código buscado es menor, nos vamos a la izquierda
    if (codigo < nodo->pelicula.codigo) {
        return buscarRecursivo(nodo->izquierdo, codigo);
    }
    // Si es mayor, nos vamos a la derecha
    return buscarRecursivo(nodo->derecho, codigo);
}

// --- 2. ALERTAS DE EXPIRACIÓN (Admin) ---
QString ArbolPeliculas::obtenerAlertasExpiracion() {
    QString alertas = "";
    QDate hoy = QDate::currentDate(); // Tomamos la fecha de hoy

    recolectarAlertas(raiz, hoy, alertas);

    if (alertas.isEmpty()) return "Todas las películas están vigentes con tiempo de sobra.";
    return alertas;
}

void ArbolPeliculas::recolectarAlertas(NodoBST* nodo, QDate hoy, QString& alertas) {
    if (nodo != nullptr) {
        recolectarAlertas(nodo->izquierdo, hoy, alertas);

        QDate fechaFin = QDate::fromString(nodo->pelicula.fechaFin, "yyyy-MM-dd");
        if (!fechaFin.isValid()) fechaFin = QDate::fromString(nodo->pelicula.fechaFin, "dd/MM/yyyy");

        // 🔥 CORRECCIÓN: Calculamos la diferencia exacta
        int diasRestantes = hoy.daysTo(fechaFin);

        // Validamos que falten 7 días o menos, y que la fecha no haya pasado ya (>= 0)
        if (fechaFin.isValid() && diasRestantes >= 0 && diasRestantes <= 7) {
            alertas += "⚠️ " + nodo->pelicula.codigo + " - " + nodo->pelicula.titulo +
                       " (Sale en: " + QString::number(diasRestantes) + " días)\n";
        }

        recolectarAlertas(nodo->derecho, hoy, alertas);
    }
}

// --- 3. ELIMINACIÓN DE PELÍCULA (Admin) ---

// Método público
bool ArbolPeliculas::eliminarPelicula(QString codigo) {
    bool eliminada = false;
    raiz = eliminarRecursivo(raiz, codigo, eliminada);
    return eliminada;
}

// Método auxiliar para encontrar el sucesor (el menor de los mayores)
NodoBST* ArbolPeliculas::encontrarMinimo(NodoBST* nodo) {
    NodoBST* actual = nodo;
    // Ir lo más a la izquierda posible
    while (actual && actual->izquierdo != nullptr) {
        actual = actual->izquierdo;
    }
    return actual;
}

// Método privado recursivo
NodoBST* ArbolPeliculas::eliminarRecursivo(NodoBST* nodo, QString codigo, bool& eliminada) {
    // Caso base: llegamos a una hoja o el árbol está vacío
    if (nodo == nullptr) {
        return nodo;
    }

    // 1. Navegamos por el árbol buscando el código
    if (codigo < nodo->pelicula.codigo) {
        nodo->izquierdo = eliminarRecursivo(nodo->izquierdo, codigo, eliminada);
    }
    else if (codigo > nodo->pelicula.codigo) {
        nodo->derecho = eliminarRecursivo(nodo->derecho, codigo, eliminada);
    }
    // 2. ¡Lo encontramos! Procesamos la eliminación
    else {
        eliminada = true;

        // Caso A: El nodo no tiene hijo izquierdo (o es una hoja sin hijos)
        if (nodo->izquierdo == nullptr) {
            NodoBST* temp = nodo->derecho;
            delete nodo; // Liberamos memoria
            return temp; // Conectamos el padre con el hijo derecho
        }
        // Caso B: El nodo no tiene hijo derecho
        else if (nodo->derecho == nullptr) {
            NodoBST* temp = nodo->izquierdo;
            delete nodo;
            return temp; // Conectamos el padre con el hijo izquierdo
        }

        // Caso C: El nodo tiene 2 hijos (El más complejo)
        // Buscamos el sucesor en inorden (el nodo más pequeño del subárbol derecho)
        NodoBST* temp = encontrarMinimo(nodo->derecho);

        // Copiamos TODOS los datos de la película del sucesor al nodo actual
        nodo->pelicula = temp->pelicula;

        // Ahora eliminamos el nodo sucesor que nos prestó sus datos
        nodo->derecho = eliminarRecursivo(nodo->derecho, temp->pelicula.codigo, eliminada);
    }

    return nodo;
}

void ArbolPeliculas::poblarComboUI(QComboBox* combo) {
    combo->clear(); // Borramos los datos viejos/eliminados
    poblarComboRecursivo(raiz, combo);
}

void ArbolPeliculas::poblarComboRecursivo(NodoBST* nodo, QComboBox* combo) {
    if (nodo != nullptr) {
        poblarComboRecursivo(nodo->izquierdo, combo);

        // Agregamos el título visualmente, y guardamos el código de forma oculta por si lo necesitas
        combo->addItem(nodo->pelicula.titulo, nodo->pelicula.codigo);

        poblarComboRecursivo(nodo->derecho, combo);
    }
}

// --- MÉTODO AUXILIAR PARA PINTAR LA FILA ---
void ArbolPeliculas::insertarFilaTabla(NodoBST* nodo, QTableWidget* tabla, int& filaActual) {
    tabla->insertRow(filaActual);
    tabla->setItem(filaActual, 0, new QTableWidgetItem(nodo->pelicula.codigo));
    tabla->setItem(filaActual, 1, new QTableWidgetItem(nodo->pelicula.titulo));
    tabla->setItem(filaActual, 2, new QTableWidgetItem(nodo->pelicula.genero));
    tabla->setItem(filaActual, 3, new QTableWidgetItem(QString::number(nodo->pelicula.duracion) + " min"));
    tabla->setItem(filaActual, 4, new QTableWidgetItem(nodo->pelicula.clasificacion));
    tabla->setItem(filaActual, 5, new QTableWidgetItem(nodo->pelicula.idioma));
    tabla->setItem(filaActual, 6, new QTableWidgetItem(nodo->pelicula.fechaEstreno));
    tabla->setItem(filaActual, 7, new QTableWidgetItem(nodo->pelicula.fechaFin));
    filaActual++;
}

// --- 1. INORDEN (Izquierda - Raíz - Derecha) -> Orden Ascendente ---
void ArbolPeliculas::poblarTablaInOrden(QTableWidget* tabla) {
    tabla->setRowCount(0);

    // ---> AÑADIR ESTO: Aseguramos las 8 columnas para que Qt no las oculte <---
    if (tabla->columnCount() < 8) {
        tabla->setColumnCount(8);
        tabla->setHorizontalHeaderLabels(QStringList() << "Código" << "Título" << "Género"
                                                       << "Duración" << "Clasificación"
                                                       << "Idioma" << "Estreno" << "Fin");
    }

    int fila = 0;
    poblarTablaRecursivoIn(raiz, tabla, fila);

    // Opcional: Ajusta el ancho para que los textos largos (como el título) quepan bien
    tabla->resizeColumnsToContents();
}

void ArbolPeliculas::poblarTablaRecursivoIn(NodoBST* nodo, QTableWidget* tabla, int& fila) {
    if (nodo != nullptr) {
        poblarTablaRecursivoIn(nodo->izquierdo, tabla, fila);
        insertarFilaTabla(nodo, tabla, fila);
        poblarTablaRecursivoIn(nodo->derecho, tabla, fila);
    }
}

// --- 2. PREORDEN (Raíz - Izquierda - Derecha) ---
void ArbolPeliculas::poblarTablaPreOrden(QTableWidget* tabla) {
    tabla->setRowCount(0);
    int fila = 0;
    poblarTablaRecursivoPre(raiz, tabla, fila);
}

void ArbolPeliculas::poblarTablaRecursivoPre(NodoBST* nodo, QTableWidget* tabla, int& fila) {
    if (nodo != nullptr) {
        insertarFilaTabla(nodo, tabla, fila); // Raíz primero
        poblarTablaRecursivoPre(nodo->izquierdo, tabla, fila);
        poblarTablaRecursivoPre(nodo->derecho, tabla, fila);
    }
}

// --- 3. POSTORDEN (Izquierda - Derecha - Raíz) ---
void ArbolPeliculas::poblarTablaPostOrden(QTableWidget* tabla) {
    tabla->setRowCount(0);
    int fila = 0;
    poblarTablaRecursivoPost(raiz, tabla, fila);
}

void ArbolPeliculas::poblarTablaRecursivoPost(NodoBST* nodo, QTableWidget* tabla, int& fila) {
    if (nodo != nullptr) {
        poblarTablaRecursivoPost(nodo->izquierdo, tabla, fila);
        poblarTablaRecursivoPost(nodo->derecho, tabla, fila);
        insertarFilaTabla(nodo, tabla, fila); // Raíz al final
    }
}



// --- NUEVOS MÉTODOS PARA BUSCAR POR TÍTULO ---

Pelicula* ArbolPeliculas::buscarPeliculaPorTitulo(QString titulo) {
    return buscarPorTituloRecursivo(raiz, titulo);
}

Pelicula* ArbolPeliculas::buscarPorTituloRecursivo(NodoBST* nodo, QString titulo) {
    // Caso base: si llegamos a una hoja nula, no se encontró por este camino
    if (nodo == nullptr) {
        return nullptr;
    }

    // Comparamos el título del nodo actual con el buscado (Limpiando y en minúsculas)
    if (nodo->pelicula.titulo.trimmed().toLower() == titulo.trimmed().toLower()) {
        return &(nodo->pelicula); // ¡Encontrada! Retornamos su dirección en memoria
    }

    // Si no es el actual, buscamos recursivamente en todo el subárbol izquierdo
    Pelicula* encontradaIzq = buscarPorTituloRecursivo(nodo->izquierdo, titulo);
    if (encontradaIzq != nullptr) {
        return encontradaIzq; // Si la encontró a la izquierda, propagamos el resultado hacia arriba
    }

    // Si tampoco estaba a la izquierda, buscamos en el subárbol derecho
    return buscarPorTituloRecursivo(nodo->derecho, titulo);
}















