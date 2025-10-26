#include "./Modelo/Lista/lista.cpp"
#include "./Modelo/Nodo/nodo.cpp"
#include "./Modelo/Fibonacci_lista/fibo.cpp"
#include <iostream>

int main(void){

    
    ListaEnlazada lista;
    lista.addListHead(2);
    lista.addListTail(1);
    lista.printList();
    std::cout<<lista.getDato(2);
    sumaFibonacciHastaIndice(lista,2);  //FUNCIONES LAMBDA MALEVOLAS
}