# Программа  - 1 семестр

## Лекция 1. 

Примерная программа курса. Программирование на языке C++. Этапы компиляции C++. 
Программа HelloWorld.  

Варианты установки: MinGW (MSYS2) + VS Code, Visual Studio, Embarcadero Dev-C++ и Dev-C++, replit.com, ...

Первая программа. Типы данных. Простейшие операторы. 


## Лекция 2.  Управляющие конструкции 
 
```C
// IfEx.cpp : Вводятся два числа. Выводится  1, если (a-b)>0, 
//-1 если (a-b)<0 и 0,  если (a-b)=0 

#include <iostream>

using namespace std;

int main()
{
	double a, b;
	int sign = 0;
	cout << "input a,b: \n";
	cin >> a >> b;
	
	if (a > b)
	{
		sign = 1;
	}
	else 
	{
		if (a < b) {sign = -1;}
	}
	cout << "compare(a,b)= " << sign << "\n";

	return 0;
}
```

## ? 
1. Git
2. Cmake
3. Тестирование 


