#include "lista.hpp"
#include <iostream>
#include <functional>

ListaEnlazada::ListaEnlazada(){head=nullptr;}
ListaEnlazada::ListaEnlazada(Nodo*& PrimerNodo){
    head=PrimerNodo;
}

void ListaEnlazada::addListTail(int d) {
    if (head == nullptr) {
        head = new Nodo(d);
        return;
    }
    
    Nodo* tmp = head;
    
    while (tmp->getSiguiente() != nullptr) {
        tmp = tmp->getSiguiente();
    }
    
    tmp->setSiguiente(new Nodo(d));
}

void ListaEnlazada::addListHead(int d){
    Nodo* NewHead = new Nodo(d);
    NewHead->setSiguiente(head);  
    head = NewHead;               
}

void ListaEnlazada::removeHead(){
    if(head == nullptr){
        std::cout << "La lista esta vacia. No hay elementos para eliminar." << std::endl;
        return;
    }
    Nodo* temp = head;
    head = head->getSiguiente();
    std::cout << "Elemento " << temp->getDato() << " eliminado de la cabeza." << std::endl;
    delete temp;
}

void ListaEnlazada::removeTail(){
    

    if(head==nullptr){
        std::cout<<"Lista vacia"<<std::endl;
        return;
    }

    if(head->getSiguiente()==nullptr){
        delete head;
        head=nullptr;
        return;
    }

    Nodo* tmp = head;
    Nodo* tmpAnterior;

    while(tmp->getSiguiente()!=nullptr){
        tmpAnterior=tmp;
        tmp=tmp->getSiguiente();
    }

    tmpAnterior->setSiguiente(nullptr);
    delete tmp;

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

int ListaEnlazada::getIndice(int dato)const{
    if(head == nullptr){
        std::cout << "Lista vacia" << std::endl;
        return -1;
    }

    Nodo* temp = head;
    int index = 0;

    while(temp != nullptr){
        if(dato == temp->getDato()){
            std::cout << "Item encontrado en indice: " << index << std::endl;
            return index;
        }
        temp = temp->getSiguiente();
        index++;
    }

    std::cout << "Elemento no encontrado en la lista" << std::endl;
    return -1;
}


int ListaEnlazada::buscarIndice(int index)const{
    std::cout << "getDato(" << index << ") llamado" << std::endl;
    
    if (head == nullptr) {
        std::cout << "ERROR: Lista vacía" << std::endl;
        return 0;
    }
    
    int counter = 0;
    Nodo* temp = head;
    
    std::cout << "Recorriendo lista..." << std::endl;
    while (temp != nullptr) {
        std::cout << "Nodo " << counter << ": valor = " << temp->getDato();
        if (counter == index) {
            std::cout << " <- ENCONTRADO" << std::endl;
            return temp->getDato();
        }
        std::cout << std::endl;
        temp = temp->getSiguiente();
        counter++;
    }
    
    
    std::cout << "ERROR: Índice " << index << " fuera de rango. Último índice: " << (counter-1) << std::endl;
    return 0;
}

int ListaEnlazada::getSize()const{

    if(head==nullptr){
        std::cout<<"Lista Vacia"<<std::endl;
        return 0;
    }
    int cont=0;
    Nodo* tmp=head;
    while(tmp!=nullptr){
        cont++;
        tmp=tmp->getSiguiente();
    }
    return cont;
}

int ListaEnlazada::sumLista()const{
    auto sum = [this]() -> int{
        int resultado=0;

        if(this->getSize()==0){
            return 0;
        }

        for(int i=0;i<this->getSize();i++){
            if(this->buscarIndice(i)%2!=0){
                resultado+=this->buscarIndice(i);
            }
        }
        return resultado;
    };
    return sum();
}