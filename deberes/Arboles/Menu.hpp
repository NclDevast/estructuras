#ifndef MENU_HPP
#define MENU_HPP
#include <iostream>
#include <conio.h>
#include <windows.h>
#include "ABB/ABB.hpp"

class Menu {
private:
    ABB<int> arbol;
    int opcionSeleccionada;
    
    // Funciones auxiliares
    void limpiarPantalla();
    void mostrarMenu();
    void ejecutarOpcion(int opcion);
    void ingresarDatos();
    void buscarDato();
    void mostrarRecorridos();
    void mostrarRecorridoMenu();
    void pausar();
    
public:
    Menu();
    void iniciar();
};

#endif
