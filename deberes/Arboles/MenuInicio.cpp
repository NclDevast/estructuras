#include "MenuInicio.hpp"

MenuInicio::MenuInicio() {
    opcionSeleccionada = 0;
}

void MenuInicio::limpiarPantalla() {
    system("cls");
}

void MenuInicio::pausar() {
    std::cout << "\nPresione cualquier tecla para continuar..." << std::endl;
    _getch();
}

void MenuInicio::mostrarMenu() {
    limpiarPantalla();
    std::cout << "--------------------------------------------" << std::endl;
    std::cout << "|         SELECCIONE TIPO DE ÁRBOL          |" << std::endl;
    std::cout << "--------------------------------------------" << std::endl;
    std::cout << std::endl;
    
    const char* opciones[] = {
        "1. ABB (Árbol Binario de Búsqueda)",
        "2. AVL (Árbol Balanceado Automáticamente)",
        "3. Salir"
    };
    
    for(int i = 0; i < 3; i++) {
        if(i == opcionSeleccionada) {
            std::cout << ">> " << opciones[i] << " <<" << std::endl;
        } else {
            std::cout << "   " << opciones[i] << std::endl;
        }
    }
    
    std::cout << std::endl << "Use FLECHAS para navegar, ENTER para seleccionar" << std::endl;
}

int MenuInicio::iniciar() {
    bool seleccionado = false;
    
    while(!seleccionado) {
        mostrarMenu();
        
        int tecla = _getch();
        
        if(tecla == 224) { // Tecla especial (flecha)
            tecla = _getch();
            if(tecla == 72) { // Flecha arriba
                opcionSeleccionada = (opcionSeleccionada - 1 + 3) % 3;
            } else if(tecla == 80) { // Flecha abajo
                opcionSeleccionada = (opcionSeleccionada + 1) % 3;
            }
        } else if(tecla == 13) { // Enter
            seleccionado = true;
            
            if(opcionSeleccionada == 2) {
                limpiarPantalla();
                std::cout << "--------------------------------------------" << std::endl;
                std::cout << "|          ¡Hasta luego! Programa finalizado|" << std::endl;
                std::cout << "--------------------------------------------" << std::endl;
                exit(0);
            }
            
            return opcionSeleccionada;
        }
    }
    
    return 0;
}
