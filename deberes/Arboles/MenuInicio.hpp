#ifndef MENUINICIO_HPP
#define MENUINICIO_HPP
#include <iostream>
#include <conio.h>
#include <windows.h>

class MenuInicio {
private:
    int opcionSeleccionada;
    
    void limpiarPantalla();
    void mostrarMenu();
    void pausar();
    
public:
    MenuInicio();
    int iniciar();
};

#endif
