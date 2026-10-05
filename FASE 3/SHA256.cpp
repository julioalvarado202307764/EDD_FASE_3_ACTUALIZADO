#include "SHA256.h"

#include <cstdint>
#include <vector>

namespace {

constexpr std::uint32_t K[64] = {
    0x428a2f98u, 0x71374491u, 0xb5c0fbcfu, 0xe9b5dba5u,
    0x3956c25bu, 0x59f111f1u, 0x923f82a4u, 0xab1c5ed5u,
    0xd807aa98u, 0x12835b01u, 0x243185beu, 0x550c7dc3u,
    0x72be5d74u, 0x80deb1feu, 0x9bdc06a7u, 0xc19bf174u,
    0xe49b69c1u, 0xefbe4786u, 0x0fc19dc6u, 0x240ca1ccu,
    0x2de92c6fu, 0x4a7484aau, 0x5cb0a9dcu, 0x76f988dau,
    0x983e5152u, 0xa831c66du, 0xb00327c8u, 0xbf597fc7u,
    0xc6e00bf3u, 0xd5a79147u, 0x06ca6351u, 0x14292967u,
    0x27b70a85u, 0x2e1b2138u, 0x4d2c6dfcu, 0x53380d13u,
    0x650a7354u, 0x766a0abbu, 0x81c2c92eu, 0x92722c85u,
    0xa2bfe8a1u, 0xa81a664bu, 0xc24b8b70u, 0xc76c51a3u,
    0xd192e819u, 0xd6990624u, 0xf40e3585u, 0x106aa070u,
    0x19a4c116u, 0x1e376c08u, 0x2748774cu, 0x34b0bcb5u,
    0x391c0cb3u, 0x4ed8aa4au, 0x5b9cca4fu, 0x682e6ff3u,
    0x748f82eeu, 0x78a5636fu, 0x84c87814u, 0x8cc70208u,
    0x90befffau, 0xa4506cebu, 0xbef9a3f7u, 0xc67178f2u
};

inline std::uint32_t rotarDerecha(std::uint32_t valor,
                                  std::uint32_t bits)
{
    return (valor >> bits) |
           (valor << (32u - bits));
}

inline std::uint32_t elegir(std::uint32_t x,
                            std::uint32_t y,
                            std::uint32_t z)
{
    return (x & y) ^
           (~x & z);
}

inline std::uint32_t mayoria(std::uint32_t x,
                             std::uint32_t y,
                             std::uint32_t z)
{
    return (x & y) ^
           (x & z) ^
           (y & z);
}

inline std::uint32_t sigmaGrande0(std::uint32_t x)
{
    return rotarDerecha(x, 2u) ^
           rotarDerecha(x, 13u) ^
           rotarDerecha(x, 22u);
}

inline std::uint32_t sigmaGrande1(std::uint32_t x)
{
    return rotarDerecha(x, 6u) ^
           rotarDerecha(x, 11u) ^
           rotarDerecha(x, 25u);
}

inline std::uint32_t sigmaPequena0(std::uint32_t x)
{
    return rotarDerecha(x, 7u) ^
           rotarDerecha(x, 18u) ^
           (x >> 3u);
}

inline std::uint32_t sigmaPequena1(std::uint32_t x)
{
    return rotarDerecha(x, 17u) ^
           rotarDerecha(x, 19u) ^
           (x >> 10u);
}

} // namespace


