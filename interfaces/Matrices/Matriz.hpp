#ifndef Matriz_hpp
#define Matriz_hpp
#include <cstdlib>

template<typename T>
void asignarMatriz(T** &Matriz, int filas, int columnas);
template<typename T>
void asignarMatriz(T*** &Matriz, int filas, int columnas, int z);
template<typename T>
void encerar(T** Matriz, int filas, int columnas);
template<typename T>
void encerar(T*** Matriz, int filas, int columnas, int z);
template<typename T>
T** sumarMatriz(T** MatrizA, T** MatrizB, int filas, int columnas);
template<typename T>
T*** sumarMatriz(T*** MatrizA, T*** MatrizB, int filas, int columnas, int z);
template<typename T>
T** restarMatriz(T** MatrizA, T** MatrizB, int filas, int columnas);
template<typename T>
T*** restarMatriz(T*** MatrizA, T*** MatrizB, int filas, int columnas, int Z);
template<typename T>
T** multiplicarMatriz(T** MatrizA, T** MatrizB, int filas, int columnas, int filasB, int columnasB);
template<typename T>
void ingresarItem(T** Matriz, int indexFila, int indexColumna, T valor);
template<typename T>
void ingresarItem(T*** Matriz, int indexFila, int indexColumna, int indexZ, T valor);
template<typename T>
void imprimirMatriz(T** Matriz, int filas, int columnas);
template<typename T>
void imprimirMatriz(T*** Matriz, int filas, int columnas, int z);
template<typename T>
void liberarMatriz(T** Matriz, int filas);
template<typename T>
void liberarMatriz(T*** Matriz, int filas, int columnas);


#endif