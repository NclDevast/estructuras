#ifndef VISTA_H
#define VISTA_H

#include <iostream>
#include "Matriz.hpp"
#include "Fraccion.hpp"

class Vista {
public:
    Vista() = default;
    ~Vista() = default;
    
    int mostrarMenu();
    void ingresarMatriz(Fraccion** matriz, const std::string& nombreMatriz);
    void mostrarMatriz(Fraccion** matriz, const std::string& titulo);
    void mostrarError(const std::string& mensaje);
private:
    void mostrarMenuOperaciones();
};

#endif