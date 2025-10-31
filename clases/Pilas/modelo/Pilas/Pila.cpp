#include "../Nodo/Nodo.hpp"
#include "Pila.hpp"
#include <iostream>
#include <stdexcept>

Pila::Pila(){
    Top=nullptr;
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
    return;
}

bool Pila::isEmpty()const{
    if(Top==nullptr){
        return true;
    }
    return false;
}

int Pila::peek()const{
    if(Top==nullptr){
        throw std::runtime_error("Error: peek() llamado en una pila vacía.");
    }
    return Top->getDato();

}

void Pila::display()const{
    if(Top==nullptr){
        std::cout<<"Error, pila vacia"<<std::endl;
        return;
    }
    Nodo* tmp = Top;
    while (tmp!=nullptr){
        std::cout<<tmp->getDato()<< " ";
        tmp=tmp->getSiguiente();
    }
    std::cout<<std::endl;
}

void Pila::editTop(int dato){
    if(Top==nullptr){
        std::cout<<"Error, pila vacia"<<std::endl;
        return;
    }
    Top->setDato(dato);
}