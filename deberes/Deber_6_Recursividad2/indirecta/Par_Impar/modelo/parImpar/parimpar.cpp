#include <iostream>
#include <functional>
#include "parimpar.hpp"

auto determinarParImpar = [](const ListaEnlazada& list, int index) -> std::pair<std::function<bool(int)>, std::function<bool(int)>> {
    std::function<bool(int dato)> esPar, esImpar;

    esPar = [&esImpar](int dato) -> bool {
        if (dato == 0) return true;
        return esImpar(dato - 1);
    };
    
    esImpar = [&esPar](int dato) -> bool {
        if (dato == 0) return false;
        return esPar(dato - 1);
    };
    
    int valor = list.getDato(index);
    std::cout << "Valor en lista[" << index << "] = " << valor << std::endl;
    std::cout << "¿Es par? " << esPar(valor) << std::endl;
    std::cout << "¿Es impar? " << esImpar(valor) << std::endl;
    
    return {esPar, esImpar};
};

void paresImpares(const ListaEnlazada& List){

    for(int i=0;i<List.getCapacity();i++){
        auto [esPar,esImpar] = determinarParImpar(List,i);
    }
}

