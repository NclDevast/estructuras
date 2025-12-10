#ifndef MENUAVL_HPP
#define MENUAVL_HPP
#include <iostream>
#include <conio.h>
#include <windows.h>
#include "MenuArbol.hpp"
#include "AVL/AVL.HPP"

class MenuAVL : public MenuArbol {
private:
    AVL<int> arbol;
    
    // Funciones auxiliares
    void mostrarMenu();
    void ejecutarOpcion(int opcion);
    void ingresarDatos();
    void buscarDato();
    void mostrarRecorridos();
    void mostrarRecorridoMenu();
    void mostrarArbol();
    void dibujarArbol(Nodo<int>* nodo, int espacio, int altura);
    int calcularAltura(Nodo<int>* nodo);
    void limpiarPantalla();
    void pausar();
    
public:
    MenuAVL();
    void iniciar() override;
};

#endif
