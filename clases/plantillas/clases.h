#ifndef CLASES_H
#define CLASES_H

#include <stdexcept> // Para manejo de excepciones

template <typename T>
class Fraccion {
public:
    // Constructor por defecto - inicializa fracción 0/1
    Fraccion() {
        Numerador = 0;
        Denominador = 1;
    }

    // Constructor con parámetros - permite crear fracciones personalizadas
    Fraccion(T numerador, T denominador) {
        // Validación: el denominador no puede ser cero
        if (denominador == 0) {
            throw std::invalid_argument("Denominador no puede ser cero");
        }
        Numerador = numerador;
        Denominador = denominador;
    }

    // Método para multiplicar fracciones
    // Toma dos fracciones como parámetros y retorna su producto
    Fraccion multiplicarFracciones(Fraccion frac1, Fraccion frac2) {
        T resultadoNumerador = frac1.getNumerador() * frac2.getNumerador();
        T resultadoDenominador = frac1.getDenominador() * frac2.getDenominador();

        Fraccion fraccionresultado(resultadoNumerador, resultadoDenominador);
        return fraccionresultado;
    }
    
    // Getters - métodos para obtener los valores de los atributos
    T getNumerador() {
        return Numerador;
    }
    
    T getDenominador() {
        return Denominador;
    }

    // Setters - métodos para modificar los valores de los atributos
    void setNumerador(T numerador) {
        Numerador = numerador;
    }

    void setDenominador(T denominador) {
        // Validación: el denominador no puede ser cero
        if (denominador == 0) {
            throw std::invalid_argument("Denominador no puede ser cero");
        }
        Denominador = denominador;
    }

private:
    // Atributos privados - solo accesibles through getters y setters
    T Numerador;
    T Denominador;
};

#endif // CLASES_H