#ifndef VISTA_H
#define VISTA_H

#include <iostream>
#include "matriz.h"

class Vista {
private:
    void mostrarMenu();
    
public:
    Vista() = default;
    ~Vista() = default;
    
    int menu();
    Matriz ingresarMatriz(const std::string& nombreMatriz);
    void mostrarMatriz(const Matriz& matriz, const std::string& titulo);
    void mostrarMensaje(const std::string& mensaje);
};

#endif // VISTA_H