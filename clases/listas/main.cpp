#include <iostream>
#include "./modelo/Lista/lista.cpp"
#include "./modelo/Nodo/nodo.cpp" 
#include "./Vista/menu/menu.cpp"
#ifdef _WIN32
#include <windows.h>
#endif

int main() {
    #ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8); 
    SetConsoleCP(CP_UTF8);      
    #endif
    ListaEnlazada list;
    ListaEnlazada* lista=&list;
    Menu menu(lista);
    menu.mostrarMenu();

    std::cout << "Presiona ENTER para salir...";
    std::cin.get();
    return 0;
}