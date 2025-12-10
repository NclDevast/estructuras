#include "Menu.hpp"


Menu::Menu() {
    opcionSeleccionada = 0;
}

void Menu::limpiarPantalla() {
    system("cls");
}

void Menu::pausar() {
    std::cout << "\nPresione cualquier tecla para continuar..." << std::endl;
    _getch();
}

void Menu::mostrarMenu() {
    limpiarPantalla();
    std::cout << "--------------------------------------------" << std::endl;
    std::cout << "|      ÁRBOL BINARIO DE BÚSQUEDA (ABB)      |" << std::endl;
    std::cout << "--------------------------------------------" << std::endl;
    std::cout << std::endl;
    
    const char* opciones[] = {
        "1. Insertar datos",
        "2. Buscar dato",
        "3. Ver recorridos",
        "4. Ver árbol (visual)",
        "5. Salir"
    };
    
    for(int i = 0; i < 5; i++) {
        if(i == opcionSeleccionada) {
            std::cout << ">> " << opciones[i] << " <<" << std::endl;
        } else {
            std::cout << "   " << opciones[i] << std::endl;
        }
    }
    
    std::cout << std::endl << "Use FLECHAS para navegar, ENTER para seleccionar" << std::endl;
}

void Menu::ingresarDatos() {
    limpiarPantalla();
    std::cout << "--------------------------------------------" << std::endl;
    std::cout << "|           INSERTAR DATOS AL ÁRBOL         |" << std::endl;
    std::cout << "--------------------------------------------" << std::endl;
    std::cout << std::endl;
    
    int cantidad;
    std::cout << "¿Cuántos datos desea ingresar? ";
    std::cin >> cantidad;
    std::cout << std::endl;
    
    for(int i = 0; i < cantidad; i++) {
        int dato;
        std::cout << "Ingrese el dato " << (i + 1) << ": ";
        std::cin >> dato;
        arbol.insertarNodo(dato);
    }
    
    std::cout << std::endl << "✓ Datos insertados correctamente" << std::endl;
    pausar();
}

void Menu::buscarDato() {
    limpiarPantalla();
    std::cout << "--------------------------------------------" << std::endl;
    std::cout << "|             BUSCAR DATO EN EL ÁRBOL       |" << std::endl;
    std::cout << "--------------------------------------------" << std::endl;
    std::cout << std::endl;
    
    int dato;
    std::cout << "Ingrese el dato a buscar: ";
    std::cin >> dato;
    std::cout << std::endl;
    
    if(arbol.buscar(dato)) {
        std::cout << "✓ El valor " << dato << " SE ENCUENTRA en el árbol" << std::endl;
    } else {
        std::cout << "✗ El valor " << dato << " NO se encuentra en el árbol" << std::endl;
    }
    
    pausar();
}

void Menu::mostrarRecorridoMenu() {
    limpiarPantalla();
    std::cout << "--------------------------------------------" << std::endl;
    std::cout << "|         SELECCIONE TIPO DE RECORRIDO      |" << std::endl;
    std::cout << "--------------------------------------------" << std::endl;
    std::cout << std::endl;
    
    int opcion = 0;
    bool seleccionado = false;
    
    while(!seleccionado) {
        limpiarPantalla();
        std::cout << "--------------------------------------------" << std::endl;
        std::cout << "|         SELECCIONE TIPO DE RECORRIDO      |" << std::endl;
        std::cout << "--------------------------------------------" << std::endl;
        std::cout << std::endl;
        
        const char* tipos[] = {
            "1. Inorden (Izquierda - Raíz - Derecha)",
            "2. Preorden (Raíz - Izquierda - Derecha)",
            "3. Postorden (Izquierda - Derecha - Raíz)",
            "4. Volver"
        };
        
        for(int i = 0; i < 4; i++) {
            if(i == opcion) {
                std::cout << ">> " << tipos[i] << " <<" << std::endl;
            } else {
                std::cout << "   " << tipos[i] << std::endl;
            }
        }
        
        std::cout << std::endl << "Use FLECHAS para navegar, ENTER para seleccionar" << std::endl;
        
        int tecla = _getch();
        
        if(tecla == 224) { // Tecla especial (flecha)
            tecla = _getch();
            if(tecla == 72) { // Flecha arriba
                opcion = (opcion - 1 + 4) % 4;
            } else if(tecla == 80) { // Flecha abajo
                opcion = (opcion + 1) % 4;
            }
        } else if(tecla == 13) { // Enter
            seleccionado = true;
            
            limpiarPantalla();
            std::cout << "--------------------------------------------" << std::endl;
            std::cout << "|              RESULTADO DEL RECORRIDO      |" << std::endl;
            std::cout << "--------------------------------------------" << std::endl;
            std::cout << std::endl;
            
            if(arbol.getRaiz() == nullptr) {
                std::cout << "✗ El árbol está vacío" << std::endl;
            } else {
                switch(opcion) {
                    case 0:
                        std::cout << "Recorrido Inorden: ";
                        arbol.inorden(arbol.getRaiz());
                        std::cout << std::endl;
                        break;
                    case 1:
                        std::cout << "Recorrido Preorden: ";
                        arbol.preorden(arbol.getRaiz());
                        std::cout << std::endl;
                        break;
                    case 2:
                        std::cout << "Recorrido Postorden: ";
                        arbol.postorden(arbol.getRaiz());
                        std::cout << std::endl;
                        break;
                    case 3:
                        return;
                }
            }
            pausar();
        }
    }
}

