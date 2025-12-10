#ifndef MENUARBOL_HPP
#define MENUARBOL_HPP
#include <iostream>
#include <conio.h>
#include <windows.h>

class MenuArbol {
protected:
    int opcionSeleccionada;
    
    void limpiarPantalla();
    void pausar();
    
public:
    MenuArbol();
    virtual ~MenuArbol();
    virtual void iniciar() = 0;
};

#endif
