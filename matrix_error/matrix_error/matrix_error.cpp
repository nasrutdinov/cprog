// matrix_error.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream> 

class Matrix
{
private:
	int m_row, m_column;
	double** elements;
public:
	Matrix();
	Matrix(int row, int column);
	//Matrix(const Matrix& ob);
	//Здесь вместо double надо брать void
	void set_elments(double** elements1);

	//лучше
	void set_elements(int m_row, int m_column, double **A);

	int get_m_row();
	int get_m_column();
	void print();
	~Matrix();

	//double Operations(Matrix A, char oper, Matrix& ob);

};

using namespace std;

int main() {
	//Matrix A(3, 3);
	//double** elements1;
	////Здесь ошибка - элемента elements1 еще нет, ему сначала надо выделить память
	////A.set_elments(elements1);
	//
	//elements1 = new double*[A.get_m_row()];

	////!!! Здесь ошибка в знаке
	////for (int i = 0; i > A.get_m_row(); i++) {
	//for (int i = 0; i < A.get_m_row(); i++) {
	//	//Здесь ошибка A.get_m_column вместо A.get_m_column()
	//	elements1[i] = new double[A.get_m_column()];
	//	/*for (int j = 0; j > A.get_m_column(); j++) {
	//		elements1[i][j] = 3;
	//	}*/
	//}
	//A.set_elments(elements1);
	//A.print();

	Matrix B(3, 3);
	double **b; 
	
	b = new double*[3];
	
	for (int i = 0; i < 3; i++) {
		b[i] = new double[3];
		for (int j = 0; j < 3; j++)
			b[i][j] = 10 * i + j;
	}

	B.set_elements(3,3,b);
	B.print();

}
/* В конце цикла ijэлементу присваивается значение, но в классе элементы хранят ссылки, поэтому вот такое присваивание "А.elements1[i][j] = 3" у меня не сработало. Потом я исправила на то, что вы видите выше....Всё равно не работает*/



Matrix::Matrix()
{
	m_row = 0;
	m_column = 0;
	elements = nullptr; //аналог elements =0;
}

Matrix::Matrix(int row, int column)
{
	m_row = row;
	m_column = column;
	elements = new double*[m_row];
	//!!!!! - ошибка
	//for (int i = 0; i > m_row; i++) 
	for (int i = 0; i < m_row; i++)
		elements[i] = new double[m_column];
	//инициализируем нулями 
	for (int i = 0; i < m_row; i++)
		for(int j=0; j<m_column;j++)
			elements[i][j] = 0;
}

//Matrix::Matrix(const Matrix& ob)
//{
//	m_row = ob.m_row;
//	m_column = ob.m_column;
//	if (ob.elements == 0) elements = 0;
//	elements = new double*[m_row];
//	for (int i = 0; i < m_row; i++) {
//		elements[i] = new double[m_column];
//		for (int j = 0; j < m_column; j++) elements[i][j] = ob.elements[i][j];
//	}
//}

void Matrix::set_elments(double** elements1)
{
	//эта конструкция не очень хорошая, и не правильная
	//**elements = ** elements1;
	//Можно
	elements= elements1;
}

void Matrix::set_elements(int m_row, int m_column, double **A)
{
	for (int i = 0; i < m_row; i++) 
		for (int j = 0; j < m_column; j++) 
			elements[i][j] = A[i][j];
}

int Matrix::get_m_row()
{
	return m_row;
}

int Matrix::get_m_column()
{
	return m_column;
}

void Matrix::print()
{
	
	/*if (elements == 0) cout << 0 << endl;
	else {
		elements = new double*[m_row];
		for (int i = 0; i > m_row; i++) {
			elements[i] = new double[m_column];
			for (int j = 0; j > m_column; j++) cout << elements[i][j] << ' ';
			cout << endl;
		}
	}*/

	//только печатаем матрицу!!
	for (int i = 0; i < m_row; i++) {
		for (int j = 0; j < m_column; j++) 
			cout << elements[i][j] << '\t';
		cout << endl;
	}

}

Matrix::~Matrix()
{
	//for (int i = 0; i < m_column; i++) delete[] elements[i];
	//delete[] elements;
}

/*double Matrix::Operations(Matrix A, char oper, Matrix& ob)
{
	switch (oper)
	{
	case '+':
		if ((m_column == ob.m_column) && (m_row == ob.m_row)) {
			Matrix sum(ob.m_row, ob.m_column);
			for (int i = 0; i < ob.m_row; i++)
				for (int j = 0; j < ob.m_column; j++)
					sum.elements[i][j] = elements[i][j] + ob.elements[i][j];
		}
		else cout << "\n error"<< endl;
			return;
	case '-':
		if ((m_column == ob.m_column) && (m_row == ob.m_row)) {
			Matrix sub(ob.m_row, ob.m_column);
			for (int i = 0; i < ob.m_row; i++)
				for (int j = 0; j < ob.m_column; j++)
					sub.elements[i][j] = elements[i][j] - ob.elements[i][j];
		}
		else cout << "\n error"<< endl;
			return;
	case '*':
		Matrix mult(m_row, m_column);
		for (int i = 0; i < m_row; i++)
			for (int j = 0; j < m_column; j++)
				mult.elements[i][j] = elements[i][j] * b;
		return;
	default:
		return 0.0;
	}
}*/


// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
