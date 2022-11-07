// test_matrix_vector.cpp : Двумерный массив через векторы
//

#include <iostream>
#include <vector>

int main()
{
	int m = 10;
	int n = 10;

	std::vector<std::vector<float>> a(m, std::vector<float> (n)) ;

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++)
			a[i][j] = 100 * i + j;
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			std::cout << a[i][j] << "\t";
		}
		std::cout << "\n";
	}
	return 0;
}

