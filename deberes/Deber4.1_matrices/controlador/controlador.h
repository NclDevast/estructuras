#ifndef CONTROLADOR_H
#define CONTROLADOR_H

#include "../matriz.h"
#include "../vista/vista.h"

class Controlador {
private:
    Vista vista;
    Matriz* matrizA;
    Matriz* matrizB;
    
public:
    Controlador();
    ~Controlador();
    
    void iniciar();
    void multiplicarMatrices();
    void editarMatriz();
};

#endif // CONTROLADOR_H