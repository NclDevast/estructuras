#include "nodo.hpp"
#include <iostream>

Nodo::Nodo(int d){
    siguiente=nullptr;
    dato=d;
}

Nodo::~Nodo(){
    delete siguiente;
    std::cout<<"Se ha eliminado el nodo correctamente"<<std::endl;
}

Nodo* Nodo::getSiguiente(){return siguiente;}
void Nodo::setSiguiente(Nodo* siguienteNew){siguiente=siguienteNew;}
int Nodo::getDato(){return dato;}
void Nodo::setDato(int d){dato=d;}