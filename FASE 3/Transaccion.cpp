#include "Transaccion.h"
#include "SHA256.h"

#include <stdexcept>


namespace {

void agregarCampoCanonico(
    std::string& salida,
    const std::string& valor)
{
    /*
     * La longitud se mide sobre std::string::size(),
     * es decir, cantidad de bytes.
     *
     * Para UTF-8 esto es exactamente lo que necesitamos.
     */
    salida +=
        std::to_string(
            valor.size()
            );

    salida += ':';
    salida += valor;
}

} // namespace


Transaccion::Transaccion()
    : fila(0),
    columna(0),
    monto("0")
{
}


Transaccion::Transaccion(
    const std::string& codigoTransaccion,
    const std::string& codigoReserva,
    const std::string& idCliente,
    const std::string& codigoFuncion,
    int fila,
    int columna,
    const std::string& valorMonto,
    const std::string& metodoPago,
    const std::string& fechaPago)
    : codigo_transaccion(
          codigoTransaccion
          ),
    codigo_reserva(
        codigoReserva
        ),
    id_cliente(
        idCliente
        ),
    codigo_funcion(
        codigoFuncion
        ),
    fila(fila),
    columna(columna),
    monto(
        normalizarMonto(
            valorMonto
            )
        ),
    metodo_pago(
        metodoPago
        ),
    fecha_pago(
        fechaPago
        )
{
}


std::string Transaccion::normalizarMonto(
    const std::string& valor)
{
    if (valor.empty()) {

        throw std::invalid_argument(
            "El monto no puede estar vacio."
            );
    }


    std::size_t punto =
        std::string::npos;


    // =========================================================
    // VALIDAR SINTAXIS
    // =========================================================

    for (std::size_t i = 0;
         i < valor.size();
         ++i) {

        const char c =
            valor[i];


        if (c == '.') {

            if (punto !=
                std::string::npos) {

                throw std::invalid_argument(
                    "El monto contiene mas de un punto decimal."
                    );
            }

            punto = i;

            continue;
        }


        if (c < '0' ||
            c > '9') {

            throw std::invalid_argument(
                "El monto debe usar solo digitos y punto decimal."
                );
        }
    }


    // =========================================================
    // DIVIDIR PARTE ENTERA Y DECIMAL
    // =========================================================

    const std::string parteEnteraOriginal =
        punto ==
                std::string::npos
            ? valor
            : valor.substr(
                  0,
                  punto
                  );


    const std::string parteDecimalOriginal =
        punto ==
                std::string::npos
            ? std::string()
            : valor.substr(
                  punto + 1u
                  );


    if (parteEnteraOriginal.empty()) {

        throw std::invalid_argument(
            "El monto debe tener parte entera."
            );
    }


    if (punto !=
            std::string::npos &&
        parteDecimalOriginal.empty()) {

        throw std::invalid_argument(
            "El monto debe tener digitos despues del punto decimal."
            );
    }


    // =========================================================
    // ELIMINAR CEROS INNECESARIOS DE LA PARTE ENTERA
    // =========================================================

    std::size_t primerNoCero =
        parteEnteraOriginal
            .find_first_not_of('0');


    std::string parteEntera =
        primerNoCero ==
                std::string::npos
            ? "0"
            : parteEnteraOriginal
                  .substr(
                      primerNoCero
                      );


    // =========================================================
    // ELIMINAR CEROS FINALES DE LA PARTE DECIMAL
    // =========================================================

    std::string parteDecimal =
        parteDecimalOriginal;


    while (!parteDecimal.empty() &&
           parteDecimal.back() ==
               '0') {

        parteDecimal.pop_back();
    }


    if (parteDecimal.empty()) {
        return parteEntera;
    }


    return
        parteEntera +
        "." +
        parteDecimal;
}


std::string
Transaccion::serializarCanonica() const
{
    std::string salida;


    /*
     * ORDEN CANÓNICO FIJO:
     *
     * 1. codigo_transaccion
     * 2. codigo_reserva
     * 3. id_cliente
     * 4. codigo_funcion
     * 5. fila
     * 6. columna
     * 7. monto
     * 8. metodo_pago
     * 9. fecha_pago
     *
     * Cada campo utiliza longitud:valor.
     */


    agregarCampoCanonico(
        salida,
        codigo_transaccion
        );

    agregarCampoCanonico(
        salida,
        codigo_reserva
        );

    agregarCampoCanonico(
        salida,
        id_cliente
        );

    agregarCampoCanonico(
        salida,
        codigo_funcion
        );

    agregarCampoCanonico(
        salida,
        std::to_string(
            fila
            )
        );

    agregarCampoCanonico(
        salida,
        std::to_string(
            columna
            )
        );

    /*
     * Se normaliza nuevamente por seguridad.
     *
     * Aunque el constructor ya normaliza, los campos son
     * públicos para mantener el estilo del proyecto y podrían
     * modificarse posteriormente.
     */
    agregarCampoCanonico(
        salida,
        normalizarMonto(
            monto
            )
        );

    agregarCampoCanonico(
        salida,
        metodo_pago
        );

    agregarCampoCanonico(
        salida,
        fecha_pago
        );


    return salida;
}


std::string Transaccion::calcularHash() const
{
    return SHA256::hash(
        serializarCanonica()
        );
}