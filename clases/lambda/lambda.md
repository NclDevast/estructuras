# Expresiones Lambda
Una expresion lambda es una forma de declarar funciones anonimas sin la necesidad de 
declarar un prototipo
> sintaxis: tipodato nombreFunc = [captura] (parametros) { codigo }

|sintaxis | descripcion|
|---------|------------|
|captura|La clausala de captura permite a la expresion lambda acceder a variables que no sean pasadas como parámetros y que existan fuera del ámbito de la expresión|
|parametros|Permite a la expresion recibir argumentos tal como una funcion normal|


```cpp
#include <iostream>

    int main() {
        auto mensaje = []() {
        std::cout << "Hola mundo!\n";
    };

    mensaje();
    return 0;
}
```
> output: "Hola mundo!"

## Lambda como parametro a funciones

Una funcion puede recibir una expresión lambda como parámetro

```cpp
#include <iostream>
#include <functional>

void myFunction(std::function<void()> func) {
  func();
  func();
}

int main() {
  auto message = []() {
    cout << "Hello World!\n";
  };

  myFunction(message);
  return 0;
}


```

## Captura por referencia

Una expresión puede recibir como clausala de captura cualquier parámetro por referencia sin la necesidad de declararlo previamente como puntero

```cpp

int main() {
  int x = 10;

  auto show = [&x]() {
    cout << x;
  };

  x = 20;  // Cambiar x despues de que la expresion lambda sea creada

  show();
  return 0;
}

```

## Expresion lambda vs Funciones tradicionales

|Expresion lambda|Funciones tradicionales|
|---|---|
|Usarla cuando se necesite usar la función una vez|Usarla cuando planea usarse una funcion varias veces|
|Usarla cuando se necesite pasar una función a otra función como parámetro| La lógica sea extensa o compleja|
