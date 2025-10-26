#include "./Modelo/Lista/lista.cpp"
#include "./Modelo/Nodo/nodo.cpp"
#include "./Modelo/Fibonacci_lista/fibo.cpp"
#include <iostream>

int main(void){

    Nodo* nodo= new Nodo(1);
    ListaEnlazada lista(nodo);
    lista.addListHead(2);
    lista.addListHead(3);
    lista.addListHead(4);
    lista.printList();
    std::cout<<lista.getDato(3);
    sumaFibonacciHastaIndice(lista,2);  //FUNCIONES LAMBDA MALEVOLAS
}