#ifndef SOLICITUD_H
#define SOLICITUD_H

#include <QString>

class Solicitud {
public:
    int id; // Este será el número autogenerado[cite: 1]
    QString cliente;
    QString telefono;
    QString tipo; // Cumpleaños, aniversario, queja, etc.[cite: 1]
    QString descripcion;
    QString fecha;
    QString estado;

    Solicitud() {}

    Solicitud(int _id, QString _cliente, QString _telefono, QString _tipo, QString _desc, QString _fecha) {
        id = _id;
        cliente = _cliente;
        telefono = _telefono;
        tipo = _tipo;
        descripcion = _desc;
        fecha = _fecha;
        estado = "Pendiente"; // Toda solicitud nueva entra como Pendiente[cite: 1]
    }
};

#endif // SOLICITUD_H