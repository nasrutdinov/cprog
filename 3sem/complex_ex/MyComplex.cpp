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

MyComplex::MyComplex(const MyComplex &c)   // ����������� �����������
	{
		re = c.re;
		im = c.im;
	}

	// ����������
	MyComplex::~MyComplex()
	{
	}

	// ��������� �������

	// ������ ������������ �����
	double MyComplex::abs()
	{
		return sqrt(re * re + im * im);
	}

	// �������� ������������
	MyComplex& MyComplex::operator = (MyComplex &c)
	{
		re = c.re;
		im = c.im;

		return (*this);
	}

	// �������� +=
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

