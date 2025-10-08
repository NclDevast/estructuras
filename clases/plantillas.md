# **Plantillas en C++**

Las plantillas son funciones o clases que funcionan con diferentes tipos de datos, se declara como:

```cpp
template <typename T> //devuelve un valor T
T add(T a, T b) {
    return a + b;
}

int main() {
    cout << add<int>(5, 3) << "\n";
    cout << add<double>(2.5, 1.5) << "\n";
    return 0;
}
```
##*Clases template*##
Utiliza el mismo principio de la funcion, pero se le aplica a clases3
```cpp
template <typename T>
class Box {
  public:
    T value;
    Box(T v) {
      value = v;
    }
    void show() {
      cout << "Value: " << value << "\n";
    }
};

int main() {
  Box<int> intBox(50);
  Box<string> strBox("Hello");

  intBox.show();
  strBox.show();
  return 0;
}
```
Definiciones adicionales
typedef: es un sobrenombre a un tipo de dato
typename: le dice al compilador que es un tipo de dato generico
