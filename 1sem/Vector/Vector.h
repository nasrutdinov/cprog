#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <algorithm>

template <typename T> class Vector;
template <typename T> std::istream& operator>>(std::istream& in, Vector<T>& vec);


template <typename T>
class Vector {
private:
    T* data;         // Указатель на массив в куче
    size_t sz;       // Текущее количество элементов
    size_t cap;      // Вместимость (выделенная память)

public:
    // Конструкторы и деструктор
    Vector();
    explicit Vector(size_t n);
    ~Vector();

    // Управление памятью
    Vector(const Vector& other);
    Vector& operator=(Vector other);

    // Методы изменения размера
    void push_back(const T& value);
    void pop_back();

    // Доступ к элементам
    T& operator[](size_t index);
    const T& operator[](size_t index) const;

    // Информационные методы
    size_t size() const;
    size_t capacity() const;
    //friend std::istream& operator>> <T>(std::istream& in, Vector<T>& vec);
        // Реализация прямо здесь, внутри класса. 
    // Она автоматически получает доступ к private полям!
    friend std::istream& operator>>(std::istream& in, Vector<T>& vec) {
        for (size_t i = 0; i < vec.sz; ++i) {
            in >> vec.data[i];
        }
        return in;
    }
};

#endif // VECTOR_H