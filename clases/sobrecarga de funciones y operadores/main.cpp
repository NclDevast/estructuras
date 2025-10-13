#include <iostream>

using namespace std;


    float suma(int num1, float num2, double num3);
    float suma(float num1, int num2, double num3);
    float suma(double num1, float num2, double num3);
    float suma(int num1, double num2, float num3);
    float suma(float num1, double num2, int num3);

    template <typename T>
    T ingresardato();

    template <typename T>
    T ingresardato(){
        T dato;
        cout<<"Ingrese un numero: ";
        cin>>dato;
        return dato;
    };

    int main(void){
        return 0;
    }

    float suma(int num1, float num2, double num3) {
    return static_cast<float>(num1 + num2 + num3);
    }

    float suma(float num1, int num2, double num3) {
        return static_cast<float>(num1 + num2 + num3);
    }

    float suma(double num1, float num2, double num3) {
        return static_cast<float>(num1 + num2 + num3);
    }

    float suma(int num1, double num2, float num3) {
        return static_cast<float>(num1 + num2 + num3);
    }

    float suma(float num1, double num2, int num3) {
        return static_cast<float>(num1 + num2 + num3);
    }

    template <typename T>
    T ingresardato();

    template <typename T>
    T ingresardato(){
        T dato;
        cout << "Ingrese un numero: ";
        cin >> dato;
        return dato;
    };

    int main (void){
        float resultado1 = suma(ingresardato<int>(), ingresardato<float>(), ingresardato<double>());
    }

