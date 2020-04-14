// matrix.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>


class Matrix {
public:
	int size;
	//данные надо убрать в private и сделать в виде динамического массива
	//float elements[3][3];
	float **elements;
	Matrix();
	// Пример https://prog-cpp.ru/cpp-operator/
	friend  Matrix operator + (Matrix &A, const Matrix &B);
};

int main()
{
	Matrix A, B;

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			A.elements[i][j] = 1;

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			B.elements[i][j] = i+j;

	std::cout << "B= \n";
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++)
			std::cout << B.elements[i][j] << "\t";
		std::cout << "\n";
	}

	std::cout << "A=  (before) \n";
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++)
			std::cout << A.elements[i][j] << "\t";
		std::cout << "\n";
	}

	A = A + B;

	std::cout << "A= (after) \n";
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++)
			std::cout << A.elements[i][j] << "\t";
		std::cout << "\n";
	}

	getchar();


  
}

Matrix::Matrix() {
	elements = new  float *[3];
	for (int i=0;i<3;i++)
		elements[i]= new float[3];

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			elements[i][j] = 0;
}

Matrix operator + (Matrix &A, const Matrix &B) {
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			A.elements[i][j] = A.elements[i][j] + B.elements[i][j];
	return A;
}



// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
