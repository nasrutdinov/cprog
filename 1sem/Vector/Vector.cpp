#include "Vector.h"

// --- Реализация методов ---

template <typename T>
Vector<T>::Vector() : data(nullptr), sz(0), cap(0) {}

template <typename T>
Vector<T>::Vector(size_t n) : sz(n), cap(n) {
    data = new T[cap](); // Инициализация нулями
}

template <typename T>
Vector<T>::~Vector() {
    delete[] data;
}

template <typename T>
Vector<T>::Vector(const Vector& other) : sz(other.sz), cap(other.cap) {
    data = new T[cap];
    for (size_t i = 0; i < sz; ++i) {
        data[i] = other.data[i];
    }
}

template <typename T>
Vector<T>& Vector<T>::operator=(Vector other) {
    std::swap(data, other.data);
    std::swap(sz, other.sz);
    std::swap(cap, other.cap);
    return *this;
}

template <typename T>
void Vector<T>::push_back(const T& value) {
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

template <typename T>
void Vector<T>::pop_back() {
    if (sz > 0) {
        sz--;
        // Для сложных типов (классов) здесь также вызывают деструктор: data[sz].~T();
    }
}

template <typename T>
T& Vector<T>::operator[](size_t index) { 
    return data[index]; 
}

template <typename T>
const T& Vector<T>::operator[](size_t index) const { 
    return data[index]; 
}

template <typename T>
size_t Vector<T>::size() const { 
    return sz; 
}

template <typename T>
size_t Vector<T>::capacity() const { 
    return cap; 
}

// template <typename T>
// std::istream& operator>>(std::istream& in, Vector<T>& vec) {
//     for (size_t i = 0; i < vec.sz; ++i) {
//         in >> vec.data[i];
//     }
//     return in;
// }




// --- Явная инстанциация шаблона ---
// Компилятор генерирует код для Vector<int> именно в этом файле,
// что позволяет линковщику найти реализации методов при сборке main.cpp
//template class Vector<int>;


// 3. ВАЖНО: Явная инстанциация самой friend-функции для int!
//template std::istream& operator>> <int>(std::istream& in, Vector<int> &vec);