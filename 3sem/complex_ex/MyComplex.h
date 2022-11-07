#pragma once

#include<iostream>

class MyComplex         // класс "Комплексное число"
{
//private:
public:
	double re, im;      // действительная и мнимая части


	// конструкторы

	MyComplex();
	MyComplex(double r);
	MyComplex(double r, double i);
	MyComplex(const MyComplex &c);   // конструктор копирования
	// деструктор
	~MyComplex();
	// остальные функции
	// Модуль комплексного числа
	double abs();
	// оператор присваивания
	MyComplex& operator = (MyComplex &c);
	// оператор +=
	MyComplex& operator + (MyComplex &c);
	//friend std::ostream & operator << (std::ostream &os, MyComplex &c);
	friend std::istream& operator>> (std::istream &in, MyComplex &c);
};

std::ostream & operator << (std::ostream &os, MyComplex &c);


