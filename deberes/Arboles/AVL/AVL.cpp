#include "AVL.HPP"
#include <iostream>
#include <algorithm>

// Constructor
template<typename T>
AVL<T>::AVL(){
    Raiz = nullptr;
}

// Destructor
template<typename T>
AVL<T>::~AVL(){
    eliminarAux(Raiz);
}

// Obtener altura de un nodo
template<typename T>
int AVL<T>::obtenerAltura(const Nodo<T>* nodo) const {
    if(nodo == nullptr) return 0;
    
    int alturaIzq = obtenerAltura(nodo->getIzquierda());
    int alturaDer = obtenerAltura(nodo->getDerecha());
    
    return 1 + std::max(alturaIzq, alturaDer);
}

// Obtener factor de balance
template<typename T>
int AVL<T>::obtenerBalance(Nodo<T>* nodo){
    if(nodo == nullptr) return 0;
    
    return obtenerAltura(nodo->getIzquierda()) - obtenerAltura(nodo->getDerecha());
}

// Rotación simple a la derecha
template<typename T>
Nodo<T>* AVL<T>::rotarDerecha(Nodo<T>* nodo){
    Nodo<T>* temp = nodo->getIzquierda();
    nodo->setIzquierda(temp->getDerecha());
    temp->setDerecha(nodo);
    
    return temp;
}

// Rotación simple a la izquierda
template<typename T>
Nodo<T>* AVL<T>::rotarIzquierda(Nodo<T>* nodo){
    Nodo<T>* temp = nodo->getDerecha();
    nodo->setDerecha(temp->getIzquierda());
    temp->setIzquierda(nodo);
    
    return temp;
}

// Método público para insertar
template<typename T>
void AVL<T>::insertarNodo(T valorInsertar){
    Raiz = insertarAux(Raiz, valorInsertar);
}

// Método auxiliar recursivo para insertar con balanceo
template<typename T>
Nodo<T>* AVL<T>::insertarAux(Nodo<T>* nodo, T valor){
    // Caso base: crear nuevo nodo
    if(nodo == nullptr){
        return new Nodo<T>(valor, nullptr);
    }
    
    // Insertar en subárbol izquierdo si es menor
    if(valor < nodo->getDato()){
        nodo->setIzquierda(insertarAux(nodo->getIzquierda(), valor));
    }
    // Insertar en subárbol derecho si es mayor
    else if(valor > nodo->getDato()){
        nodo->setDerecha(insertarAux(nodo->getDerecha(), valor));
    }
    // Si es igual, no insertar (evitar duplicados)
    else {
        return nodo;
    }
    
    // Obtener factor de balance
    int balance = obtenerBalance(nodo);
    
    // Caso Izquierda-Izquierda
    if(balance > 1 && valor < nodo->getIzquierda()->getDato()){
        return rotarDerecha(nodo);
    }
    
    // Caso Derecha-Derecha
    if(balance < -1 && valor > nodo->getDerecha()->getDato()){
        return rotarIzquierda(nodo);
    }
    
    // Caso Izquierda-Derecha
    if(balance > 1 && valor > nodo->getIzquierda()->getDato()){
        nodo->setIzquierda(rotarIzquierda(nodo->getIzquierda()));
        return rotarDerecha(nodo);
    }
    
    // Caso Derecha-Izquierda
    if(balance < -1 && valor < nodo->getDerecha()->getDato()){
        nodo->setDerecha(rotarDerecha(nodo->getDerecha()));
        return rotarIzquierda(nodo);
    }
    
    return nodo;
}

// Método público para buscar
template<typename T>
bool AVL<T>::buscar(T valorBuscar){
    return buscarAux(Raiz, valorBuscar) != nullptr;
}

// Método auxiliar recursivo para buscar
template<typename T>
Nodo<T>* AVL<T>::buscarAux(Nodo<T>* nodo, T valor){
    // Caso base: nodo no encontrado
    if(nodo == nullptr){
        return nullptr;
    }
    
    // Si el valor es igual, retornar el nodo
    if(nodo->getDato() == valor){
        return nodo;
    }
    // Si el valor es menor, buscar en subárbol izquierdo
    else if(valor < nodo->getDato()){
        return buscarAux(nodo->getIzquierda(), valor);
    }
    // Si el valor es mayor, buscar en subárbol derecho
    else{
        return buscarAux(nodo->getDerecha(), valor);
    }
}

// Método auxiliar para eliminar todo el árbol
template<typename T>
void AVL<T>::eliminarAux(Nodo<T>* nodo){
    if(nodo == nullptr) return;
    
    eliminarAux(nodo->getIzquierda());
    eliminarAux(nodo->getDerecha());
    delete nodo;
}

// Recorrido en orden (izquierda, raíz, derecha)
template<typename T>
void AVL<T>::inorden(Nodo<T>* nodo){
    if(nodo == nullptr) return;
    
    inorden(nodo->getIzquierda());
    std::cout << nodo->getDato() << " ";
    inorden(nodo->getDerecha());
}

// Recorrido en pre-orden (raíz, izquierda, derecha)
template<typename T>
void AVL<T>::preorden(Nodo<T>* nodo){
    if(nodo == nullptr) return;
    
    std::cout << nodo->getDato() << " ";
    preorden(nodo->getIzquierda());
    preorden(nodo->getDerecha());
}

// Recorrido en post-orden (izquierda, derecha, raíz)
template<typename T>
void AVL<T>::postorden(Nodo<T>* nodo){
    if(nodo == nullptr) return;
    
    postorden(nodo->getIzquierda());
    postorden(nodo->getDerecha());
    std::cout << nodo->getDato() << " ";
}

// Getter para la raíz
template<typename T>
Nodo<T>* AVL<T>::getRaiz()const{
    return Raiz;
}

// Getter para la altura del árbol
template<typename T>
int AVL<T>::getAltura()const{
    int altura = obtenerAltura(Raiz);
    return altura;
}
