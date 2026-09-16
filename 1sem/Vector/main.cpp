#include <iostream>
#include <algorithm>
#include <locale.h>
#include <windows.h>

template <typename T>
class Vector {
private:
    T* data;         // Указатель на массив в куче
    size_t sz;       // Текущее количество элементов
    size_t cap;      // Вместимость (выделенная память)

public:
    // Конструктор по умолчанию
    Vector() : data(nullptr), sz(0), cap(0) {}

    // Конструктор с размером
    explicit Vector(size_t n) : sz(n), cap(n) {
        data = new T[cap](); // Инициализация нулями
    }

    // Деструктор
    ~Vector() {
        delete[] data;
    }

    // Конструктор копирования
    Vector(const Vector& other) : sz(other.sz), cap(other.cap) {
        data = new T[cap];
        for (size_t i = 0; i < sz; ++i) {
            data[i] = other.data[i];
        }
    }

    // Оператор присваивания копированием
    Vector& operator=(Vector other) {
        std::swap(data, other.data);
        std::swap(sz, other.sz);
        std::swap(cap, other.cap);
        return *this;
    }

    // Добавление элемента в конец
    void push_back(const T& value) {
        if (sz >= cap) {
            size_t new_cap = (cap == 0) ? 1 : cap * 2;
            T* new_data = new T[new_cap];
            for (size_t i = 0; i < sz; ++i) {
                new_data[i] = data[i];
            }
            delete[] data;
            data = new_data;
            cap = new_cap;
        }
        data[sz++] = value;
    }

    // Удаление элемента из конца
    void pop_back() {
        if (sz > 0) {
            sz--;
            // Для сложных типов (классов) здесь также вызывают деструктор: data[sz].~T();
        }
    }

    // Доступ по индексу
    T& operator[](size_t index) { return data[index]; }
    const T& operator[](size_t index) const { return data[index]; }

    size_t size() const { return sz; }
    size_t capacity() const { return cap; }

    // Перегрузка оператора >> для ввода вектора (считывает столько элементов, какой текущий size)
    friend std::istream& operator>>(std::istream& in, Vector<T>& vec) {
        for (size_t i = 0; i < vec.sz; ++i) {
            in >> vec.data[i];
        }
        return in;
    }
};

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
