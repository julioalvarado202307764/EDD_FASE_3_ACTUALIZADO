#ifndef SHA256_H
#define SHA256_H

#include <string>

class SHA256 {
public:
    // Calcula SHA-256 sobre los bytes exactos contenidos en std::string.
    static std::string hash(const std::string& mensaje);
};

#endif // SHA256_H