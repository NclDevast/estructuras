#ifndef fraccion_hpp
#define fraccion_hpp


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
    float getNumerador()const;
    float getDenominador()const;
    void setNumerador(float numerador);
    void setDenominador(float denominador);
    //Sobrecarga de operadores y metodos
    Fraccion operator+(const Fraccion& otra)const;
    Fraccion operator-(const Fraccion& otra)const;
    Fraccion operator*(const Fraccion& otra)const;
    Fraccion operator/(const Fraccion& otra)const;
    float calcularDenominador(const Fraccion& otra)const;
    void imprimirFraccion();

};

#endif