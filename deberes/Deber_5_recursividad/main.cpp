#include <vector>
#include <iostream>
#include <functional>
#include "Matrices/Matriz.cpp"  

// Recursión anidada
auto ackermann = [](int& llamadas) -> std::function<int(int,int)> {
    std::function<int(int,int)> ack;  
    
    ack = [&llamadas, &ack](int m, int n) -> int {  
        llamadas++;
        if (m == 0) return n + 1;
        if (n == 0) return ack(m - 1, 1);
        return ack(m - 1, ack(m, n - 1));
    };
    
    return ack;
};

// Recursión múltiple - Torres de Hanoi
auto hanoi = [](int& movimientos) -> std::function<void(int, char, char, char)> {
    return [&movimientos](int n, char origen, char auxiliar, char destino) -> void {
        std::function<void(int, char, char, char)> mover = [&](int n, char origen, char auxiliar, char destino) {
            if (n > 0) {
                mover(n - 1, origen, destino, auxiliar);
                movimientos++;
                std::cout << "Mover disco " << n << " desde " << origen << " hasta " << destino << std::endl;
                mover(n - 1, auxiliar, origen, destino);
            }
        };
        mover(n, origen, auxiliar, destino);
    };
};



// Recursión indirecta - Positivo/Negativo
auto positivoNegativo = []() -> std::pair<std::function<bool(int)>, std::function<bool(int)>> {
    std::function<bool(int)> esPositivo, esNegativo;
    
    esPositivo = [&esNegativo](int n) -> bool {
        if (n > 0) return true;
        if (n == 0) return false;
        return !esNegativo(n + 1); // Llamada indirecta
    };
    
    esNegativo = [&esPositivo](int n) -> bool {
        if (n < 0) return true;
        if (n == 0) return false;
        return !esPositivo(n - 1); // Llamada indirecta
    };
    
    return {esPositivo, esNegativo};
};

auto procesarNumero = [](int& llamadas) -> std::function<int(int)> {
    return [&llamadas](int numero) -> int {
        std::function<int(int)> procesar = [&](int n) -> int {
            llamadas++;
            
            // Caso base
            if (n < 10) {
                return n;
            }
            
            // RECURSIÓN NO LINEAL: Dos llamadas recursivas diferentes
            int ultimoDigito = n % 10;
            int restoDelNumero = n / 10;
            
            int resultadoResto = procesar(restoDelNumero);  // Primera llamada recursiva
            int resultadoDigito = procesar(ultimoDigito);   // Segunda llamada recursiva
            
            return resultadoResto + resultadoDigito;
        };
        
        return procesar(numero);
    };
};

int main(void){
    // Prueba de Recursión Anidada (Ackermann)
    std::cout << "=== Prueba de Recursión Anidada (Ackermann) ===\n";
    int llamadasAckermann = 0;
    auto ack = ackermann(llamadasAckermann);
    std::cout << "Ackermann(2,1) = " << ack(2,1) << std::endl;
    std::cout << "Número de llamadas: " << llamadasAckermann << std::endl;

    // Prueba de Recursión Múltiple (Torres de Hanoi)
    std::cout << "\n=== Prueba de Recursión Múltiple (Torres de Hanoi) ===\n";
    int movimientos = 0;
    auto moverTorres = hanoi(movimientos);
    moverTorres(3, 'A', 'B', 'C');
    std::cout << "Número total de movimientos: " << movimientos << std::endl;

    // Prueba de Recursión Indirecta (Positivo/Negativo)
    std::cout << "\n=== Prueba de Recursión Indirecta (Positivo/Negativo) ===\n";
    auto [esPositivo, esNegativo] = positivoNegativo();
    int num1 = 5;
    int num2 = -3;
    int num3 = 0;
    std::cout << num1 << " es " << (esPositivo(num1) ? "positivo" : "negativo") << std::endl;
    std::cout << num2 << " es " << (esNegativo(num2) ? "negativo" : "positivo") << std::endl;
    std::cout << num3 << " es " << (esPositivo(num3) ? "positivo" : "negativo") << std::endl;

    // Búsqueda en diccionario
    std::cout << "\n=== Búsqueda en Diccionario ===\n";
    char** MatrizString;
    char** StringBusqueda;
    int* indice = new int(0);

    std::cout << "=== RECURSIÓN NO LINEAL - Procesar Número ===" << std::endl;
    
    int llamadas = 0;
    auto procesar = procesarNumero(llamadas);
    
    int numero = 123;
    int resultado = procesar(numero);
    
    std::cout << "Número: " << numero << std::endl;
    std::cout << "Resultado: " << resultado << std::endl;
    std::cout << "Número de llamadas recursivas: " << llamadas << std::endl;

    std::function<void(int*)> busquedaDiccionario;

    busquedaDiccionario = [&MatrizString, &StringBusqueda, &busquedaDiccionario](int *indice) -> void {
        if (*indice >= 4) {
            *indice = -1;
            return;
        }
        
        bool coincide = true;
        for(int j = 0; j < 4; j++) {
            if(MatrizString[*indice][j] != StringBusqueda[0][j]) {
                coincide = false;
                break;
            }
        }
        
        if(coincide) {
            return;
        } else {
            (*indice)++;
            if(*indice < 4) {
                busquedaDiccionario(indice);
            } else {
                *indice = -1;
            }
        }
    };

    asignarMatriz(MatrizString, 4, 4);
    asignarMatriz(StringBusqueda, 1, 4);
    
    std::cout << "Ingrese su diccionario de 4 palabras con maximo 4 letras:\n";
    ingresarStringsEnMatriz(MatrizString, 4, 4);
    
    std::cout << "Ingrese la palabra a buscar:\n";
    ingresarStringsEnMatriz(StringBusqueda, 1, 4);

    *indice = 0;
    busquedaDiccionario(indice);

    if(*indice == -1){
        std::cout << "Palabra no encontrada" << std::endl;
    }
    else{
        std::cout << "Palabra encontrada en el indice: " << *indice << std::endl;
    }
    
    liberarMatriz(MatrizString, 4);
    liberarMatriz(StringBusqueda, 1);
    delete indice;

    return 0;  
}