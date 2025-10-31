#ifndef NODO_HPP
#define NODO_HPP

class Nodo{
    private:
    Nodo* Siguiente;
    Nodo* Anterior;
    int Dato;

    public:
    Nodo(int);
    Nodo(Nodo*,int);
    Nodo(Nodo*,Nodo*,int);
    //~Nodo();
    Nodo* getSiguiente()const;
    Nodo* getAnterior()const;
    void setSiguiente(Nodo*);
    void setAnterior(Nodo*);
    int getDato();
    void setDato(int);
};


#endif