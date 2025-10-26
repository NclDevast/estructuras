#ifndef MENU_HPP
#define MENU_HPP

#include "../../modelo/Lista/lista.hpp"

class Menu {
private:
    ListaEnlazada lista;
public:
    Menu(ListaEnlazada);
    void mostrarMenu();
    void insertarCabeza();
    void insertarCola();
    void eliminarCabeza();
    void buscarElemento();
    void imprimirLista();
    int obtenerEntero(const char* mensaje);
};

#endif 

