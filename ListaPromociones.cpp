#include "ListaPromociones.h"
#include <QFile>
#include <QTextStream>
#include <QProcess>
#include <QDebug>
#include <QTreeWidgetItem>

ListaPromociones::ListaPromociones() {
    primero = nullptr;
    ultimo = nullptr;
}

// Inserción en Lista Circular Simple
void ListaPromociones::agregarPromocion(QString codigo, QString nombre, QString vigencia, QString dias) {
    Promocion nueva(codigo, nombre, vigencia, dias);
    NodoPromocion* nuevoNodo = new NodoPromocion(nueva);

    if (primero == nullptr) {
        primero = nuevoNodo;
        ultimo = nuevoNodo;
        primero->siguiente = primero; // Apunta a sí mismo para cerrar el círculo
    } else {
        ultimo->siguiente = nuevoNodo;
        nuevoNodo->siguiente = primero; // Cierra el círculo
        ultimo = nuevoNodo;
    }
    qDebug() << "Promoción agregada:" << codigo;
}

// Buscar la promoción y meterle un beneficio a su sub-lista
void ListaPromociones::agregarBeneficioAPromo(QString codigoPromo, QString tipo, QString desc, QString valor) {
    if (primero == nullptr) return;

    NodoPromocion* actual = primero;
    do {
        if (actual->promocion.codigo == codigoPromo) {
            Beneficio b(tipo, desc, valor);
            actual->promocion.agregarBeneficio(b);
            qDebug() << "Beneficio agregado a" << codigoPromo;
            return;
        }
        actual = actual->siguiente;
    } while (actual != primero);

    qDebug() << "Error: Promoción no encontrada.";
}

// ----------------------------------------------------
// GENERACIÓN DEL REPORTE 3: LISTA CIRCULAR DE LISTAS[cite: 1]
// ----------------------------------------------------
void ListaPromociones::generarReporteDOT() {
    if (primero == nullptr) return;

    QFile archivo("reporte_promociones.dot");
    if (!archivo.open(QIODevice::WriteOnly | QIODevice::Text)) return;

    QTextStream stream(&archivo);
    stream << "digraph Promociones {\n";
    stream << "node [shape=box, style=\"rounded,filled\", fontname=\"Helvetica\"];\n";

    NodoPromocion* actualPromo = primero;

    // 1. Dibujar todas las Promociones y conectarlas en círculo
    do {
        // Nodos verdes claro para las promos
        stream << "promo_" << actualPromo->promocion.codigo
               << " [label=\"" << actualPromo->promocion.codigo
               << "\\n" << actualPromo->promocion.nombre
               << "\\nVigencia: " << actualPromo->promocion.vigencia
               << "\", fillcolor=\"#a2f0a2\"];\n";

        // Flecha simple al siguiente[cite: 1]
        stream << "promo_" << actualPromo->promocion.codigo << " -> promo_"
               << actualPromo->siguiente->promocion.codigo << ";\n";

        // 2. Dibujar la sub-lista de beneficios colgando de esta promo
        NodoBeneficio* actualBen = actualPromo->promocion.primeroBeneficio;
        if (actualBen != nullptr) {
            // Unimos la promo con su primer beneficio (línea punteada para diferenciar)
            stream << "promo_" << actualPromo->promocion.codigo << " -> ben_"
                   << actualPromo->promocion.codigo << "_0 [style=dashed];\n";

            int i = 0;
            while (actualBen != nullptr) {
                // Nodos amarillos para los beneficios
                stream << "ben_" << actualPromo->promocion.codigo << "_" << i
                       << " [label=\"Tipo: " << actualBen->beneficio.tipo
                       << "\\nDesc: " << actualBen->beneficio.descripcion
                       << "\\nValor: " << actualBen->beneficio.valor
                       << "\", fillcolor=\"#ffffcc\"];\n";

                // Si hay un siguiente, conectamos con flecha doble (dir=both)[cite: 1]
                if (actualBen->siguiente != nullptr) {
                    stream << "ben_" << actualPromo->promocion.codigo << "_" << i
                           << " -> ben_" << actualPromo->promocion.codigo << "_" << (i+1) << " [dir=both];\n";
                } else {
                    // El último beneficio apunta a null[cite: 1]
                    stream << "null_" << actualPromo->promocion.codigo << "_" << i << " [label=\"null\", shape=plaintext, style=\"\"];\n";
                    stream << "ben_" << actualPromo->promocion.codigo << "_" << i << " -> null_" << actualPromo->promocion.codigo << "_" << i << ";\n";
                }

                actualBen = actualBen->siguiente;
                i++;
            }
        }

        actualPromo = actualPromo->siguiente;
    } while (actualPromo != primero);

    // Forzamos a que las promociones estén en la misma línea horizontal
    stream << "{ rank=same;";
    actualPromo = primero;
    do {
        stream << " promo_" << actualPromo->promocion.codigo << ";";
        actualPromo = actualPromo->siguiente;
    } while (actualPromo != primero);
    stream << " }\n";

    stream << "}\n";
    archivo.close();

    QProcess comando;
    comando.start("dot", QStringList() << "-Tpng" << "reporte_promociones.dot" << "-o" << "reporte_promociones.png");
    comando.waitForFinished();
    qDebug() << "Reporte de Promociones generado exitosamente 🔥";
}

void ListaPromociones::poblarArbolUI(QTreeWidget* arbol) {
    arbol->clear(); // Limpiamos visualmente antes de cargar
    if (primero == nullptr) return;

    NodoPromocion* actualPromo = primero;
    do {
        // 1. Crear el nodo padre (La Promoción)
        QTreeWidgetItem* itemPromo = new QTreeWidgetItem(arbol);
        QString textoPromo = actualPromo->promocion.codigo + " - " +
                             actualPromo->promocion.nombre +
                             " (Válido: " + actualPromo->promocion.diasAplicables + ")";
        itemPromo->setText(0, textoPromo);

        // Ponemos un colorcito de fondo para diferenciar la promo de los beneficios
        itemPromo->setBackground(0, QColor("#a2f0a2"));

        // 2. Recorrer la sub-lista doble de beneficios de esta promoción
        NodoBeneficio* actualBen = actualPromo->promocion.primeroBeneficio;
        while (actualBen != nullptr) {
            // Crear el nodo hijo apuntando al padre (itemPromo)
            QTreeWidgetItem* itemBen = new QTreeWidgetItem(itemPromo);
            QString textoBen = "⭐ Beneficio: " + actualBen->beneficio.tipo +
                               " | " + actualBen->beneficio.descripcion +
                               " | Valor: " + actualBen->beneficio.valor;
            itemBen->setText(0, textoBen);

            actualBen = actualBen->siguiente;
        }

        actualPromo = actualPromo->siguiente;
    } while (actualPromo != primero);

    // Expandimos todos los nodos para que el usuario los vea abiertos por defecto
    arbol->expandAll();
}
