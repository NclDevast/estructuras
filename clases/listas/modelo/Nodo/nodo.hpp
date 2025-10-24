class Nodo{
    private: 
    int dato;
    Nodo* siguiente;
    
    public:
    Nodo(int);
    ~Nodo();
    Nodo* getSiguiente();
    int getDato();
    void setSiguiente(Nodo*);
    void setDato(int);
    
    
};