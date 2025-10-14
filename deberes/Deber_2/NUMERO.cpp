#include "NUMERO.h"
#include <iostream>
using namespace std;



Clase::Clase(){
    NumInt=0;
    NumDouble=0;
    Char='a';
    NumLongInt=0;
};


Clase::Clase(int numInt, double numDouble, char newChar, long int numLongInt){
    NumInt=numInt;
    NumDouble=numDouble;
    Char=newChar;
    NumLongInt=numLongInt;
}

int Clase::getNumInt(){
    return NumInt;
}

double Clase::getNumDouble(){
    return NumDouble;
}


char Clase::getChar(){
    return Char;
}


long int Clase::getNumLongInt(){
    return NumLongInt;
}


void Clase::setNumInt(int num){
    NumInt = num;
}


void Clase::setNumDouble(double num){
    NumDouble=num;
}

void Clase::setChar(char CharNew){
    Char=CharNew;  
}

void Clase::setNumLongInt(long int num){
    NumLongInt=num;
}

void Clase::mostrarTamanos(){
    cout << "Tamaño de int: " << sizeof(NumInt) << " bytes" << endl;
        cout << "Tamaño de double: " << sizeof(NumDouble) << " bytes" << endl;
        cout << "Tamaño de char: " << sizeof(Char) << " bytes" << endl;
        cout << "Tamaño de long int: " << sizeof(NumLongInt) << " bytes" << endl;
        cout << "Suma de tamaños individuales: " 
             << (sizeof(NumInt) + sizeof(NumDouble) + sizeof(Char) + sizeof(NumLongInt)) 
             << " bytes" << endl;
        cout << "Tamaño total del objeto: " << sizeof(*this) << " bytes" << endl;

}

template<typename T>
size_t getSize(T dato){
    return sizeof(dato);
}
