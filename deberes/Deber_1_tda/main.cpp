#include <iostream>
#include "FRACCION.h"

int main(void){
    
    int* opc;
    opc = new int;

    cout<<"Multiplicador de fracciones"<<endl<<"Seleccione su opcion: "<<endl<<"1)Fracciones de enteros";
    cout<<endl<<"2)Fraccion de decimales"<<endl;
    cin>>*opc;

    switch(*opc){
        case 1:{
            Fraccion<int> fr1,fr2;
            fr1.ingresar();
            fr2.ingresar();
            Fraccion<int> fr3(fr1.multiplicar(fr2));
            cout<<"Su resultado es: ";
            fr3.mostrar();
            break;
        }
        
        case 2: {
            Fraccion<float> fr1, fr2;
            fr1.ingresar();
            fr2.ingresar();
            Fraccion<float> fr3 = fr1.multiplicar(fr2); 
            cout << "Su resultado es: ";
            fr3.mostrar();
            break;
        }
        default: 
        cout<<"Opcion invalida";
    }

    delete opc;

    return 0;
}