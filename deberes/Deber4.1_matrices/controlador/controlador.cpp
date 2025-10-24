#include "../../PruebaInterfaces/controlador.h"

Controlador::Controlador() : matrizA(nullptr), matrizB(nullptr) {}

Controlador::~Controlador() {
    delete matrizA;
    delete matrizB;
}

void Controlador::iniciar() {
    int opcion;
    do {
        opcion = vista.menu();
        
        switch(opcion) {
            case 1:
                multiplicarMatrices();
                break;
            case 2:
                editarMatriz();
                break;
            case 0:
                vista.mostrarMensaje("\n¡Hasta luego!");
                break;
            default:
                vista.mostrarMensaje("\nOpción inválida. Intente nuevamente.");
        }
        
    } while (opcion != 0);
}

void Controlador::multiplicarMatrices() {
    matrizA = new Matriz(vista.ingresarMatriz("Matriz A"));
    vista.mostrarMatriz(*matrizA, "Matriz A ingresada:");
    
    matrizB = new Matriz(vista.ingresarMatriz("Matriz B"));
    vista.mostrarMatriz(*matrizB, "Matriz B ingresada:");
    
    if(matrizA->getColumnas() != matrizB->getFilas()) {
        vista.mostrarMensaje("\nError: Las dimensiones de las matrices no son compatibles para multiplicación.");
        return;
    }
    
    Matriz resultado = (*matrizA) * (*matrizB);
    vista.mostrarMatriz(resultado, "Resultado de la multiplicación:");
}

void Controlador::editarMatriz() {
    if(!matrizA) {
        vista.mostrarMensaje("\nNo hay matriz para editar. Primero debe crear una matriz.");
        return;
    }
    
    int filas, columnas;
    vista.mostrarMensaje("\nIngrese las nuevas dimensiones para la matriz:");
    std::cout << "Filas: ";
    std::cin >> filas;
    std::cout << "Columnas: ";
    std::cin >> columnas;
    
    matrizA->editarMatriz(filas, columnas);
    
    vista.mostrarMensaje("\nIngrese los nuevos valores:");
    for(int i = 0; i < filas; i++) {
        for(int j = 0; j < columnas; j++) {
            float valor;
            std::cout << "Elemento [" << i + 1 << "][" << j + 1 << "]: ";
            std::cin >> valor;
            matrizA->ingresarDatos(i, j, valor);
        }
    }
    
    vista.mostrarMatriz(*matrizA, "Matriz actualizada:");
}
