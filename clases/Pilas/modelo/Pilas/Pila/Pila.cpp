#include "Pila.hpp"
#include <iostream>

Pila::Pila(){
    Top=nullptr;
}
Pila::Pila(int dato){

}
Pila::Pila(int dato){
    Top=new Nodo(dato);
}
Pila::~Pila(){
    while(Top!=nullptr){
        Nodo* tmp = Top;
        tmp=tmp->getSiguiente();
        delete tmp;
    }
}

void Pila::push(int dato){
    if(Top==nullptr){
        Top=new Nodo(dato);
        return;
    }
    Nodo* tmp = new Nodo(Top,dato);
    Top->setAnterior(tmp);
    Top=tmp;
}

void Pila::pop(){
    if(Top==nullptr){
        std::cout<<"Error, pila vacia"<<std::endl;
        return;
    }
    Nodo* NodoABorrar = Top;

    Top=Top->getSiguiente();
    if(Top!=nullptr){
        Top->setAnterior(nullptr);
    }
    delete NodoABorrar;
}

void Pila::pop(int dato){
    
}
