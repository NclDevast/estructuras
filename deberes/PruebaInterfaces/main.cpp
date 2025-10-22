#include "Fraccion.hpp"
#include "Matriz.hpp"
int main(void){
    Fraccion** matrizFracciones;
    asignarMatriz(matrizFracciones, 2, 2);

    matrizFracciones[0][0] = Fraccion(2,3);
    matrizFracciones[0][1] = Fraccion(4,3);
    matrizFracciones[1][0] = Fraccion(7,8);
    matrizFracciones[1][1] = Fraccion(10,9);

    Fraccion** matrizFracciones2;
    asignarMatriz(matrizFracciones2, 2, 2);

    matrizFracciones2[0][0] = Fraccion(5,7);  // Corregido: matrizFracciones2
    matrizFracciones2[0][1] = Fraccion(8,8);  // Corregido: matrizFracciones2
    matrizFracciones2[1][0] = Fraccion(9,8);  // Corregido: matrizFracciones2
    matrizFracciones2[1][1] = Fraccion(10,9); // Corregido: matrizFracciones2

    Fraccion** matrizFraccionesResultado;
    asignarMatriz(matrizFraccionesResultado, 2, 2);  // Corregido: matrizFraccionesResultado
    
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            matrizFraccionesResultado[i][j] = matrizFracciones[i][j] + matrizFracciones2[i][j];
        }
    }
    
    imprimirMatriz(matrizFraccionesResultado, 2, 2);
    
    // Liberar memoria
    liberarMatriz(matrizFracciones, 2, 2);
    liberarMatriz(matrizFracciones2, 2, 2);
    liberarMatriz(matrizFraccionesResultado, 2, 2);
    
    return 0;
}