#include "./modelo/Matriz.cpp"
#include "./modelo/Fraccion.cpp"

int main() {

    Fraccion** fraca;
    Fraccion** fracb;
    Fraccion** fracc;

    asignarMatriz(fraca,2,2);
    asignarMatriz(fracb,2,2);
    asignarMatriz(fracc,2,2);


    liberarMatriz(fraca,2);
    liberarMatriz(fracb,2);
    liberarMatriz(fracc,2);

    return 0;
    
}