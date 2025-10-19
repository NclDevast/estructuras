#ifndef matriz_h
#define matriz_h
#include <cstdlib>
#include <iostream>

class Matriz{

    private:

    int Filas,Columnas;
    float** MatrizGenerada;

    public:

    //constructores y destructor

    Matriz();
    Matriz(int filas, int columnas);
    ~Matriz();

    //getters
    int getFilas();
    int getColumnas();
    float** getMatriz();
    //setters
    void setFilas(int filas);
    void setColumnas(int columnas);
    //metodos
    void editarMatriz(int sizeFilas, int sizeColumna);
    void ingresarDatos(int indexFila, int indexColumna, float valor);
    Matriz operator*(const Matriz& const)const;

};

template<typename T>
size_t getSize(T dato);

#endif