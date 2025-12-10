#include "MenuArbol.hpp"

MenuArbol::MenuArbol() {
    opcionSeleccionada = 0;
}

MenuArbol::~MenuArbol() {
}

void MenuArbol::limpiarPantalla() {
    system("cls");
}

void MenuArbol::pausar() {
    std::cout << "\nPresione cualquier tecla para continuar..." << std::endl;
    _getch();
}
