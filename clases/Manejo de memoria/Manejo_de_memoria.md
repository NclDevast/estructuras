# Manejo de memoria estática y dinámica

Comparación rápida

|Operador .|Operador ->|
|---|---|
|El operador . sirve para acceder a un miembro estático de un objeto|El operador -> sirve para acceder a un miembro dinámico (puntero) de un objeto|

## Operaciónes para reservación de memoria


| Función | Definición | Sintaxis | Ejemplo |
|---------|------------|----------|---------|
| **malloc** | Asigna un bloque de memoria del tamaño especificado en bytes. No inicializa la memoria. | `void* malloc(size_t size);` | `int* ptr = (int*)malloc(10 * sizeof(int));` |
| **calloc** | Asigna memoria para un array de elementos, inicializando todos los bits a cero. | `void* calloc(size_t num, size_t size);` | `int* ptr = (int*)calloc(10, sizeof(int));` |
| **realloc** | Cambia el tamaño de un bloque de memoria previamente asignado. | `void* realloc(void* ptr, size_t size);` | `ptr = (int*)realloc(ptr, 20 * sizeof(int));` |
| **new** | Operador de C++ que asigna memoria e inicializa objetos (llama al constructor). | `type* ptr = new type;`<br>`type* ptr = new type[size];` | `int* ptr = new int;`<br>`int* arr = new int[10];` |
| **delete** | Operador de C++ que libera memoria asignada con new y llama al destructor. | `delete ptr;`<br>`delete[] arr;` | `delete ptr;`<br>`delete[] arr;` |

## Diferencias entre malloc, realloc y calloc

### malloc - Asignación básica de memoria

Cuándo usarlo:
- Cuando necesitas memoria sin inicializar
- Cuando el rendimiento es crítico (evita la sobrecarga de inicialización)

```cpp

// Buffer para datos binarios
uint8_t* buffer = (uint8_t*)malloc(1024 * sizeof(uint8_t));

// Estructura simple sin constructor
struct Point { int x, y; };
Point* points = (Point*)malloc(10 * sizeof(Point));

```

### calloc - Memoria inicializada a cero

Cuándo usarlo:
Cuando necesitas arrays inicializados a cero

Cuando trabajas con contadores o flags

Para evitar bugs de memoria no inicializada

Cuando la seguridad es prioridad

```cpp

// Array de contadores
int* counters = (int*)calloc(100, sizeof(int));

// Matriz de booleanos
bool* flags = (bool*)calloc(50, sizeof(bool));

// Estructura con muchos campos
struct Config {
    int timeout;
    int retries;
    char name[50];
};
Config* configs = (Config*)calloc(5, sizeof(Config));

```

### realloc - Redimensionamiento de memoria

Cuándo usarlo:
Cuando necesitas expandir/contraer arrays dinámicos

Para buffers que crecen incrementalmente

En implementaciones de listas dinámicas o vectores

Cuando no conoces el tamaño final de antemano

```cpp
// Buffer que crece dinámicamente
char* input_buffer = (char*)malloc(64 * sizeof(char));
size_t buffer_size = 64;

while (needs_more_space) {
    buffer_size *= 2;
    input_buffer = (char*)realloc(input_buffer, buffer_size);
}

// Lista dinámica de elementos
typedef struct {
    int id;
    char name[100];
} Item;

Item* items = (Item*)malloc(10 * sizeof(Item));
int item_count = 10;

// Agregar más elementos
items = (Item*)realloc(items, 20 * sizeof(Item));
```

## Como segmentar memoria una vez asignada

Ejercicio de matriz 3x3
Usando malloc, realloc y calloc:

```cpp
#include <stdio.h>
#include <stdlib.h>

int main() {
    int filas = 3, columnas = 3;
    int **matriz;
    
    // Asignar memoria para array de punteros a filas
    matriz = (int**)malloc(filas * sizeof(int*));
    if (matriz == NULL) return 1;
    
    // Asignar memoria para cada fila
    for (int i = 0; i < filas; i++) {
        *(matriz + i) = (int*)malloc(columnas * sizeof(int));
        if (*(matriz + i) == NULL) return 1;
    }
    
    // Editar usando doble aritmética de punteros
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            *(*(matriz + i) + j) = i * columnas + j + 1;
        }
    }
    
    // Imprimir
    printf("Matriz con doble puntero:\n");
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            printf("%d ", *(*(matriz + i) + j));
        }
        printf("\n");
    }
    
    // Liberar memoria
    for (int i = 0; i < filas; i++) {
        free(*(matriz + i));
    }
    free(matriz);
    
    return 0;
}

```

```cpp
#include <iostream>

int main() {
    const int filas = 3, columnas = 3;
    
    // Asignar memoria para array de punteros
    int** matriz = new int*[filas];
    
    // Asignar memoria para cada fila
    for (int i = 0; i < filas; i++) {
        *(matriz + i) = new int[columnas];
    }
    
    // Inicializar usando doble aritmética de punteros
    for (int i = 0; i < filas; i++) {
        int* fila_actual = *(matriz + i);
        for (int j = 0; j < columnas; j++) {
            *(fila_actual + j) = i * 10 + j;
        }
    }
    
    // Imprimir
    std::cout << "Matriz con doble puntero (new/delete):" << std::endl;
    for (int i = 0; i < filas; i++) {
        int* fila_actual = *(matriz + i);
        for (int j = 0; j < columnas; j++) {
            std::cout << *(fila_actual + j) << " ";
        }
        std::cout << std::endl;
    }
    
    // Modificar valores específicos
    int** ptr_matriz = matriz;
    for (int i = 0; i < filas; i++) {
        int* ptr_fila = *(ptr_matriz + i);
        for (int j = 0; j < columnas; j++) {
            if (i == j) {  // Diagonal principal
                *(ptr_fila + j) = 100 + i * 10 + j;
            }
        }
    }
    
    std::cout << "\nMatriz después de modificar diagonal:" << std::endl;
    for (int i = 0; i < filas; i++) {
        int* fila_actual = *(matriz + i);
        for (int j = 0; j < columnas; j++) {
            std::cout << *(fila_actual + j) << " ";
        }
        std::cout << std::endl;
    }
    
    // Liberar memoria
    for (int i = 0; i < filas; i++) {
        delete[] *(matriz + i);
    }
    delete[] matriz;
    
    return 0;
}

```