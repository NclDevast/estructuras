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
            if (eleccion >=n) eleccion=0;
            break;
            case 80:
            eleccion++;
            if(eleccion >=n) eleccion=0;
            break;
        }
    }else if (tecla ==13){
        system("cls");
        std::cout<<"Opcon sele"
    }
        
        }

    }
}