#include "Nodo.hpp"

Nodo::Nodo(int dato){
    Siguiente = nullptr;
    Anterior = nullptr;
    Dato = dato;
}

Nodo::Nodo(Nodo* siguiente,int dato){
    Dato=dato;
    Siguiente=siguiente;
    Anterior=nullptr;
}

Nodo::Nodo(Nodo* siguiente, Nodo* anterior, int dato){
    Dato=dato;
    Siguiente=siguiente;
    Anterior=anterior;
}


Nodo* Nodo::getAnterior(void)const{return Anterior;}
Nodo* Nodo::getSiguiente(void)const{return Siguiente;}
int Nodo::getDato(){return Dato;}
void Nodo::setAnterior(Nodo* anterior){Anterior=anterior;}
void Nodo::setSiguiente(Nodo* siguiente){Siguiente=siguiente;}
void Nodo::setDato(int dato){Dato=dato;}
