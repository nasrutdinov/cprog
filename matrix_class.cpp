// test.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;



class matrix {
private:
	int count_row;
	int count_column;
	double **elements;
public:	
	matrix() {};
	matrix(int , int);
	void print();
	void set_element(int, int, double);
	void smooth();
	friend  matrix operator + (matrix &A, const matrix &B);
	friend  matrix operator - (matrix &A, const matrix &B);
};

int main()
{
	const int m = 3;
	const int n = 4;
	
	matrix A(m,n);
	//matrix B;

	A.print();

	for (int i=0; i<5;i++)
		A.smooth();
	A.print();

	/*(A + A).print();

	(A - A).print();*/

	/*B = A + A;

	cout << "A+A=" << endl;
	(A + A).print();

	cout << "A=" << endl;
	A.print();

	cout << "B=" << endl;
	B.print();


	cout << "addres A=" << &A << "\t size=" <<sizeof(A)<<"\n";
	cout<<"addres B="<< &B<< "\t size=" << sizeof(B) << "\n";*/

	//matrix C(m, n);
	//for (int i = 0; i < m; i++)
	//	for (int j = 0; j < n; j++)
	//		C.set_element(i,j, 30*i+j);

	//C.print();

	//(A-C).print();

}


matrix::matrix(int m, int n) {
	this->count_row = m;
	//count_row = m;
	this->count_column = n;
	//count_column = n;

	elements = new double*[count_row];

	for (int i = 0; i < count_row; i++) {
		elements[i] = new double[count_column];
		for (int j = 0; j < count_column; j++)
			elements[i][j] = 10*i+j;
	}
		
}

void matrix::print() {
	std::cout << std::endl;
	for (int i = 0; i < count_row; i++) {
		for (int j = 0; j < count_column; j++)
			std::cout << elements[i][j] << "\t";
		std::cout << std::endl;
	}
}

void matrix::set_element(int i, int j, double a) {
	elements[i][j] = a;
}

matrix operator + (matrix &A, const matrix &B) {
	for (int i = 0; i < A.count_row; i++)
		for (int j = 0; j < A.count_column; j++)
			A.elements[i][j] = A.elements[i][j] + B.elements[i][j];
	return A;
}

matrix operator - (matrix &A, const matrix &B) {
	for (int i = 0; i < A.count_row; i++)
		for (int j = 0; j < A.count_column; j++)
			A.elements[i][j] = A.elements[i][j] - B.elements[i][j];
	return A;
}

void matrix::smooth() {
	double *c = new double[count_row];

	for (int i = 0; i < count_row; i++) {
		for (int j = 0; j < count_column; j++)
			c[j] = elements[i][j];
		for (int j = 1; j < count_column - 1; j++)
			elements[i][j] = (c[j-1] + c[j+1])/10;
	}
}

/*
1 2   21
4 5   22  


*/