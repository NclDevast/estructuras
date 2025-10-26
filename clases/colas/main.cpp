#include <iostream>
#include <conio.h>
#include <stdlib.h>

using namespace std;

struct Nodo{
    int dato;
    Nodo *siguiente;
};

void insertarCola(Nodo *&, Nodo*&, int);
bool cola_vacia(Nodo *); 
void suprimirCola(Nodo *&, Nodo *&, int &);

int main(){
    Nodo *frente = NULL;
    Nodo *fin = NULL;
    int dato, opcion;

    cout << "COLA DE NODOS\n";

    do {
        cout << "\nDigite un numero: ";
        cin >> dato;
        insertarCola(frente, fin, dato);

        cout << "¿Desea insertar otro numero? (1=Si / 0=No): ";
        cin >> opcion;
    } while (opcion == 1);

    getch();
    system("cls");

    cout << "\nEliminando los nodos de la cola:\n";
    while (frente != NULL) {
        suprimirCola(frente, fin, dato);
        if (frente != NULL) {
            cout << dato << " , ";
        } else {
            cout << dato << " .\n";
        }
    }

    cout << "\n\nTodos los elementos fueron eliminados.\n";
    getch();
    return 0;
}

void insertarCola(Nodo *&frente, Nodo *&fin, int n){
    Nodo *nuevo_nodo = new Nodo();

    nuevo_nodo->dato = n;
    nuevo_nodo->siguiente = NULL;

    if (cola_vacia(frente)){
        frente = nuevo_nodo;
    } else {
        fin->siguiente = nuevo_nodo;
    }
    fin = nuevo_nodo;

    cout << "Elemento " << n << " insertado a cola correctamente\n";
}

bool cola_vacia(Nodo *frente){
    return (frente == NULL);
}

void suprimirCola(Nodo *&frente, Nodo *&fin, int &n){
    n = frente->dato;
    Nodo *aux = frente;

    if (frente == fin){
        frente = NULL;
        fin = NULL;
    } else {
        frente = frente->siguiente;
    }
    delete aux;
}