void Menu::mostrarRecorridos() {
    mostrarRecorridoMenu();
}

void Menu::ejecutarOpcion(int opcion) {
    switch(opcion) {
        case 0:
            ingresarDatos();
            break;
        case 1:
            buscarDato();
            break;
        case 2:
            mostrarRecorridos();
            break;
        case 3:
            mostrarArbol();
            break;
        case 4:
            limpiarPantalla();
            std::cout << "--------------------------------------------" << std::endl;
            std::cout << "|          ¡Hasta luego! Programa finalizado|" << std::endl;
            std::cout << "--------------------------------------------" << std::endl;
            exit(0);
    }
}

void Menu::iniciar() {
    bool continuar = true;
    
    while(continuar) {
        mostrarMenu();
        
        int tecla = _getch();
        
        if(tecla == 224) { // Tecla especial (flecha)
            tecla = _getch();
            if(tecla == 72) { // Flecha arriba
                opcionSeleccionada = (opcionSeleccionada - 1 + 5) % 5;
            } else if(tecla == 80) { // Flecha abajo
                opcionSeleccionada = (opcionSeleccionada + 1) % 5;
            }
        } else if(tecla == 13) { // Enter
            ejecutarOpcion(opcionSeleccionada);
        }
    }
}

int Menu::calcularAltura(Nodo<int>* nodo) {
    if(nodo == nullptr) {
        return 0;
    }
    
    int alturaIzq = calcularAltura(nodo->getIzquierda());
    int alturaDer = calcularAltura(nodo->getDerecha());
    
    return 1 + (alturaIzq > alturaDer ? alturaIzq : alturaDer);
}

void Menu::dibujarArbol(Nodo<int>* nodo, int espacio, int altura) {
    if(nodo == nullptr) {
        return;
    }
    
    espacio += altura;
    
    dibujarArbol(nodo->getDerecha(), espacio, altura);
    
    std::cout << std::endl;
    for(int i = altura; i < espacio; i++) {
        std::cout << " ";
    }
    std::cout << nodo->getDato();
    
    dibujarArbol(nodo->getIzquierda(), espacio, altura);
}

void Menu::mostrarArbol() {
    limpiarPantalla();
    std::cout << "--------------------------------------------" << std::endl;
    std::cout << "|              VISUALIZAR ÁRBOL             |" << std::endl;
    std::cout << "--------------------------------------------" << std::endl;
    std::cout << std::endl;
    
    if(arbol.getRaiz() == nullptr) {
        std::cout << "✗ El árbol está vacío" << std::endl;
    } else {
        int altura = calcularAltura(arbol.getRaiz());
        std::cout << "Altura del árbol: " << altura << std::endl;
        std::cout << std::endl;
        std::cout << "Representación visual del árbol:" << std::endl;
        std::cout << std::endl;
        
        dibujarArbol(arbol.getRaiz(), 0, 4);
        
        std::cout << std::endl << std::endl;
        std::cout << "Estadísticas del árbol:" << std::endl;
        std::cout << "- Altura: " << altura << std::endl;
    }
    
    pausar();
}
