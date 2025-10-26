#include <iostream>
using namespace std;

struct Nodo {
    int dato;
    Nodo* siguiente;
};

struct Cola {
    Nodo* frente;
    Nodo* final;
};

void inicializar(Cola* c) {
    c->frente = NULL;
    c->final = NULL;
}

bool empty(Cola* c) {
    return (c->frente == NULL);
}

void push(Cola* c, int valor) {
    Nodo* nuevo = new Nodo();
    nuevo->dato = valor;
    nuevo->siguiente = NULL;

    if (empty(c)) {
        c->frente = nuevo;
    } else {
        c->final->siguiente = nuevo;
    }
    c->final = nuevo;
}

int main() {
    Cola cola;
    inicializar(&cola);

    cout << (empty(&cola) ? "Cola vacía" : "Cola con elementos") << endl;

    push(&cola, 15);
    push(&cola, 30);

    cout << (empty(&cola) ? "Cola vacía" : "Cola con elementos") << endl;
}
