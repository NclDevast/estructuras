#ifndef LISTA_HPP
#define LISTA_HPP
#include "Nodo.hpp"
#include <iostream>

template <typename T> class Lista {
private:
  Nodo<T> *Head;
  int Capacity;

public:
  Lista() : Head(nullptr), Capacity(0) {}

  ~Lista() {
    while (Head != nullptr) {
      Nodo<T> *temp = Head;
      Head = Head->getSiguiente();
      delete temp;
    }
  }
  Nodo* getHead(){
    return Head;
  }

  bool isEmpty() { return Head == nullptr; }

  void insertHead(T dato) {
    Nodo<T> *nuevo = new Nodo<T>(dato, Head);
    Head = nuevo;
    Capacity++;
  }

  void insertTail(T dato) {
    Nodo<T> *nuevo = new Nodo<T>(dato);
    if (isEmpty()) {
      Head = nuevo;
    } else {
      Nodo<T> *actual = Head;
      while (actual->getSiguiente() != nullptr) {
        actual = actual->getSiguiente();
      }
      actual->setSiguiente(nuevo);
    }
    Capacity++;
  }

  void deleteHead() {
    if (!isEmpty()) {
      Nodo<T> *temp = Head;
      Head = Head->getSiguiente();
      delete temp;
      Capacity--;
    }
  }

  void deleteTail() {
    if (isEmpty()) {
      return;
    }
    if (Head->getSiguiente() == nullptr) {
      delete Head;
      Head = nullptr;
    } else {
      Nodo<T> *actual = Head;
      while (actual->getSiguiente()->getSiguiente() != nullptr) {
        actual = actual->getSiguiente();
      }
      delete actual->getSiguiente();
      actual->setSiguiente(nullptr);
    }
    Capacity--;
  }


  void print() {
    if (isEmpty()) {
      std::cout << "La lista está vacía." << std::endl;
      return;
    }
    Nodo<T> *actual = Head;
    std::cout << "Inicio -> ";
    while (actual != nullptr) {
      std::cout << actual->getDato() << " -> ";
      actual = actual->getSiguiente();
    }
    std::cout << "Fin" << std::endl;
  }

  void insertbyIndex(T dato, int index) {
    if (index < 0 || index > Capacity) {
      std::cout << "Índice fuera de rango." << std::endl;
      return;
    }

    if (index == 0) {
      insertHead(dato);
      return;
    }

    if (index == Capacity) {
      insertTail(dato);
      return;
    }

    Nodo<T> *nuevo = new Nodo<T>(dato);
    Nodo<T> *actual = Head;
    for (int i = 0; i < index - 1; ++i) {
      actual = actual->getSiguiente();
    }
    nuevo->setSiguiente(actual->getSiguiente());
    actual->setSiguiente(nuevo);
    Capacity++;
  }
  T searchbyIndex(int index) {
    if (index < 0 || index >= Capacity) {
      std::cout << "Índice fuera de rango." << std::endl;
      return T(); 
    }
    Nodo<T> *actual = Head;
    for (int i = 0; i < index; ++i) {
      actual = actual->getSiguiente();
    }
    return actual->getDato();
  }
  int getCapacity() {
      return Capacity;
  }

  void sortList(){
    if(Head == nullptr || Head->getSiguiente() == nullptr){
        std::cout << "La lista esta vacia o tiene un solo elemento." << std::endl;
        return;
    }

    bool swapped;
    Nodo<T>* ptr1;
    Nodo<T>* lptr = nullptr;

    do {
        swapped = false;
        ptr1 = Head;

        while(ptr1->getSiguiente() != lptr){
            
            if(ptr1->getDato() > ptr1->getSiguiente()->getDato()){
                
                T temp = ptr1->getDato();
                ptr1->setDato(ptr1->getSiguiente()->getDato());
                ptr1->getSiguiente()->setDato(temp);
                swapped = true;
            }
            ptr1 = ptr1->getSiguiente();
        }
        lptr = ptr1;
    } while(swapped);

    std::cout << "Lista ordenada exitosamente." << std::endl;
  }
};

#endif