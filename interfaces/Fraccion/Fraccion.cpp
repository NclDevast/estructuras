#include "Fraccion.hpp"
#include <iostream>

// Constructores y destructor
Fraccion::Fraccion() {
    Numerador = 0;
    Denominador = 1;
}

Fraccion::Fraccion(float numerador, float denominador) {
    Numerador = numerador;
    if(denominador == 0) {
        std::cout << "Error, no hay division para 0" << std::endl;
        Denominador = 1;
    } else {
        Denominador = denominador;
    }
}

Fraccion::~Fraccion() {
    
}

// Getters y setters
float Fraccion::getDenominador() const {
    return Denominador;
}

float Fraccion::getNumerador() const {
    return Numerador;
}

void Fraccion::setNumerador(float numerador) {
    Numerador = numerador;
}

void Fraccion::setDenominador(float denominador) {
    if(denominador != 0) {
        Denominador = denominador;
    } else {
        std::cout << "Error: El denominador no puede ser cero" << std::endl;
    }
}

float Fraccion::calcularDenominador(const Fraccion& otra) const {
    return Denominador * otra.getDenominador();
}

// Sobrecarga de operadores
Fraccion Fraccion::operator+(const Fraccion& otra) const {
    float resultadoFr1;
    float resultadoFr2;
    float nuevoNumerador; 
    
    resultadoFr1 = Numerador * otra.getDenominador();
    resultadoFr2 = otra.getNumerador() * Denominador;
    nuevoNumerador = resultadoFr1 + resultadoFr2;
    return Fraccion(nuevoNumerador, calcularDenominador(otra));
}

Fraccion Fraccion::operator-(const Fraccion& otra) const {
    float resultadoFr1;
    float resultadoFr2;
    float nuevoNumerador; 
    
    resultadoFr1 = Numerador * otra.getDenominador();
    resultadoFr2 = otra.getNumerador() * Denominador;
    nuevoNumerador = resultadoFr1 - resultadoFr2;
    return Fraccion(nuevoNumerador, calcularDenominador(otra));
}

Fraccion Fraccion::operator*(const Fraccion& otra) const {
    float nuevoNum;
    float nuevoDen;

    nuevoNum = Numerador * otra.getNumerador();
    nuevoDen = Denominador * otra.getDenominador();

    return Fraccion(nuevoNum, nuevoDen);
}

Fraccion Fraccion::operator/(const Fraccion& otra) const {
    float nuevoNum;
    float nuevoDen;

    nuevoNum = Numerador * otra.getDenominador();
    nuevoDen = Denominador * otra.getNumerador();

    return Fraccion(nuevoNum, nuevoDen);
}

// Método para imprimir
void Fraccion::imprimirFraccion() {
    std::cout << Numerador << "/" << Denominador << std::endl;
}

// Función template (si se necesita mantener)
template<typename T>
size_t getSize(T dato) {
    return sizeof(dato);
}