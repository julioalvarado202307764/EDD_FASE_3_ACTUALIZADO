#ifndef PELICULA_H
#define PELICULA_H

#include <QString>

class Pelicula {
public:
    QString codigo;
    QString titulo;
    QString genero;
    int duracion;
    QString clasificacion;
    QString idioma;
    QString fechaEstreno;
    QString fechaFin;

    // Constructor vacío
    Pelicula() {}

    // Constructor con parámetros
    Pelicula(QString cod, QString tit, QString gen, int dur, QString clasif, QString lang, QString fEstreno, QString fFin) {
        codigo = cod;
        titulo = tit;
        genero = gen;
        duracion = dur;
        clasificacion = clasif;
        idioma = lang;
        fechaEstreno = fEstreno;
        fechaFin = fFin;
    }
};

#endif // PELICULA_H