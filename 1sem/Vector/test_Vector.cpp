#include <gtest/gtest.h>
#include <sstream>
#include "Vector.h"

// Тест конструктора по умолчанию
TEST(VectorTest, DefaultConstructor) {
    Vector<int> v;
    EXPECT_EQ(v.size(), 0);
    EXPECT_EQ(v.capacity(), 0);
}

// Тест конструктора с размером
TEST(VectorTest, SizeConstructor) {
    Vector<int> v(5);
    EXPECT_EQ(v.size(), 5);
    EXPECT_EQ(v.capacity(), 5);
    // Проверка инициализации нулями (гарантируется new T[cap]())
    for (size_t i = 0; i < 5; ++i) {
        EXPECT_EQ(v[i], 0);
    }
}

// Тест добавления элементов и автоматического увеличения емкости (reallocation)
TEST(VectorTest, PushBackAndReallocation) {
    Vector<int> v;
    EXPECT_EQ(v.capacity(), 0);
    
    v.push_back(10);
    EXPECT_EQ(v.size(), 1);
    EXPECT_EQ(v.capacity(), 1);
    EXPECT_EQ(v[0], 10);

    v.push_back(20); // Триггер реаллокации: cap 1 -> 2
    EXPECT_EQ(v.size(), 2);
    EXPECT_EQ(v.capacity(), 2);
    EXPECT_EQ(v[0], 10); // Старые данные должны сохраниться
    EXPECT_EQ(v[1], 20);

    v.push_back(30); // Триггер реаллокации: cap 2 -> 4
    EXPECT_EQ(v.size(), 3);
    EXPECT_EQ(v.capacity(), 4);
    EXPECT_EQ(v[2], 30);
}

// Тест удаления элементов с конца
TEST(VectorTest, PopBack) {
    Vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    EXPECT_EQ(v.size(), 3);

    v.pop_back();
    EXPECT_EQ(v.size(), 2);
    EXPECT_EQ(v[0], 1);
    EXPECT_EQ(v[1], 2);

    v.pop_back();
    v.pop_back();
    EXPECT_EQ(v.size(), 0);

    // Крайний случай: вызов pop_back на пустом векторе не должен вызывать краш
    // (согласно вашей реализации с проверкой if (sz > 0))
    EXPECT_NO_THROW(v.pop_back());
}

// Тест конструктора копирования (проверка глубокого копирования)
TEST(VectorTest, CopyConstructor) {
    Vector<int> v1;
    v1.push_back(100);
    v1.push_back(200);

    Vector<int> v2(v1);
    EXPECT_EQ(v2.size(), 2);
    EXPECT_EQ(v2.capacity(), 2);
    EXPECT_EQ(v2[0], 100);
    EXPECT_EQ(v2[1], 200);

    // Изменяем копию, оригинал должен остаться нетронутым
    v2[0] = 999;
    EXPECT_EQ(v1[0], 100); 
}

// Тест оператора присваивания копированием
TEST(VectorTest, CopyAssignmentOperator) {
    Vector<int> v1;
    v1.push_back(10);
    v1.push_back(20);

    Vector<int> v2;
    v2.push_back(99); // Придаем v2 начальное состояние, которое должно быть перезаписано

    v2 = v1;
    EXPECT_EQ(v2.size(), 2);
    EXPECT_EQ(v2[0], 10);
    EXPECT_EQ(v2[1], 20);

    // Проверка независимости памяти (глубокое копирование)
    v1[0] = 555;
    EXPECT_EQ(v2[0], 10);
}

// Тест оператора ввода из потока (operator>>)
TEST(VectorTest, StreamInputOperator) {
    // Важно: ваш operator>> читает ровно vec.sz элементов.
    // Поэтому размер должен быть задан заранее.
    Vector<int> v(3); 
    
    std::istringstream input("10 20 30");
    input >> v;

    EXPECT_EQ(v.size(), 3);
    EXPECT_EQ(v[0], 10);
    EXPECT_EQ(v[1], 20);
    EXPECT_EQ(v[2], 30);
}

// Тест константного оператора []
TEST(VectorTest, ConstOperatorBracket) {
    Vector<int> v;
    v.push_back(42);
    
    // Передаем в функцию, принимающую const ссылку
    auto get_first = [](const Vector<int>& vec) {
        return vec[0];
    };

    EXPECT_EQ(get_first(v), 42);
}