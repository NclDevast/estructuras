#include <iostream>
#include <functional>

int main() {
    // Declarar las matrices usando punteros
    int** matriz1 = new int*[3];
    int** matriz2 = new int*[3];
    int** resultado = new int*[3];
    
    // Inicializar las matrices
    for(int i = 0; i < 3; i++) {
        matriz1[i] = new int[3];
        matriz2[i] = new int[3];
        resultado[i] = new int[3];
    }
    
    // Llenar la primera matriz
    std::cout << "Ingrese los elementos de la primera matriz 3x3:\n";
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            std::cout << "matriz1[" << i << "][" << j << "]: ";
            std::cin >> matriz1[i][j];
        }
    }
    
    // Llenar la segunda matriz
    std::cout << "\nIngrese los elementos de la segunda matriz 3x3:\n";
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            std::cout << "matriz2[" << i << "][" << j << "]: ";
            std::cin >> matriz2[i][j];
        }
    }
    
    // Definir la función lambda para sumar las matrices
    auto sumarMatrices = [](int** m1, int** m2, int** res, int filas, int cols) {
        for(int i = 0; i < filas; i++) {
            for(int j = 0; j < cols; j++) {
                res[i][j] = m1[i][j] + m2[i][j];
            }
        }
    };
    
    // Usar la función lambda para sumar las matrices
    sumarMatrices(matriz1, matriz2, resultado, 3, 3);
    
    // Mostrar el resultado
    std::cout << "\nResultado de la suma:\n";
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            std::cout << resultado[i][j] << "\t";
        }
        std::cout << "\n";
    }
    
    // Liberar memoria
    for(int i = 0; i < 3; i++) {
        delete[] matriz1[i];
        delete[] matriz2[i];
        delete[] resultado[i];
    }
    delete[] matriz1;
    delete[] matriz2;
    delete[] resultado;
    
    return 0;
}
