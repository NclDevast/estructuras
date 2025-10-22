#include "Fraccion.hpp"
#include <stdio.h>
#include <iostream>



//constructores y destructor

Fraccion::Fraccion(){
    Numerador = new float(0);
    Denominador = new float(1);
}

Fraccion::Fraccion(float numerador, float denominador){
    Numerador = new float(numerador);
    Denominador = new float(denominador);
    if(denominador=0){
        std::cout<<"Error, no hay division para 0 ";
        *Denominador=1;
    }
}

Fraccion::~Fraccion(){
    delete Numerador;
    delete Denominador;
}

float Fraccion::getDenominador()const{
    return *Denominador;
}

float Fraccion::getNumerador()const{
    return *Numerador;
}

void Fraccion::setNumerador(float numerador){
    *Numerador=numerador;
}

void Fraccion::setDenominador(float denominador){
    *Denominador=denominador;
}

float Fraccion::calcularDenominador(const Fraccion& otra)const{
    return *Denominador * (otra.getDenominador());
}

Fraccion Fraccion::operator+(const Fraccion& otra)const{

    float resultadoFr1;
    float resultadoFr2;
    float nuevoNumerador; 
    
    resultadoFr1= (*Numerador)*(otra.getDenominador());
    resultadoFr2= (otra.getNumerador())*(*Denominador);
    nuevoNumerador = resultadoFr1 + resultadoFr2;
    return Fraccion(nuevoNumerador, calcularDenominador(otra));

}

Fraccion Fraccion::operator-(const Fraccion& otra)const{
    float resultadoFr1;
    float resultadoFr2;
    float nuevoNumerador; 
    
    resultadoFr1= (*Numerador)*(otra.getDenominador());
    resultadoFr2= (otra.getNumerador())*(*Denominador);
    nuevoNumerador = resultadoFr1 - resultadoFr2;
    return Fraccion(nuevoNumerador, calcularDenominador(otra));

}

Fraccion Fraccion::operator*(const Fraccion& otra)const{
    float nuevoNum;
    float nuevoDen;

    nuevoNum=(*Numerador)*(otra.getNumerador());
    nuevoDen=(*Denominador)*(otra.getNumerador());

    return Fraccion(nuevoNum,nuevoDen);
}

Fraccion Fraccion::operator/(const Fraccion& otra)const{
    float nuevoNum;
    float nuevoDen;

    nuevoNum=(*Numerador)*(otra.getDenominador());
    nuevoDen=(*Denominador)*(otra.getNumerador());

    return Fraccion(nuevoNum,nuevoDen);
}

template<typename T>
size_t getSize(T dato){
    return sizeof(dato);
}