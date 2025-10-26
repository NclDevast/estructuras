#include "fibo.hpp"
#include <functional>
#include <iostream>


auto sumaFiboElemento = [](ListaEnlazada List, int index)->int{
    std::function<int(int)>sumaFibo;
    int temp;
    if(List.getDato(index)<=1){
        return 0;
    }
    temp=List.getDato(index);
    auto sumaFibo = [&sumaFibo](int dato){
        return sumaFibo(dato-1)+sumaFibo(dato-2);
        };
    return sumaFibo(temp);
};

int fiboElemento(ListaEnlazada lista, int index){

    int tmp;
    for(int i=0;i<index;i++){
        tmp=tmp+sumaFiboElemento(lista,index);
    }
    std::cout<<"La suma total de todos los elementos de la lista son: "<<tmp<<std::endl;
    return tmp;
}