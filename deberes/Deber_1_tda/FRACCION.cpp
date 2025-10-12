#include "FRACCION.h"
#include <iostream>
#include <stdexcept> 
using namespace std;

template<typename T>
Fraccion<T>::Fraccion(){
    numerador = 0;
    denominador = 1;
}

template<typename T>
Fraccion<T>::Fraccion(T num, T den){
    if(den == 0){
        throw invalid_argument("Denominador no puede ser cero");
    }
    numerador = num;
    denominador = den;
}

template<typename T>
T Fraccion<T>::getNumerador() const{
    return numerador;
}

template<typename T>
T Fraccion<T>::getDenominador() const{
    return denominador;
}

template<typename T>
void Fraccion<T>::setNumerador(T num){
    numerador = num;
}

template<typename T>
void Fraccion<T>::setDenominador(T den){
     denominador = den;
}

template<typename T>
Fraccion<T> Fraccion<T>::multiplicar(const Fraccion<T>& otra) const{
    return Fraccion<T>(numerador * otra.numerador, denominador * otra.denominador);
}


template<typename T>
void Fraccion<T>::ingresar(){
    
    do{
        cout << "Ingrese el denominador (Debe ser diferente de cero): ";
        cin >> denominador;
        if(denominador==0){
        cout<< "Error, el denominador no puede ser 0, retornando"<<endl;
        }
    }
    while(denominador==0);

    cout<< "Ingrese el numerador: ";
    cin>>numerador;
}



template<typename T>
void Fraccion<T>::mostrar() const{
    cout<<numerador<<"/"<<denominador;
}

