#ifndef FRACCION_H
#define FRACCION_H

template<typename T>
class Fraccion{
    private:
        T numerador;
        T denominador;
    public:
    // Constructores
        Fraccion();
        Fraccion(T num, T den);
    //getters y setters
        T getNumerador() const;
        T getDenominador() const;
        void setNumerador(T num);
        void setDenominador(T dem);
    //métodos
        Fraccion<T> multiplicar(const Fraccion<T>& otra) const;
        void ingresar(); 
        void mostrar() const;
};

#include "FRACCION.cpp"

#endif // FRACCION_H