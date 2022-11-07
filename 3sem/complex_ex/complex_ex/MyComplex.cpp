#include "MyComplex.h"
#include <cmath>


MyComplex::MyComplex() {}

MyComplex::MyComplex(double r)
	{
		re = r;
		im = 0;
	}

MyComplex::MyComplex(double r, double i)
	{
		re = r;
		im = i;
	}

MyComplex::MyComplex(const MyComplex &c)   // конструктор копирования
	{
		re = c.re;
		im = c.im;
	}

	// деструктор
	MyComplex::~MyComplex()
	{
	}

	// остальные функции

	// Модуль комплексного числа
	double MyComplex::abs()
	{
		return sqrt(re * re + im * im);
	}

	// оператор присваивания
	MyComplex& MyComplex::operator = (MyComplex &c)
	{
		re = c.re;
		im = c.im;

		return (*this);
	}

	// оператор +=
	MyComplex& MyComplex::operator + (MyComplex &c)
	{
		re += c.re;
		im += c.im;
		return *this;
	}

	std::ostream & operator << (std::ostream & os, MyComplex &c) {
		os << c.re << " +I*" << c.im;
		return os;
	}

	std::istream& operator>> (std::istream &in, MyComplex &c) {
		in >> c.re;
		in >> c.im;
		return in;
	}

