#include <iostream>

using namespace std;

int main (void){

//las clases son un tipo de tda

    class Fraccion{

        public:

        //constructores son metodos que se llaman al crear una instancia de clase
        
        Fraccion(){
            Numerador=NULL;
            Denominador=1;
        }

        //sobrecarga de metodos: Significa hacer un mismo metodo con difentes parametros
        Fraccion(double numerador, double denominador){
            Numerador=numerador;
            Denominador=denominador;
        }

        //metodo para multiplicar fracciones;

        Fraccion multiplicarFracciones(Fraccion frac1, Fraccion frac2){

            double resultadoNumerador= frac1.getNumerador()*frac2.getNumerador();
            double resultadoDenominador= frac1.getDenominador()*frac2.getDenominador();

            Fraccion fraccionresultado(resultadoNumerador,resultadoDenominador);
            return fraccionresultado;

        }
        
        //getters y setters

        double getNumerador(){
            return Numerador;
        }
        double getDenominador(){
            return Denominador;
        }

        void setNumerador(double numerador){
            Numerador = numerador;
        }

        void setDenominador(double denominador){
            Denominador = denominador;
        }

        private:

        double Numerador;
        double Denominador;

    };


    Fraccion fr1, fr2 , fr3;

    //fr1
    fr1.setNumerador(5);
    fr1.setDenominador(6);

    //fr2
    fr2.setNumerador(7);
    fr2.setDenominador(8);

    fr3 = fr1.multiplicarFracciones(fr1,fr2);
}