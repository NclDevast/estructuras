#include "lista.hpp"

ListaEnlazada::ListaEnlazada(){head=nullptr;}
void ListaEnlazada::addListTail(int d){
    while(head==nullptr){
        head=new Nodo(d);
        return;
    }
    Nodo* tmp = head;
    while(tmp->getSiguiente()!=nullptr){
        tmp = tmp->getSiguiente();
    }
    tmp->setSiguiente(new Nodo(d));
}

void ListaEnlazada::addListHead(int d){
    Nodo* NewHead = new Nodo(d);
    NewHead->setSiguiente(head);
    head=NewHead;
}