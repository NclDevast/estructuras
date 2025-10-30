#ifndef PILA_HPP
#define PILA_HPP
#include  "../Nodo/Nodo.hpp"
class Pila{
    private:
    Nodo* Top;
    public:
    Pila();
    Pila(int);
    ~Pila();
    void push(int);
    void pop();
    void pop(int);
    bool isEmpty()const;
    void peek()const;
    void display()const;
    void editTop(int);
};

#endif