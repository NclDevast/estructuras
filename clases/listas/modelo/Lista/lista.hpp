#include "../Nodo/nodo.hpp"

class ListaEnlazada{
    private:
    Nodo* head;
    public:
    ListaEnlazada();
    ~ListaEnlazada();
    void addListHead(int);
    void addListTail(int);
    void remList();
    void printList();
};