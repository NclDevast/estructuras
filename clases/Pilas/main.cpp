#include "./modelo/Nodo/Nodo.cpp"
#include "./modelo/Pilas/Pila.cpp"
#include <iostream>

int main(void){
    Pila pilanueva = Pila(4);
    pilanueva.push(65);
    pilanueva.push(45);
    pilanueva.display();
    pilanueva.pop();
    std::cout<<"El valor en el Top de la pila es: "<<pilanueva.peek();
}