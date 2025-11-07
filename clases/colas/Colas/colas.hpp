//la cola entra por arriba, y entra por abajo
#ifndef COLA_HPP
#define COLA_HPP
#include "../Nodo/nodo.hpp"

class Cola{
    private:
    Nodo* Head;
    Nodo* Tail;
    public:
    Cola();
    Cola(int);
    ~Cola();
    void push(int);
    void pop();
    int front();
    int back();
    void display();
    bool isEmpty();
};

#endif
