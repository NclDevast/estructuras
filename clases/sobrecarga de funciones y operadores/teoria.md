# Sobrecarga de operadores 

Consiste en crear una función que tome múltiples instancias de parámetros o de tipos de datos con un mismo nombre.

```cpp
template <typename T>
class Ejemplo{
    private:
    T ejemplo1;
    T ejemplo2;
    public:
    //constructores sobrecargados
    Ejemplo(){
        ejemplo1 = NULL;
        ejemplo2 = NULL
    }
    Ejemplo(T ej1, T ej2){
        ejemplo1=ej1;
        ejemplo2=ej2;
    }
}
```cpp
<br>
