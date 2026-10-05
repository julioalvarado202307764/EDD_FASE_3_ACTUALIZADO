#ifndef TRANSACCION_H
#define TRANSACCION_H

#include <string>

class Transaccion {
public:
    std::string codigo_transaccion;
    std::string codigo_reserva;
    std::string id_cliente;
    std::string codigo_funcion;

    int fila;
    int columna;

    /*
     * Decimal canónico almacenado como texto.
     *
     * Ejemplos equivalentes:
     * 100, 100.0, 100.00 -> "100"
     *
     * Esto evita depender de representación binaria de double
     * y no impone todavía una escala monetaria arbitraria.
     */
    std::string monto;

    std::string metodo_pago;
    std::string fecha_pago;


    Transaccion();

    Transaccion(
        const std::string& codigoTransaccion,
        const std::string& codigoReserva,
        const std::string& idCliente,
        const std::string& codigoFuncion,
        int fila,
        int columna,
        const std::string& monto,
        const std::string& metodoPago,
        const std::string& fechaPago
        );


    /*
     * Normalización decimal independiente del locale.
     * Utiliza "." como separador y no admite signo,
     * coma regional ni separadores de miles.
     */
    static std::string normalizarMonto(
        const std::string& valor
        );


    /*
     * Serialización canónica:
     *
     * - orden fijo de los 9 campos;
     * - cada campo se representa como longitud:valor;
     * - la longitud se mide en BYTES;
     * - las cadenas textuales deben llegar codificadas en UTF-8.
     */
    std::string serializarCanonica() const;


    /*
     * El hash no se almacena como estado duplicado.
     * Siempre se deriva de la serialización canónica.
     */
    std::string calcularHash() const;
};

#endif // TRANSACCION_H