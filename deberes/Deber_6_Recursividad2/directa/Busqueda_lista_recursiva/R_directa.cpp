#include <iostream>
#include <functional>
#include "./modelo/Lista/lista.cpp"
#include "./modelo/Nodo/nodo.cpp"


//sumar todos los elementos de una Lista

std::function<void(int,int,int)> sumaElementosLista;

int main(void){

    Nodo* primerNodo = new  Nodo(1);
    ListaEnlazada Lista(primerNodo);
    Lista.addListHead(5);
    Lista.addListHead(6);
    Lista.addListHead(1);
    Lista.getIndice(5);
    
}