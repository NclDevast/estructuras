#ifndef modelo_h
#define modelo_h

#include <stdio.h>
#include <iostream>

class Fraccion{
    private: 
    float* Denominador;
    float* Numerador;

    public:

    //constructores

    Fraccion();
    Fraccion(float numerador, float denominador);
    ~Fraccion();
    
    //getters y setters
    float getNumerador();
    float getDenominador();
    void setNumerador(float numerador);
    void setDenominador(float denominador);
    //Sobrecarga de operadores y metodos
    Fraccion operator+(const Fraccion& otra)const;
    Fraccion operator-(const Fraccion& otra)const;
    Fraccion operator*(const Fraccion& otra)const;
    Fraccion operator/(const Fraccion& otra)const;
    float calcularDenominador(const Fraccion& otra)const;

};

template<typename T>
size_t getSize(T dato);

#endif