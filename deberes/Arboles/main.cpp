#include "MenuInicio.cpp"
#include "Menu.cpp"
#include "MenuAVL.cpp"
#include "MenuArbol.cpp"
#include "common/Nodo.cpp"
#include "ABB/ABB.cpp"
#include "AVL/AVL.cpp"

int main(void){
    MenuInicio menuInicio;
    int tipoArbol = menuInicio.iniciar();
    
    if(tipoArbol == 0) {
        // ABB
        Menu menuABB;
        menuABB.iniciar();
    } else if(tipoArbol == 1) {
        // AVL
        MenuAVL menuAVL;
        menuAVL.iniciar();
    }
    
    return 0;
}