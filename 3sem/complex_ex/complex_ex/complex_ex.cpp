// complex_ex.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "MyComplex.h"

using namespace std;

int main()
{
	MyComplex a(5, 2);
	MyComplex b(3, -3);
	MyComplex z;

	cout << "a = " << a << "; b =" << b << endl;

	MyComplex c = a + b;


	cout << "enter re and im:" << endl;
	cin >> z;
	cout << "z=" << z << endl;

	return 0;
}


