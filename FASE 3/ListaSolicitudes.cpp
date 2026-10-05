#include "ListaSolicitudes.h"
#include <QFile>
#include <QProcess>
#include <QDebug>
#include <QTableWidgetItem>

ListaSolicitudes::ListaSolicitudes() {
    primero = nullptr;
    ultimo = nullptr;
    contadorId = 1; // Arrancamos las solicitudes en 1
}

void ListaSolicitudes::registrarSolicitud(QString cliente, QString telefono, QString tipo, QString descripcion, QString fecha) {
    // Creamos la solicitud usando el contador y luego lo aumentamos (contadorId++)
    Solicitud nueva(contadorId++, cliente, telefono, tipo, descripcion, fecha);
    NodoSolicitud* nuevoNodo = new NodoSolicitud(nueva);

    if (primero == nullptr) {
        // Si la lista está vacía, el nodo es el primero y el último
        primero = nuevoNodo;
        ultimo = nuevoNodo;
        // Se apunta a sí mismo para hacer el círculo
        primero->siguiente = primero;
        primero->anterior = ultimo;
    } else {
        // Enlazamos el nuevo nodo al final
        ultimo->siguiente = nuevoNodo;
        nuevoNodo->anterior = ultimo;
        // Cerramos el círculo
        nuevoNodo->siguiente = primero;
        primero->anterior = nuevoNodo;
        // Actualizamos quién es el último
        ultimo = nuevoNodo;
    }
    qDebug() << "Solicitud registrada con éxito. ID:" << nueva.id;
}

void ListaSolicitudes::generarReporteDOT() {
    if (primero == nullptr) {
        qDebug() << "No hay solicitudes para reportar.";
        return;
    }

    QFile archivo("reporte_solicitudes.dot");
    if (!archivo.open(QIODevice::WriteOnly | QIODevice::Text)) return;

    QTextStream stream(&archivo);

    // Configuramos el grafo en dirección horizontal (rankdir=LR)
    stream << "digraph ListaSolicitudes {\n";
    stream << "rankdir=LR;\n";
    stream << "node [shape=box, style=\"rounded,filled\", fillcolor=\"#ffdab9\", fontname=\"Helvetica\"];\n";

    NodoSolicitud* actual = primero;

    // Usamos do-while porque es una lista circular y queremos dar exactamente una vuelta
    do {
        // Declaramos el nodo y mostramos los datos requeridos[cite: 1]
        stream << "node" << actual->solicitud.id
               << " [label=\"Número: " << actual->solicitud.id
               << "\\nCliente: " << actual->solicitud.cliente
               << "\\nTipo: " << actual->solicitud.tipo
               << "\\nEstado: " << actual->solicitud.estado << "\"];\n";

        // Creamos la flecha bidireccional (dir=both) hacia el siguiente nodo
        stream << "node" << actual->solicitud.id << " -> node" << actual->siguiente->solicitud.id << " [dir=both];\n";

        actual = actual->siguiente;
    } while (actual != primero);

    stream << "}\n";
    archivo.close();

    // Generamos el PNG
    QProcess comando;
    comando.start("dot", QStringList() << "-Tpng" << "reporte_solicitudes.dot" << "-o" << "reporte_solicitudes.png");
    comando.waitForFinished();

    qDebug() << "Reporte de solicitudes generado: reporte_solicitudes.png ";
}

void ListaSolicitudes::poblarTablaAdmin(QTableWidget* tabla) {
    tabla->setRowCount(0);
    if (primero == nullptr) return;

    NodoSolicitud* actual = primero;
    int fila = 0;
    do {
        tabla->insertRow(fila);
        tabla->setItem(fila, 0, new QTableWidgetItem(QString::number(actual->solicitud.id)));
        tabla->setItem(fila, 1, new QTableWidgetItem(actual->solicitud.cliente));
        tabla->setItem(fila, 2, new QTableWidgetItem(actual->solicitud.telefono));
        tabla->setItem(fila, 3, new QTableWidgetItem(actual->solicitud.tipo));
        tabla->setItem(fila, 4, new QTableWidgetItem(actual->solicitud.estado));

        fila++;
        actual = actual->siguiente;
    } while (actual != primero);
}

// Busca la primera que diga "Pendiente"
NodoSolicitud* ListaSolicitudes::getPrimeraPendiente() {
    if (primero == nullptr) return nullptr;
    NodoSolicitud* actual = primero;
    do {
        if (actual->solicitud.estado == "Pendiente") return actual;
        actual = actual->siguiente;
    } while (actual != primero);
    return nullptr;
}

// Cambia el estado[cite: 1]
void ListaSolicitudes::marcarComoAtendida(int id) {
    if (primero == nullptr) return;
    NodoSolicitud* actual = primero;
    do {
        if (actual->solicitud.id == id) {
            actual->solicitud.estado = "Atendida";
            return;
        }
        actual = actual->siguiente;
    } while (actual != primero);
}

// Lógica de desenlazado de lista circular doble[cite: 1]
void ListaSolicitudes::eliminarSolicitud(int id) {
    if (primero == nullptr) return;

    NodoSolicitud* actual = primero;
    do {
        if (actual->solicitud.id == id) {
            // Si es el único nodo en la lista
            if (actual->siguiente == actual) {
                primero = nullptr;
                ultimo = nullptr;
            } else {
                // Desenlazamos el nodo conectando a sus vecinos
                actual->anterior->siguiente = actual->siguiente;
                actual->siguiente->anterior = actual->anterior;

                // Si borramos el primero o el último, hay que mover los punteros
                if (actual == primero) primero = actual->siguiente;
                if (actual == ultimo) ultimo = actual->anterior;
            }
            delete actual; // ¡Liberar memoria!
            return;
        }
        actual = actual->siguiente;
    } while (actual != primero && primero != nullptr);
}

// --- 1. ESTADO "EN PROCESO" (Administrador) ---
void ListaSolicitudes::marcarComoEnProceso(int id) {
    if (primero == nullptr) return;
    NodoSolicitud* actual = primero;
    do {
        if (actual->solicitud.id == id) {
            actual->solicitud.estado = "En Proceso";
            return;
        }
        actual = actual->siguiente;
    } while (actual != primero);
}

// --- 2. BÚSQUEDA DE ESTADO (Cliente)[cite: 1] ---
QString ListaSolicitudes::buscarEstadoPorTelefono(QString telefono) {
    if (primero == nullptr) return "No hay solicitudes en el sistema.";

    QString resultados = "";
    NodoSolicitud* actual = primero;

    // Recorremos la lista circular buscando todas las quejas de este teléfono
    do {
        if (actual->solicitud.telefono == telefono) {
            resultados += "🔖 Tipo: " + actual->solicitud.tipo + "\n" +
                          "📝 Descripción: " + actual->solicitud.descripcion + "\n" +
                          "⚙️ Estado: " + actual->solicitud.estado + "\n" +
                          "-----------------------------\n";
        }
        actual = actual->siguiente;
    } while (actual != primero);

    if (resultados.isEmpty()) return "No se encontraron solicitudes asociadas al teléfono: " + telefono;

    return resultados;
}





























