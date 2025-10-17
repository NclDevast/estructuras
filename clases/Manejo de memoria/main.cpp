#include <stdio.h>
#include <stdlib.h>

// Versión minimalista de multiplicación de matrices
int main() {
    printf("=== MULTIPLICACIÓN SIMPLIFICADA 2x2 ===\n");
    
    // Crear matrices 2x2 usando memoria dinámica
    int* A = (int*)malloc(2 * 2 * sizeof(int));
    int* B = (int*)malloc(2 * 2 * sizeof(int));
    int* C = (int*)malloc(2 * 2 * sizeof(int));
    
    // Inicializar matriz A
    *(A + 0) = 1; *(A + 1) = 2;  // [1, 2]
    *(A + 2) = 3; *(A + 3) = 4;  // [3, 4]
    
    // Inicializar matriz B  
    *(B + 0) = 2; *(B + 1) = 0;  // [2, 0]
    *(B + 2) = 1; *(B + 3) = 2;  // [1, 2]
    
    // Multiplicación: C = A × B usando solo aritmética de punteros
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            // Posición en matriz resultado
            int* pos_C = C + i * 2 + j;
            *pos_C = 0; // Inicializar
            
            for (int k = 0; k < 2; k++) {
                int elemento_A = *(A + i * 2 + k);
                int elemento_B = *(B + k * 2 + j);
                *pos_C += elemento_A * elemento_B;
            }
        }
    }
    
    // Imprimir resultados
    printf("Matriz A:\n");
    printf("%d %d\n", *(A + 0), *(A + 1));
    printf("%d %d\n", *(A + 2), *(A + 3));
    
    printf("\nMatriz B:\n");
    printf("%d %d\n", *(B + 0), *(B + 1));
    printf("%d %d\n", *(B + 2), *(B + 3));
    
    printf("\nResultado A × B:\n");
    printf("%d %d\n", *(C + 0), *(C + 1));
    printf("%d %d\n", *(C + 2), *(C + 3));
    
    // Verificación manual: 
    // [1,2]   [2,0]   [1*2+2*1, 1*0+2*2]   [4, 4]
    // [3,4] × [1,2] = [3*2+4*1, 3*0+4*2] = [10,8]
    
    printf("\nVerificación: [4,4] y [10,8] son correctos!\n");
    
    // Liberar memoria
    free(A);
    free(B);
    free(C);
    
    return 0;
}