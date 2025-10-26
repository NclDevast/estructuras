#include <iostream>
#include "./modelo/Lista/lista.hpp"
#include "./modelo/Nodo/nodo.hpp" 
#include "./Vista/menu/menu.h"
#ifdef _WIN32
#include <windows.h>
#endif

int main() {
    #ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8); 
    SetConsoleCP(CP_UTF8);      
    #endif

    Menu menu;
    menu.mostrarMenu();

    std::cout << "Presiona ENTER para salir...";
    std::cin.get();
    return 0;
}