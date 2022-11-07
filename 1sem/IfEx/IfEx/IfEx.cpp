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

