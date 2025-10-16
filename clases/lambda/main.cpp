#include<iostream>
#include<functional>
#include<cmath>

double obtenerDato(std::function<double()> redondearNum);

int main(void){

    //auto le dice al compilador que asuma el tipo de dato que se va a retornar

    auto suma = [](int a, int b){
        return a+b;
    };

    std::cout<<"El resultado de la suma es: "<<suma(2,5);

    // Definir la lambda que capture el número del usuario
    double numusuario;
    std::cout<<"Ingrese un numero decimal, se va a redondear al numero entero mas cercano: ";
    std::cin>>numusuario;
    
    auto redondearNum = [numusuario](){
        return round(numusuario);
    };
    
    // Llamar a obtenerDato con la lambda que ya tiene el número capturado
    double resultado = obtenerDato(redondearNum);
    std::cout << "El número redondeado es: " << resultado << std::endl;
}

double obtenerDato(std::function<double()> redondearNum){
    return redondearNum(); // Llama a la función sin parámetros
}