#ifndef  BUSQUEDA_HPP
#define BUSQUEDA_HPP
#include <algorithm>
#include <string>
#include <iostream>

int inputNum(std::string Mensaje, bool negativos){
    if(negativos){
        std::cout << Mensaje;
        int input = 0;
        std::cin >> input;
        return input;
    }
    bool validInput = false;
    int input = 0;
    do{
        std::cout << Mensaje;
        std::cin >> input;
        if(input <= 0){ 
            std::cout << "Entrada Invalida, debe ser mayor a cero\n";
        }
        else {
            validInput = true;
        }
    } while(!validInput);
    return input;
}

int ejercicioTorres(){
    int n = inputNum("Ingrese cuantas ciudades existen: ", false);
    int m = inputNum("Ingrese cuantas torres habran: ", false);

    int* cities = inputIntVector(n, "Ingrese las coordenadas de la ciudad: ", true);
    int* towers = inputIntVector(m, "Ingrese las coordenadas de la torre: ", true);
    cities = bubbleSort(cities, n);
    towers = bubbleSort(towers, m);

    long long max_r = 0;
    int tower_idx = 0;
    for (int i = 0; i < n; ++i) {
        long long current_min_dist = -1;
        while (tower_idx < m - 1 && towers[tower_idx + 1] <= cities[i]) {
            tower_idx++;
        }
        current_min_dist = std::abs((long long)cities[i] - towers[tower_idx]);
        if (tower_idx + 1 < m) {
            current_min_dist = std::min(current_min_dist, std::abs((long long)cities[i] - towers[tower_idx + 1]));
        }
        if (current_min_dist > max_r) {
            max_r = current_min_dist;
        }
    }

    std::cout << "El minimo r es: " << max_r << std::endl;

    delete[] cities;
    delete[] towers;
    return 0; 
}

int* inputIntVector(int size,std::string msg,bool negatives){
    int* vector = new int[size];
    for(int i=0;i<size;i++){
        *(vector+i)=inputNum(msg,negatives);
    }
    return vector;
}

int* bubbleSort(int* array, int size){
    std::sort(array, array + size);
    return array;
}

#endif