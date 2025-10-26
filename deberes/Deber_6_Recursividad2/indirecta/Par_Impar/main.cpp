#include "./modelo/Lista/lista.cpp"
#include "./modelo/Nodo/nodo.cpp"
#include "./modelo/parImpar/parimpar.cpp"

int main(void){
    Nodo* nodo= new Nodo(1);
    ListaEnlazada lista(nodo);
    lista.addListHead(2);
    lista.addListHead(3);
    lista.addListHead(4);
    paresImpares(lista);
}