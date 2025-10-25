#ifndef MENU_H
#define MENU_H

#include "../modelo/Lista/lista.hpp"

class Menu {
private:
    ListaEnlazada lista;
public:
    void mostrarMenu();
    void insertarCabeza();
    void insertarCola();
    void eliminarCabeza();
    void buscarElemento();
    void imprimirLista();
    int obtenerEntero(const char* mensaje);
};

#endif 

