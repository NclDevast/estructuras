#include <iostream>
#include <cmath>
#include <cstdlib>   
using namespace std;

int inputNum(string Mensaje, bool negativos){
    if(negativos){
        cout << Mensaje;
        int input = 0;
        cin >> input;
        return input;
    }
    bool validInput = false;
    int input = 0;
    do{
        cout << Mensaje;
        cin >> input;
        if(input <= 0){ 
            cout << "Entrada Invalida, debe ser mayor a cero\n";
        }
        else {
            validInput = true;
        }
    } while(!validInput);
    return input;
}

int* inputIntVector(int size, string msg, bool negatives){
    int* vector = (int*)malloc(size * sizeof(int));
    for(int i = 0; i < size; i++){
        *(vector+i) = inputNum(msg, negatives);
    }
    return vector;
}

int* bubbleSort(int* array, int size){
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (*(array + j) > *(array + j + 1)) {
                int temp = *(array + j);
                *(array + j) = *(array + j + 1);
                *(array + j + 1) = temp;
            }
        }
    }
    return array;
}

// ----------------------
// BÚSQUEDA BINARIA REAL
// ----------------------
int lowerBoundManual(int* arr, int size, int value) {
    int left = 0;
    int right = size;

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (*(arr + mid) < value)
            left = mid + 1;
        else
            right = mid;
    }
    return left;
}

int ejercicioRouters(){
    int n = inputNum("Ingrese cuantos salones existen: ", false);
    int m = inputNum("Ingrese cuantos routers habran: ", false);

    int* salon = inputIntVector(n, "Ingrese la coordenada del salon: ", true);
    int* router = inputIntVector(m, "Ingrese la coordenada del router: ", true);

    salon = bubbleSort(salon, n);
    router = bubbleSort(router, m);

    long long max_r = 0;

    for (int i = 0; i < n; i++) {

        int c = *(salon + i);

        int pos = lowerBoundManual(router, m, c);

        long long best = 9000000000000000000LL;

        if (pos < m) {
            long long dist = std::llabs((long long)c - *(router + pos));
            if (dist < best) best = dist;
        }

        if (pos > 0) {
            long long dist = std::llabs((long long)c - *(router + (pos - 1)));
            if (dist < best) best = dist;
        }

        if (best > max_r)
            max_r = best;
    }

    cout << "El minimo r es: " << max_r << "\n";

    free(salon);
    free(router);
    return 0;
}


int main() {
    ejercicioRouters();
    return 0;
}