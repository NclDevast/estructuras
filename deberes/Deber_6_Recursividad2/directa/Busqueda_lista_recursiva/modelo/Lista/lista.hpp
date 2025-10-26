#ifndef LISTA_HPP
#define LISTA_HPP
#include "../Nodo/nodo.hpp"

class ListaEnlazada{
    private:
    Nodo* head;
    public:
    ListaEnlazada();
    ListaEnlazada(Nodo*);
    ~ListaEnlazada();
    void addListHead(int);
    void addListTail(int);
    void removeHead();
    void removeTail();
    void printList();
    int getIndice(int);
};

#endif