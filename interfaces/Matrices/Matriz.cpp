#include "Matriz.hpp"
#include <iostream>
#include <stdexcept>

template<typename T>
void asignarMatriz(T** Matriz, int filas, int columnas){
    Matriz = new T*[filas];
    for(int i=0;i<filas;i++){
        Matriz[i] = new T[columnas];
    }
}

template<typename T>
void asignarMatriz(T*** Matriz, int filas, int columnas, int z){
    Matriz = new T**[filas];
    for(int i = 0; i<filas;i++){
        Matriz[i]= new T*[columnas];
        for(int j=0;j<columnas;j++){
            Matriz[i][j]=new T[z];
        }
    }
}

template<typename T>
void encerar(T** Matriz, int filas, int columnas){
    for(int i =0; i<filas;i++){
        for(int j=0; j<columnas;j++){
            Matriz[i][j]=0;
        }
    }
}

template<typename T>
void encerar(T*** Matriz, int filas, int columnas, int z){
    for(int i=0; i<filas;i++){
        for(int j=0; j<columnas;j++){
            for(int k=0; k<z;k++){
                Matriz[i][j][k]=0;
            }
        }
    }
}

template<typename T>
T** sumarMatriz(T** MatrizA, T** MatrizB, int filas, int columnas){
    T** MatrizResultado = asignarMatriz(MatrizResultado, filas, columnas);
    for(int i=0; i<filas;i++){
        for(int j=0;j<columnas;j++){
            T[i][j]=MatrizA[i][j]+MatrizB[i][j];
        }
    }
    return MatrizResultado;
    
}

template<typename T>
T*** sumarMatriz(T*** MatrizA, T*** MatrizB, int filas, int columnas, int z){
    T*** MatrizResultado= asignarMatriz(MatrizResultado, filas, columnas, z);
    for(int i=0; i<filas;i++){
        for(int j=0;j<columnas;j++){
            for(int k=0;k<z;k++){
                T[i][j][k]=MatrizA[i][j][k]+MatrizB[i][j][k];
            }
        }
    }
    return MatrizResultado;
}
template<typename T>
T** restarMatriz(T** MatrizA, T** MatrizB, int filas, int columnas){
    T** MatrizResultado = asignarMatriz(MatrizResultado,filas, columnas);
    for(int i =0;i<filas;i++){
        for(int j=0;j<columnas;j++){
            MatrizResultado[i][j]=MatrizA[i][j]-MatrizB[i][j];
        }
    }
    return MatrizResultado;
}
template<typename T>
T*** restarMatriz(T*** MatrizA, T*** MatrizB, int filas, int columnas, int z){
     T*** MatrizResultado= asignarMatriz(MatrizResultado, filas, columnas, z);
    for(int i=0; i<filas;i++){
        for(int j=0;j<columnas;j++){
            for(int k=0;k<z;k++){
                T[i][j][k]=MatrizA[i][j][k]-MatrizB[i][j][k];
            }
        }
    }
    return MatrizResultado;

}
template<typename T>
T** multiplicarMatriz(T** MatrizA, T** MatrizB, int filas, int columnas, int filasB, int columnasB){
    try{
        if(columnas != filasB){
            throw DimensionesInvalidasExcepcion("El # de columnas de la matriz A debe ser igual al # de filas de B");
        }
        
        T** MatrizResultado = new T*[filas];
        for(int i = 0; i < filas; i++){
            MatrizResultado[i] = new T[columnasB];
            for(int j = 0; j < columnasB; j++){
                MatrizResultado[i][j] = 0;
                for(int k = 0; k < columnas; k++){
                    MatrizResultado[i][j] += MatrizA[i][k] * MatrizB[k][j];
                }
            }
        }
        return MatrizResultado;
    }
    catch(const DimensionesInvalidasExcepcion& e){
        throw;
    }
}

template<typename T>
void ingresarItem(T** indexMatriz, int indexFila, int Columna, T valor){
    T[i][j]=valor;
}
template<typename T>
void ingresarItem(T*** Matriz, int indexFila, int indexColumna, int indexZ, T valor){
    T[i][j][k]=valor;
}
template<typename T>
void imprimirMatriz(T** Matriz, int filas, int columnas){
    for(int i=0; i<filas; i++){
        for(int j=0; j<columnas;j++){
            std::cout<<Matriz[i][j]<<" ";
        }
        std::cout<<std::endl;
    }
}
template<typename T>
void imprimirMatriz(T*** Matriz, int filas, int columnas, int z){
    for(int k = 0; k < z; k++){
        std::cout << "capa " << k + 1 << ":" << std::endl;
        for(int i = 0; i < filas; i++){
            for(int j = 0; j < columnas; j++){
                std::cout << Matriz[i][j][k] << " ";
            }
            std::cout << std::endl;
        }
    }
}
template<typename T>
void liberarMatriz(T** Matriz, int filas, int columnas){
    for(int i = 0; i < filas; i++){
        delete[] Matriz[i];
    }
    delete[] Matriz;
}

template<typename T>
void liberarMatriz(T*** Matriz, int filas, int columnas, int z){
    for(int i = 0; i < filas; i++){
        for(int j = 0; j < columnas; j++){
            delete[] Matriz[i][j];
        }
        delete[] Matriz[i];
    }
    delete[] Matriz;
}