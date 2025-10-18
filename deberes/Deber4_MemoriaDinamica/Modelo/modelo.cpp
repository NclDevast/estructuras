#include "modelo.h"


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

float Fraccion::getDenominador(){
    return *Denominador;
}

float Fraccion::getNumerador(){
    return *Numerador;
}

void Fraccion::setNumerador(float numerador){
    *Numerador=numerador;
}

void Fraccion::setDenominador(float denominador){
    *Denominador=denominador;
}

float Fraccion::calcularDenominador(const Fraccion& otra)const{
    return *Denominador * (*otra.Denominador);
}

Fraccion Fraccion::operator+(const Fraccion& otra)const{

    float resultadoFr1;
    float resultadoFr2;
    float nuevoNumerador; 
    
    resultadoFr1= (*Numerador)*(*otra.Denominador);
    resultadoFr2= (*otra.Numerador)*(*Denominador);
    nuevoNumerador = resultadoFr1 + resultadoFr2;
    return Fraccion(nuevoNumerador, calcularDenominador(otra));

}

Fraccion Fraccion::operator-(const Fraccion& otra)const{
    float resultadoFr1;
    float resultadoFr2;
    float nuevoNumerador; 
    
    resultadoFr1= (*Numerador)*(*otra.Denominador);
    resultadoFr2= (*otra.Numerador)*(*Denominador);
    nuevoNumerador = resultadoFr1 - resultadoFr2;
    return Fraccion(nuevoNumerador, calcularDenominador(otra));

}

Fraccion Fraccion::operator*(const Fraccion& otra)const{
    float nuevoNum;
    float nuevoDen;

    nuevoNum=(*Numerador)*(*otra.Numerador);
    nuevoDen=(*Denominador)*(*otra.Denominador);

    return Fraccion(nuevoNum,nuevoDen);
}

Fraccion Fraccion::operator/(const Fraccion& otra)const{
    float nuevoNum;
    float nuevoDen;

    nuevoNum=(*Numerador)*(*otra.Denominador);
    nuevoDen=(*Denominador)*(*otra.Numerador);

    return Fraccion(nuevoNum,nuevoDen);
}

template<typename T>
size_t getSize(T dato){
    return  sizeof(dato);
}