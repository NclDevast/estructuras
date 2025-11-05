#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <numeric>

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

// =================================================================
// SOLUCIÓN C++11/14: WRAPPERS PARA LLAMAR PLANTILLAS CON VECTORES
// =================================================================

// Generador de secuencias de índices (C++11/14)
template<int...> struct index_sequence {};
template<int N, int... Is> struct make_index_sequence : make_index_sequence<N - 1, N - 1, Is...> {};
template<int... Is> struct make_index_sequence<0, Is...> : index_sequence<Is...> {};


// -----------------------------------------------------------------
// WRAPPERS GENÉRICOS DE LLAMADA
// -----------------------------------------------------------------

// Wrapper para multiplicar
template <typename T, int... Is>
long long call_multiplicar(const std::vector<T>& vec, index_sequence<Is...>) {
    // El 'Is...' desempaqueta el vector llamando a vec[0], vec[1], etc.
    return multiplicar(vec[Is]...);
}

// Wrapper para concatenar_chars
template <typename T, int... Is>
std::string call_concatenar_chars(const std::vector<T>& vec, index_sequence<Is...>) {
    return concatenar_chars(vec[Is]...);
}

// Wrapper para promedio
template <typename T, int... Is>
double call_promedio(const std::vector<T>& vec, index_sequence<Is...>) {
    return promedio(vec[Is]...);
}

// Wrapper para buscar_numero
template <typename T, int... Is>
bool call_buscar_numero(int target, const std::vector<T>& vec, index_sequence<Is...>) {
    return buscar_numero(target, vec[Is]...);
}




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

// =================================================================
// FUNCIÓN MAIN MODIFICADA (USANDO LOS WRAPPERS)
// =================================================================

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
                        long long resultado = call_multiplicar(nums, make_index_sequence<100>{}); // 100 es un límite seguro
                        std::cout << "Resultado de la multiplicación: " << resultado << "\n";
                    }
                    break;
                }
                case 2: { 
                    auto chars = leer_elementos<char>(n, "carácter"); 
                    if (!chars.empty()) {
                        std::string resultado = call_concatenar_chars(chars, make_index_sequence<100>{});
                        std::cout << "Resultado de la concatenación: " << resultado << "\n";
                    }
                    break;
                }
                case 3: { 
                    auto doubles = leer_elementos<double>(n, "double");
                    if (!doubles.empty()) {
                        double resultado = call_promedio(doubles, make_index_sequence<100>{});
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
                        bool encontrado = call_buscar_numero(target, search_nums, make_index_sequence<100>{});
                        
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