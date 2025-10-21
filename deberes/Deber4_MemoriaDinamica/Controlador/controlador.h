#ifndef CONTROLADOR_H
#define CONTROLADOR_H

#include "../Modelo/modelo.h"
#include "../Vista/vista.h"

class Controlador {
private:
    Vista vista;
    
public:
    Controlador() = default;
    ~Controlador() = default;
    
    void iniciar();
    Fraccion realizarOperacion(const Fraccion& f1, const Fraccion& f2, int opcion);
};

#endif // CONTROLADOR_H
