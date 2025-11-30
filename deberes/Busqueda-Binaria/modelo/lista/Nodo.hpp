#ifndef NODO_HPP
#define NODO_HPP

template <typename T>
class Nodo {
private:
  T Dato;
  Nodo<T> *Siguiente;

public:
  Nodo(T dato, Nodo<T> *siguiente = nullptr)
      : Dato(dato), Siguiente(siguiente) {}

  Nodo<T> *getSiguiente() { return Siguiente; }

  void setSiguiente(Nodo<T> *Siguiente) { this->Siguiente = Siguiente; }

  T getDato() { return Dato; }

  void setDato(T Dato) { this->Dato = Dato; }
};

#endif