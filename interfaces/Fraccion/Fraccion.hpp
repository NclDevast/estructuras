#ifndef fraccion_hpp
#define fraccion_hpp

class Fraccion {
private: 
    float Denominador;  // Cambiado de puntero a variable directa
    float Numerador;    // Cambiado de puntero a variable directa

public:
    // Constructores
    Fraccion();
    Fraccion(float numerador, float denominador);
    ~Fraccion();
    
    // Getters y setters
    float getNumerador() const;
    float getDenominador() const;
    void setNumerador(float numerador);
    void setDenominador(float denominador);
    
    // Sobrecarga de operadores y métodos
    Fraccion operator+(const Fraccion& otra) const;
    Fraccion operator-(const Fraccion& otra) const;
    Fraccion operator*(const Fraccion& otra) const;
    Fraccion operator/(const Fraccion& otra) const;
    float calcularDenominador(const Fraccion& otra) const;
    void imprimirFraccion();
};

#endif