#include <iostream>

int main (void){
    int* ptrarreglo = new int[3];
    *(ptrarreglo)=4;
    *(ptrarreglo+1)=5;
    *(ptrarreglo+2)=1;
    for(int i=0;i<3;i++){
        std::cout<<"Elemento "<<i<<" del arreglo es: "<<*(ptrarreglo+i)<<std::endl;
    }

    int** nuevoarreglo = new int*[3]; //filas
    for(int i=0;i<4;i++){ 
        *(nuevoarreglo+i) = new int[4]; //columnas
    }
    for(int j=0;j<3;j++){
        **(nuevoarreglo+j)=*(ptrarreglo+j);
    }
    delete ptrarreglo;

    for(int i=0;i<4;i++){
        for(int j=0;j<3;j++){
            std::cout<<"El elemento "<<i<<" "<<j<<" es: ";
            std::cout<<*(*(nuevoarreglo+j)+i)<<".   "; //el doble puntero desreferencia el valor
        }                                               //el primer puntero mueve el indice de columna
        std::cout<<std::endl;                           //el puntero base controla el indice de  la fila
    }
    //nota: en este caso los elemntos de las filas 2,3,4 daran error porque apuntan a nullptr
}