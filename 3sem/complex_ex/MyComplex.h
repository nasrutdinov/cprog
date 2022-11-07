#pragma once

#include<iostream>

class MyComplex         // ����� "����������� �����"
{
//private:
public:
	double re, im;      // �������������� � ������ �����


	// ������������

	MyComplex();
	MyComplex(double r);
	MyComplex(double r, double i);
	MyComplex(const MyComplex &c);   // ����������� �����������
	// ����������
	~MyComplex();
	// ��������� �������
	// ������ ������������ �����
	double abs();
	// �������� ������������
	MyComplex& operator = (MyComplex &c);
	// �������� +=
	MyComplex& operator + (MyComplex &c);
	//friend std::ostream & operator << (std::ostream &os, MyComplex &c);
	friend std::istream& operator>> (std::istream &in, MyComplex &c);
};

std::ostream & operator << (std::ostream &os, MyComplex &c);


