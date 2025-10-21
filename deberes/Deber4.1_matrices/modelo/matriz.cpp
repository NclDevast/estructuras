#include "matriz.h"


Matriz::Matriz(){
    Filas=0;
    Columnas=0;
}

Matriz::Matriz(int filas, int columnas): Filas(filas), Columnas(columnas){
    MatrizGenerada=new float*[filas];
    for(int i=0;i<Filas;i++){
        MatrizGenerada[i] = new float[Columnas];
    }

    /* Metodo legacy usando Malloc
    MatrizGenerada = (float**)malloc(sizeof(float*) * Filas);
        for (int i = 0; i < Filas; i++) {
            *(MatrizGenerada + i) = (float*)malloc(sizeof(float) * Columnas);
        }
    */
}

Matriz::~Matriz(){
    for(int i = 0; i < Filas; i++) {
        delete[] MatrizGenerada[i];
    }
    delete[] MatrizGenerada;
}

int Matriz::getFilas(){
    return Filas;
}

int Matriz::getColumnas(){
    return Columnas;
}

void Matriz::setFilas(int filas){
    Filas=filas;
}

void Matriz::setColumnas(int columnas){
    Columnas=columnas;
}

void Matriz::editarMatriz(int sizeFilas, int sizeColumnas){
    // Liberar memoria anterior
    if (MatrizGenerada != nullptr) {
        for(int i = 0; i < Filas; i++) {
            delete[] MatrizGenerada[i];
        }
        delete[] MatrizGenerada;
    }
    
    // Actualizar dimensiones
    Filas = sizeFilas;
    Columnas = sizeColumnas;
    
    // Crear nueva matriz
    MatrizGenerada = new float*[Filas];
    for(int i = 0; i < Filas; i++) {
        MatrizGenerada[i] = new float[Columnas];
        // Inicializar con ceros
        for(int j = 0; j < Columnas; j++) {
            MatrizGenerada[i][j] = 0.0f;
        }
    }
}

void Matriz::ingresarDatos(int indexFila, int indexColumna, float valor){
    *(*(MatrizGenerada+indexFila)+indexColumna)=valor;
}

Matriz Matriz::operator*(const Matriz& otra)const{
    float suma;
    if(Columnas!=otra.Filas){
        std::cout<<"Dimensiones no compatibles: El numero de columnas de la primera matriz debe ser igual al numero de columnas de la segunda matriz";
        return Matriz();
    }
    Matriz MatrizResultado = Matriz(Filas, otra.Columnas);
    for(int i = 0; i<MatrizResultado.Filas;i++){

        for(int i = 0; i < MatrizResultado.Filas; i++) {
            for(int j = 0; j < MatrizResultado.Columnas; j++) {
                float resultadoTemp = 0;
                
                for(int k = 0; k < Columnas; k++) {
                    resultadoTemp += (*(*(MatrizGenerada + i) + k)) * (*(*(otra.MatrizGenerada + k) + j));
                }
                
                *(*(MatrizResultado.MatrizGenerada + i) + j) = resultadoTemp;
            }
        }
    return MatrizResultado;
    }
}    