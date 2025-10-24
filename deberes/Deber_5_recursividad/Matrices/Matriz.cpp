#include "../../PruebaInterfaces/modelo/Matriz.hpp"
#include <iostream>
#include <stdexcept>
#include <cstring>
#include <string>
#include <limits>



class DimensionesInvalidasExcepcion : public std::runtime_error {
public:
    DimensionesInvalidasExcepcion(const std::string& mensaje) 
        : std::runtime_error(mensaje) {}
};

template<typename T>
void asignarMatriz(T** &Matriz, int filas, int columnas) {
    Matriz = new T*[filas];
    for(int i = 0; i < filas; i++) {
        Matriz[i] = new T[columnas];
    }
}

template<typename T>
void asignarMatriz(T*** &Matriz, int filas, int columnas, int z) {
    Matriz = new T**[filas];
    for(int i = 0; i < filas; i++) {
        Matriz[i] = new T*[columnas];
        for(int j = 0; j < columnas; j++) {
            Matriz[i][j] = new T[z];
        }
    }
}

template<typename T>
void encerar(T** Matriz, int filas, int columnas) {
    for(int i = 0; i < filas; i++) {
        for(int j = 0; j < columnas; j++) {
            Matriz[i][j] = 0;
        }
    }
}

template<typename T>
void encerar(T*** Matriz, int filas, int columnas, int z) {
    for(int i = 0; i < filas; i++) {
        for(int j = 0; j < columnas; j++) {
            for(int k = 0; k < z; k++) {
                Matriz[i][j][k] = 0;
            }
        }
    }
}

template<typename T>
T** sumarMatriz(T** MatrizA, T** MatrizB, int filas, int columnas) {
    T** MatrizResultado;
    asignarMatriz(MatrizResultado, filas, columnas);
    for(int i = 0; i < filas; i++) {
        for(int j = 0; j < columnas; j++) {
            MatrizResultado[i][j] = MatrizA[i][j] + MatrizB[i][j];
        }
    }
    return MatrizResultado;
}

template<typename T>
T*** sumarMatriz(T*** MatrizA, T*** MatrizB, int filas, int columnas, int z) {
    T*** MatrizResultado;
    asignarMatriz(MatrizResultado, filas, columnas, z);
    for(int i = 0; i < filas; i++) {
        for(int j = 0; j < columnas; j++) {
            for(int k = 0; k < z; k++) {
                MatrizResultado[i][j][k] = MatrizA[i][j][k] + MatrizB[i][j][k];
            }
        }
    }
    return MatrizResultado;
}

template<typename T>
T** restarMatriz(T** MatrizA, T** MatrizB, int filas, int columnas) {
    T** MatrizResultado;
    asignarMatriz(MatrizResultado, filas, columnas);
    for(int i = 0; i < filas; i++) {
        for(int j = 0; j < columnas; j++) {
            MatrizResultado[i][j] = MatrizA[i][j] - MatrizB[i][j];
        }
    }
    return MatrizResultado;
}

template<typename T>
T*** restarMatriz(T*** MatrizA, T*** MatrizB, int filas, int columnas, int Z) {
    T*** MatrizResultado;
    asignarMatriz(MatrizResultado, filas, columnas, Z);
    for(int i = 0; i < filas; i++) {
        for(int j = 0; j < columnas; j++) {
            for(int k = 0; k < Z; k++) {
                MatrizResultado[i][j][k] = MatrizA[i][j][k] - MatrizB[i][j][k];
            }
        }
    }
    return MatrizResultado;
}

template<typename T>
T** multiplicarMatriz(T** MatrizA, T** MatrizB, int filas, int columnas, int filasB, int columnasB) {
    if(columnas != filasB) {
        throw DimensionesInvalidasExcepcion("El # de columnas de la matriz A debe ser igual al # de filas de B");
    }
    
    T** MatrizResultado;
    asignarMatriz(MatrizResultado, filas, columnasB);
    encerar(MatrizResultado, filas, columnasB);
    
    for(int i = 0; i < filas; i++) {
        for(int j = 0; j < columnasB; j++) {
            for(int k = 0; k < columnas; k++) {
                MatrizResultado[i][j] += MatrizA[i][k] * MatrizB[k][j];
            }
        }
    }
    return MatrizResultado;
}

template<typename T>
void ingresarItem(T** Matriz, int indexFila, int indexColumna, T valor) {
    Matriz[indexFila][indexColumna] = valor;
}

template<typename T>
void ingresarItem(T*** Matriz, int indexFila, int indexColumna, int indexZ, T valor) {
    Matriz[indexFila][indexColumna][indexZ] = valor;
}

template<typename T>
void imprimirMatriz(T** Matriz, int filas, int columnas) {
    for(int i = 0; i < filas; i++) {
        for(int j = 0; j < columnas; j++) {
            std::cout << Matriz[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

template<typename T>
void imprimirMatriz(T*** Matriz, int filas, int columnas, int z) {
    for(int k = 0; k < z; k++) {
        std::cout << "capa " << k + 1 << ":" << std::endl;
        for(int i = 0; i < filas; i++) {
            for(int j = 0; j < columnas; j++) {
                std::cout << Matriz[i][j][k] << " ";
            }
            std::cout << std::endl;
        }
    }
}

template<typename T>
void liberarMatriz(T** Matriz, int filas) {
    for(int i = 0; i < filas; i++) {
        delete[] Matriz[i];
    }
    delete[] Matriz;
}

template<typename T>
void liberarMatriz(T*** Matriz, int filas, int columnas) {
    for(int i = 0; i < filas; i++) {
        for(int j = 0; j < columnas; j++) {
            delete[] Matriz[i][j];
        }
        delete[] Matriz[i];
    }
    delete[] Matriz;
}
template<>
void asignarMatriz<char>(char** &Matriz, int filas, int columnas) {
    Matriz = new char*[filas];
    for(int i = 0; i < filas; i++) {
        Matriz[i] = new char[columnas + 1];  // +1 para el null
        Matriz[i][0] = '\0';  // Inicializar como cadena vacía
    }
}

void ingresarStringsEnMatriz(char** matriz, int filas, int columnas) {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    for(int i = 0; i < filas; i++) {
        std::cout << "Ingrese string para fila " << i << " (max " 
                  << (columnas - 1) << " chars): ";
        
        std::string input;
        std::getline(std::cin, input);
        
        // Truncar si es muy largo
        if(input.length() >= columnas) {
            std::cout << "¡Advertencia: String truncado a " 
                      << (columnas - 1) << " caracteres!\n";
        }
        
        strncpy(matriz[i], input.c_str(), columnas - 1);
        matriz[i][columnas - 1] = '\0';
    }
}