std::string SHA256::hash(const std::string& mensaje)
{
    // =========================================================
    // 1. MENSAJE ORIGINAL COMO SECUENCIA EXACTA DE BYTES
    // =========================================================

    std::vector<std::uint8_t> bytes;

    bytes.reserve(
        mensaje.size() + 72u
        );

    for (unsigned char byte : mensaje) {
        bytes.push_back(
            static_cast<std::uint8_t>(
                byte
                )
            );
    }


    // Longitud ORIGINAL del mensaje, expresada en bits.
    const std::uint64_t longitudBits =
        static_cast<std::uint64_t>(
            bytes.size()
            ) * 8u;


    // =========================================================
    // 2. PADDING
    // =========================================================

    // Agregar el bit 1 seguido de siete ceros.
    bytes.push_back(0x80u);

    // Completar con ceros hasta quedar en 56 bytes módulo 64.
    while ((bytes.size() % 64u) != 56u) {
        bytes.push_back(0x00u);
    }


    // =========================================================
    // 3. LONGITUD ORIGINAL EN 64 BITS, BIG-ENDIAN
    // =========================================================

    for (int desplazamiento = 56;
         desplazamiento >= 0;
         desplazamiento -= 8) {

        bytes.push_back(
            static_cast<std::uint8_t>(
                (longitudBits >>
                 desplazamiento) &
                0xffu
                )
            );
    }


    // =========================================================
    // 4. ESTADO INICIAL SHA-256
    // =========================================================

    std::uint32_t h0 = 0x6a09e667u;
    std::uint32_t h1 = 0xbb67ae85u;
    std::uint32_t h2 = 0x3c6ef372u;
    std::uint32_t h3 = 0xa54ff53au;
    std::uint32_t h4 = 0x510e527fu;
    std::uint32_t h5 = 0x9b05688cu;
    std::uint32_t h6 = 0x1f83d9abu;
    std::uint32_t h7 = 0x5be0cd19u;


    // =========================================================
    // 5. PROCESAR BLOQUES DE 512 BITS
    // =========================================================

    for (std::size_t inicioBloque = 0;
         inicioBloque < bytes.size();
         inicioBloque += 64u) {

        std::uint32_t w[64] = {};


        // Primeras 16 palabras: directamente desde el bloque.
        for (int i = 0; i < 16; ++i) {

            const std::size_t base =
                inicioBloque +
                static_cast<std::size_t>(i) * 4u;

            w[i] =
                (static_cast<std::uint32_t>(
                     bytes[base]
                     ) << 24u) |

                (static_cast<std::uint32_t>(
                     bytes[base + 1u]
                     ) << 16u) |

                (static_cast<std::uint32_t>(
                     bytes[base + 2u]
                     ) << 8u) |

                static_cast<std::uint32_t>(
                    bytes[base + 3u]
                    );
        }


        // Extender message schedule hasta w[63].
        for (int i = 16; i < 64; ++i) {

            w[i] =
                sigmaPequena1(w[i - 2]) +
                w[i - 7] +
                sigmaPequena0(w[i - 15]) +
                w[i - 16];
        }


        std::uint32_t a = h0;
        std::uint32_t b = h1;
        std::uint32_t c = h2;
        std::uint32_t d = h3;
        std::uint32_t e = h4;
        std::uint32_t f = h5;
        std::uint32_t g = h6;
        std::uint32_t h = h7;


        // =====================================================
        // 6. 64 RONDAS DE COMPRESIÓN
        // =====================================================

        for (int i = 0; i < 64; ++i) {

            const std::uint32_t temporal1 =
                h +
                sigmaGrande1(e) +
                elegir(e, f, g) +
                K[i] +
                w[i];

            const std::uint32_t temporal2 =
                sigmaGrande0(a) +
                mayoria(a, b, c);


            h = g;
            g = f;
            f = e;
            e = d + temporal1;
            d = c;
            c = b;
            b = a;
            a = temporal1 + temporal2;
        }


        // =====================================================
        // 7. ACUMULAR ESTADO
        // =====================================================

        h0 += a;
        h1 += b;
        h2 += c;
        h3 += d;
        h4 += e;
        h5 += f;
        h6 += g;
        h7 += h;
    }


    // =========================================================
    // 8. HEXADECIMAL DE 64 CARACTERES
    // =========================================================

    const std::uint32_t estado[8] = {
        h0, h1, h2, h3,
        h4, h5, h6, h7
    };

    static const char* HEX =
        "0123456789abcdef";

    std::string resultado;

    resultado.reserve(64u);


    for (std::uint32_t palabra : estado) {

        for (int desplazamiento = 28;
             desplazamiento >= 0;
             desplazamiento -= 4) {

            resultado.push_back(
                HEX[
                    (palabra >>
                     desplazamiento) &
                    0x0fu
            ]
                );
        }
    }


    return resultado;
}