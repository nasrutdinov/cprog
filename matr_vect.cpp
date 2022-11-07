// matr_vect.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include<hash_set>

using namespace std;

int main()
{
    std::cout << "Hello World!\n";

	int n = 1000;
	vector<vector<float>> A;
	A.resize(n);
	for (int k = 0; k < n; ++k) {
		A[k].resize(n);
	}
	for (int i = 0; i < n; ++i) 
		for (int j = 0; j < n; ++j) {
			A[i][j] = i + j;
	}
	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 10; ++j) {
			cout<<A[i][j] <<"\t";
		}
		cout << endl;
	}

}

