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