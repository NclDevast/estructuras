#include "vista.h"

void Vista::mostrarMenu() {
    std::cout << "\n=== Operaciones con Matrices ===\n";
    std::cout << "1. Ingresar matriz\n";
    std::cout << "2. Multiplicar matrices\n";
    std::cout << "3. Mostrar matriz\n";
    std::cout << "0. Salir\n";
    std::cout << "Elija una opción: ";
}

int Vista::menu() {
    int opcion;
    mostrarMenu();
    std::cin >> opcion;
    return opcion;
}

Matriz Vista::ingresarMatriz(const std::string& nombreMatriz) {
    int filas, columnas;
    
    std::cout << "\nIngresando " << nombreMatriz << "\n";
    std::cout << "Ingrese número de filas: ";
    std::cin >> filas;
    std::cout << "Ingrese número de columnas: ";
    std::cin >> columnas;
    
    Matriz matriz(filas, columnas);
    
    std::cout << "\nIngrese los elementos de la matriz:\n";
    for(int i = 0; i < filas; i++) {
        for(int j = 0; j < columnas; j++) {
            float valor;
            std::cout << "Elemento [" << i + 1 << "][" << j + 1 << "]: ";
            std::cin >> valor;
            matriz.ingresarDatos(i, j, valor);
        }
    }
    
    return matriz;
}

void Vista::mostrarMatriz(const Matriz& matriz, const std::string& titulo) {
    std::cout << "\n" << titulo << "\n";
    std::cout << "Dimensiones: " << matriz.getFilas() << "x" << matriz.getColumnas() << "\n\n";
    
    for(int i = 0; i < matriz.getFilas(); i++) {
        std::cout << "[ ";
        for(int j = 0; j < matriz.getColumnas(); j++) {
            std::cout << matriz.getMatriz()[i][j];
            if (j < matriz.getColumnas() - 1) {
                std::cout << "\t";
            }
        }
        std::cout << " ]\n";
    }
    std::cout << std::endl;
}

void Vista::mostrarMensaje(const std::string& mensaje) {
    std::cout << mensaje << std::endl;
}
