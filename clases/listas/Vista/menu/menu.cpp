#include "menu.h"
#include <iostream>
#include <conio.h>
#include <cstdlib>

void Menu::mostrarMenu(){
    const char *opciones[]={
        "Insertar elemento por cabeza",
        "Insertar elemento por cola",
        "Eliminar elemento por cabeza",
        "Buscar elemento en la lista",
        "Imprimir lista",
        "Salir"
    };
    int n=6;
    int eleccion=0;
    int tecla;

    do{
        system("cls");
        std::cout<<"Menu de lista enlazada simple"<<std::endl;
        
        int index= 0;
        for(const auto& opcion: opciones){
            if(index==eleccion){
                std::cout<<" ->";
            }else{
                std::cout<<" ";
            }
            std::cout<<opcion<<std::endl;
            index++;
        }
        std::cout<<"Use las flechas Arriba/Abajo para navegar y enter para elegir"<<std::endl;
        tecla=_getch();
        if(tecla==0||tecla==224){
            tecla =_getch();
            switch (tecla){
            case 72:
            eleccion--;
            if (eleccion < 0) eleccion = n-1;
            break;
            case 80:
            eleccion++;
            if(eleccion >= n) eleccion=0;
            break;
        }
    }else if (tecla ==13){
        system("cls");
        std::cout<<"Opcion seleccionada: "<<opciones[eleccion]<<std::endl;
    switch (eleccion){
        case 0: 
        insertarCabeza();
        break;
        case 1: 
        insertarCola();
        break;
        case 2: 
        eliminarCabeza();
        break;
        case 3: 
        buscarElemento();
        break;
        case 4:
        imprimirLista();
        break;
        case 5:
        std::cout<<"Saliendo del programa"<<std::endl;
        return;

        default:
        std::cout<<"Opcion invalida\n";
    
    }
    std::cout<<"\nPresione cualquier tecla para continuar   ";
    _getch();

    }
} while (true);

 }

void Menu::insertarCabeza(){
    std::cout << "Insertar Cabeza" << std::endl;
    int valor;
    std::cout << "Ingrese el valor a insertar: ";
    std::cin >> valor;
    lista.addListHead(valor);
    std::cout << "Valor " << valor << " insertado al inicio." << std::endl;
}

void Menu::insertarCola(){
    std::cout << "Insertar Cola" << std::endl;
    int valor;
    std::cout << "Ingrese el valor a insertar: ";
    std::cin >> valor;
    lista.addListTail(valor);
    std::cout << "Valor " << valor << " insertado al final." << std::endl;
}

void Menu::eliminarCabeza(){
    std::cout << "Eliminar Cola" << std::endl;
    lista.remList();
}

void Menu::buscarElemento(){
    std::cout << "Buscar elemento" << std::endl;
    int valor;
    std::cout << "Ingrese el valor a buscar: ";
    std::cin >> valor;
    std::cout << "Funcionalidad de busqueda en desarrollo..." << std::endl;
}

void Menu::imprimirLista(){
    std::cout << "Imprimir lista" << std::endl;
    lista.printList();
}

int Menu::obtenerEntero(const char* mensaje){
    int valor;
    std::cout << mensaje;
    std::cin >> valor;
    return valor;
}