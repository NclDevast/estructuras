#include "../../PruebaInterfaces/controlador.h"

void Controlador::iniciar() {
    int opcion;
    do {
        opcion = vista.menu();
        
        if (opcion >= 1 && opcion <= 4) {
            vista.mostrarMensaje("\nPrimera fracción:");
            Fraccion f1 = vista.ingresarFraccion();
            
            vista.mostrarMensaje("\nSegunda fracción:");
            Fraccion f2 = vista.ingresarFraccion();
            
            Fraccion resultado = realizarOperacion(f1, f2, opcion);
            
            char operador;
            switch(opcion) {
                case 1: operador = '+'; break;
                case 2: operador = '-'; break;
                case 3: operador = '*'; break;
                case 4: operador = '/'; break;
                default: operador = '?';
            }
            
            vista.mostrarResultado(resultado, operador);
        }
        
    } while (opcion != 0);
    
    vista.mostrarMensaje("\n¡Hasta luego!");
}

Fraccion Controlador::realizarOperacion(const Fraccion& f1, const Fraccion& f2, int opcion) {
    switch(opcion) {
        case 1:
            return f1 + f2;
        case 2:
            return f1 - f2;
        case 3:
            return f1 * f2;
        case 4:
            return f1 / f2;
        default:
            return Fraccion(); // Retorna fracción por defecto 0/1
    }
}