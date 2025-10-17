#include <iostream>

int main(void){
    int num = 5;
    std::cout<<"El valor actual de num es: "<<num<<std::endl<<"Su direccion es: "<<&num;
    int* ptrnum = new int;
    ptrnum=&num;
    std::cout<<std::endl<<"Puntero creado con direccion: "<<ptrnum<<std::endl;
    std::cout<<"Ingrese un numero para asignar: ";
    std::cin>>*ptrnum;
    std::cout<<"El puntero con direccion: " <<ptrnum<<std::endl<<"Al desreferenciarlo da: "<<*ptrnum<<std::endl;

    double numDouble = 5.4;

    double* ptrnumDouble = new double;
    double** ptraPtrDouble = new double*;

    ptrnumDouble=&numDouble;
    ptraPtrDouble=&ptrnumDouble;

    std::cout<<"El valor de numDouble: "<<**ptraPtrDouble<<std::endl;
    std::cout<<"Direccion en ptraPtr: "<<ptraPtrDouble<<std::endl;
    std::cout<<"Direccion de ptrnumDouble: "<<&ptrnumDouble<<std::endl;
    std::cout<<"Direccion de numDouble: "<<&numDouble; 
    

} 