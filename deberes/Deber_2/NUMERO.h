#ifndef NUMERO_H
#define NUMERO_H

class Clase{

    private: 

    int NumInt;
    double NumDouble;
    char Char;
    long int NumLongInt;
    
    
    public:
    Clase();
    Clase(int numInt, double numDouble, char newChar, long int numLongInt);
    int getNumInt();
    double getNumDouble();
    char getChar();
    long int getNumLongInt();
    void setNumInt(int num);
    void setNumDouble(double num);
    void setChar(char CharNew);
    void setNumLongInt(long int num);
    void mostrarTamanos();
};

template<typename T>
size_t getSize(T dato);

#include "NUMERO.cpp"
#endif