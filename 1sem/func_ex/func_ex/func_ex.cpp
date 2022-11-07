// func_ex.cpp : Пример описания функции 
//

#include <iostream>
using namespace std;

//функция вычисления факториала n!
float fact(int n)// заголовок функции
{
	float result = 1;
	for (int i = 2; i <= n; i++) // цикл вычисления значения n!
		result *= i; // накапливаем произведение в переменной result
	
	return result;
}

//прототип функции
void swap(int x, int y);
void swap2(int &x, int&y);

int main(int argc, char* argv[])
{
	//int n; 
	//cout << "Enter number: \n";
	//cin >> n;
	//cout<<"n!=" << fact(n)<<endl;// запуск функции нахождения факториала

	int x = 2, y = 5;
	cout << "before func: \n";
	cout << "x=" << x << endl;
	cout << "y=" << y << endl;

	swap(x, y);

	cout << "after func: \n";
	cout << "x=" << x << endl;
	cout << "y=" << y << endl;

	cout << "before func2: \n";
	cout << "x=" << x << endl;
	cout << "y=" << y << endl;

	swap2(x, y);

	cout << "after func2: \n";
	cout << "x=" << x << endl;
	cout << "y=" << y << endl;
	
	return 0;
}

//описание функции
void swap(int x, int y) {
	int z = x;
	x = y;
	y = z;
	cout << "inside func: \n";
	cout << "x=" << x<<endl; 
	cout << "y=" << y << endl;

}

void swap2(int &x, int&y) {
	int z = x;
	x = y;
	y = z;
	cout << "inside func2: \n";
	cout << "x=" << x << endl;
	cout << "y=" << y << endl;

}