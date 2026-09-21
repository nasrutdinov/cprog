#include <iostream>
#include <algorithm>
#include <locale.h>
#include <windows.h>
#include "Vector.h"


int main() {

    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8); // Для корректного ввода, если нужен cin
    
    std::setlocale(LC_ALL, ".UTF8"); // Настройка стандартной библиотеки под UTF-8

    
    // 1. Демонстрация pop_back
    Vector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);

    vec.pop_back(); // Удалит 30

    std::cout << "После pop_back: ";
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << " ";
    }
    std::cout << "\n\n";

    // 2. Демонстрация оператора >>
    size_t n;
    std::cout << "Введите количество элементов для нового вектора: ";
    std::cin >> n;

    Vector<int> custom_vec(n); // Создаем вектор нужного размера
    std::cout << "Введите " << n << " чисел через пробел: ";
    std::cin >> custom_vec;     // Используем оператор >>

    std::cout << "Вы ввели: ";
    for (size_t i = 0; i < custom_vec.size(); ++i) {
        std::cout << custom_vec[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
