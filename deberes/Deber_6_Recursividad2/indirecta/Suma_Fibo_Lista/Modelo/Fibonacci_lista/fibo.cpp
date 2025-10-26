#include "fibo.hpp"
#include <functional>
#include <iostream>

//version con referencia de objeto y captura maligna

auto sumaFiboElemento = [](const ListaEnlazada& List, int index) -> int {
    std::cout<<"Llegado a Fibo"<< index << std::endl;;
    int valor = List.getDato(index);
    
    std::function<int(int)> sumaFibo;
    
    sumaFibo = [&sumaFibo](int n) -> int {
        if (n <= 0) return 0;
        if (n == 1) return 1;
        return sumaFibo(n - 1) + sumaFibo(n - 2);
    };
    
    return sumaFibo(valor);
};

int sumaFibonacciHastaIndice(const ListaEnlazada& lista, int index) {
    int sumaTotal = 0;  
    
    for(int i = 0; i <= index; i++) {  
        sumaTotal += sumaFiboElemento(lista, i);  
    }
    
    std::cout << "La suma total de Fibonacci de los elementos hasta indice " 
              << index << " es: " << sumaTotal << std::endl;
    return sumaTotal;
}
    /*

    // Versión CORRECTA - calcula Fibonacci del valor en la lista
auto fibonacciDeElemento = [](ListaEnlazada lista, int index) -> int {
    int valor = lista.getDato(index);
    
    // Fibonacci iterativo
    if (valor <= 0) return 0;
    if (valor == 1) return 1;
    
    int a = 0, b = 1, c;
    for (int i = 2; i <= valor; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
};

// ASÍ SÍ FUNCIONA
int sumaFibonacciHastaIndice(ListaEnlazada lista, int index) {
    int sumaTotal = 0;  
    for(int i = 0; i <= index; i++) {  
        sumaTotal += fibonacciDeElemento(lista, i);  // ✅ Retorna int directamente
    }
    
    std::cout << "La suma total de Fibonacci de los elementos hasta indice " 
              << index << " es: " << sumaTotal << std::endl;
    return sumaTotal;
}
    */