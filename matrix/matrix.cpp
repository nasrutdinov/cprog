// matrix_program.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

class Matrix {
private:
	int row, column;
	
public:
	float **elements;
	Matrix() {};
	Matrix(int, int);
	void print();
};

int main()
{
	Matrix A(3, 3);

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			A.elements[i][j] = 10 * i + j;

	A.print();

    return 0;
}

Matrix::Matrix(int row, int column) {
	//int **massive;
	this->row = row;
	this->column = column;
	elements = new float*[row];
	for (int k = 0; k < row; k++)
		elements[k] = new float[column];

	
}

void Matrix::print() {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++)
			std::cout << elements[i][j] << "\t";
		std::cout << "\n";
	}
}

