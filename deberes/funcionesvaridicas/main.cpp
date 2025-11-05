#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <numeric>
#include <utility> // Para std::apply (C++17) o std::forward (C++11)
#include <tuple>   // Necesario para std::apply (C++17)

// 1. Multiplicar N Enteros
long long multiplicar() {
    return 1;
}

template <typename T, typename... Args>
long long multiplicar(T head, Args... tail) {
    return (long long)head * multiplicar(tail...);
}

// 2. Concatenación de Caracteres
template <typename... Chars>
std::string concatenar_chars(Chars... chars) {
    std::string resultado = "";
    ((resultado += (char)chars), ...); 
    return resultado;
}

// 3. Cálculo de la Media Aritmética (Promedio)
template <typename... Args>
double promedio(Args... args) {
    size_t n = sizeof...(args);
    if (n == 0) return 0.0;
    double suma = (double{} + ... + args); 
    return suma / n;
}

// 4. Búsqueda de un Número en una Lista
template <typename T, typename... Args>
bool buscar_numero(T target, Args... args) {
    return (false || ... || (args == target));
}

// Funciones Auxiliares para Input
template <typename T>
std::vector<T> leer_elementos(int n, const std::string& tipo_nombre) {
    std::vector<T> elementos;
    T valor;
    std::cout << "Ingrese los " << n << " " << tipo_nombre << "s:" << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cout << tipo_nombre << " " << i + 1 << ": ";
        while (!(std::cin >> valor)) {
            std::cout << "Error. Ingrese un " << tipo_nombre << " válido: ";
            std::cin.clear(); 
            std::cin.ignore(10000, '\n');
        }
        elementos.push_back(valor);
    }
    return elementos;
}

// Función main con el driver de demostración
int main() {
    int opcion;

    do {
        std::cout << "\n--- MENU DE PLANTILLAS VARIÁDICAS C++ ---\n";
        std::cout << "1. Multiplicar N Enteros\n";
        std::cout << "2. Concatenar N Caracteres\n";
        std::cout << "3. Calcular el Promedio de N Doubles\n";
        std::cout << "4. Buscar Número en N Enteros\n";
        std::cout << "0. Salir\n";
        std::cout << "Seleccione una opción: ";

        if (!(std::cin >> opcion)) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            opcion = -1;
        }

        if (opcion > 0 && opcion < 5) {
            int n;
            std::cout << "Ingrese la cantidad de elementos (N): ";
            if (!(std::cin >> n) || n <= 0) {
                std::cout << "Cantidad inválida o error de lectura.\n";
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                continue;
            }

            switch (opcion) {
                case 1: { 
                    auto nums = leer_elementos<int>(n, "entero");
                    if (!nums.empty()) {
                        long long resultado = std::apply([](auto... args) {
                            return multiplicar(args...);
                        }, nums); 
                        std::cout << "Resultado de la multiplicación: " << resultado << "\n";
                    }
                    break;
                }
                case 2: { 
                    auto chars = leer_elementos<char>(n, "carácter"); 
                    if (!chars.empty()) {
                        std::string resultado = std::apply([](auto... args) {
                            return concatenar_chars(args...);
                        }, chars);
                        std::cout << "Resultado de la concatenación: " << resultado << "\n";
                    }
                    break;
                }
                case 3: { 
                    auto doubles = leer_elementos<double>(n, "double");
                    if (!doubles.empty()) {
                        double resultado = std::apply([](auto... args) {
                            return promedio(args...);
                        }, doubles);
                        std::cout << "Resultado del promedio: " << resultado << "\n";
                    }
                    break;
                }
                case 4: { 
                    int target;
                    std::cout << "Ingrese el número a buscar (Target): ";
                    if (!(std::cin >> target)) {
                        std::cout << "Error al leer el target.\n";
                        std::cin.clear();
                        std::cin.ignore(10000, '\n');
                        break;
                    }
                    
                    auto search_nums = leer_elementos<int>(n, "entero de la lista");
                    if (!search_nums.empty()) {
                        bool encontrado = std::apply([target](auto... args) {
                            return buscar_numero(target, args...);
                        }, search_nums);
                        
                        std::cout << "Resultado: El número " << target 
                                  << (encontrado ? " fue encontrado.\n" : " NO fue encontrado.\n");
                    }
                    break;
                }
            }
        } else if (opcion == 0) {
            std::cout << "Saliendo del programa. ¡Hasta la próxima refactorización!\n";
        } else {
            std::cout << "Opción no válida. Intente de nuevo.\n";
        }

    } while (opcion != 0);

    return 0;
}