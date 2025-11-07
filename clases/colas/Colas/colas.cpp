#include "colas.hpp"
#include <iostream>

Cola::Cola(){
    Head=nullptr;
    Tail=nullptr;
}

Cola::Cola(int dato){
    Head=new Nodo(dato);
    Tail=Head;
}

Cola::~Cola(){
    while(Head!=nullptr){
        Nodo* tmp = Head;
        Head=Head->getSiguiente();
        delete tmp;
    }
}
bool Cola::isEmpty(){
    if (Head==nullptr)
    return true;
    return false;
}
void Cola::push(int dato){
    if(isEmpty){
        Head=new Nodo(dato);
        Tail=Head;
        return;
    }
    Nodo* NewNodo = new Nodo(dato);
    Tail->setSiguiente(NewNodo);
    Tail=NewNodo;
}
void Cola::pop(){
    if(isEmpty){
        std::cout<<"Error, cola vacia."<<std::endl;
        return;
    }
    Nodo* NodoBorrar = Head;
    Head=Head->getSiguiente();
    if(Head==nullptr){
        Tail=nullptr;
    }
    delete NodoBorrar;
}

int Cola::front(){
    if(isEmpty){
        std::cout<<"Error, pila vacia"<<std::endl;
        return 0;
    }
    return Head->getDato();
}

int Cola::back(){
    if(isEmpty){
        std::cout<<"Error, pila vacia"<<std::endl;
        return 0;
    }
    return Tail->getDato();
}
void Cola::display(){
    if(isEmpty){
        std::cout<<"Error, pila vacia"<<std::endl;
        return;
    }
    Nodo* Cursor=Head;
    std::cout<<"Inicio ->";
    while(Cursor!=nullptr){
        std::cout<<Cursor->getDato()<<" ";
        Cursor=Cursor->getSiguiente();
    }
    std::cout<<"<- Fin"<<std::endl;
}