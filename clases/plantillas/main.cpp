#include <iostream>
#include "clases.h"
using namespace std;

int main (void){

    Fraccion <int> fraccion1(3,4);
    Fraccion <int> fraccion2(2,5);

    Fraccion <int> fraccionresultado= fraccion1.multiplicarFracciones(fraccion1,fraccion2);

    cout<<"El resultado de la multiplicacion es: "<<fraccionresultado.getNumerador()<<"/"<<fraccionresultado.getDenominador()<<endl;

    return 0;
}