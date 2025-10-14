//Encontrar el tamaño de una clase que tenga diferentes tipos de datos (int, float, double) y explicar por qué tiene ese tamaño.
//nota: incluir el tamaño de metodos como getters y setters y constructors
//realizar la suma entre 3 objetos con un atributo numero y un metodo suma

#include <iostream>
#include "NUMERO.h"

int main (void){
    Clase clase(1,2.5,'c',1);
    cout<<"El tamano del objeto es: "<<sizeof(clase)<<endl;
    cout << "El tamano del int es: " << getSize(clase.getNumInt())<<endl;
    cout << "El tamano del double es: "<<getSize(clase.getNumDouble())<<endl;
    cout << "El tamano del char es: " <<getSize(clase.getChar())<<endl;
    cout << "El tamano del long int es: "<<getSize(clase.getNumLongInt())<<endl;
    clase.mostrarTamanos();
    return 0;
}