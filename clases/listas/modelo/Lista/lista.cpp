#include "lista.hpp"
#include <iostream>

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

void ListaEnlazada::remList(){
    if(head == nullptr){
        std::cout << "La lista esta vacia. No hay elementos para eliminar." << std::endl;
        return;
    }
    Nodo* temp = head;
    head = head->getSiguiente();
    std::cout << "Elemento " << temp->getDato() << " eliminado de la cabeza." << std::endl;
    delete temp;
}

void ListaEnlazada::printList(){
    if(head == nullptr){
        std::cout << "La lista esta vacia." << std::endl;
        return;
    }
    Nodo* tmp = head;
    std::cout << "Elementos de la lista: ";
    while(tmp != nullptr){
        std::cout << tmp->getDato() << " -> ";
        tmp = tmp->getSiguiente();
    }
    std::cout << "NULL" << std::endl;
}

ListaEnlazada::~ListaEnlazada(){
    while(head != nullptr){
        Nodo* temp = head;
        head = head->getSiguiente();
        delete temp;
    }
}