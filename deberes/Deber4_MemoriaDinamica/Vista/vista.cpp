#include "vista.h"

void Vista::mostrarMenu() {
    std::cout << "\n=== Calculadora de Fracciones ===\n";
    std::cout << "1. Sumar fracciones\n";
    std::cout << "2. Restar fracciones\n";
    std::cout << "3. Multiplicar fracciones\n";
    std::cout << "4. Dividir fracciones\n";
    std::cout << "0. Salir\n";
    std::cout << "Elija una opción: ";
}

int Vista::menu() {
    int opcion;
    mostrarMenu();
    std::cin >> opcion;
    return opcion;
}

Fraccion Vista::ingresarFraccion() {
    float numerador, denominador;
    
    std::cout << "Ingrese el numerador: ";
    std::cin >> numerador;
    
    do {
        std::cout << "Ingrese el denominador (no puede ser 0): ";
        std::cin >> denominador;
        if (denominador == 0) {
            std::cout << "Error: El denominador no puede ser 0\n";
        }
    } while (denominador == 0);
    
    return Fraccion(numerador, denominador);
}

void Vista::mostrarResultado(const Fraccion& resultado, char operador) {
    std::cout << "\nResultado de la operación (" << operador << "): ";
    std::cout << resultado.getNumerador() << "/" << resultado.getDenominador() << std::endl;
}

void Vista::mostrarMensaje(const std::string& mensaje) {
    std::cout << mensaje << std::endl;
}