class Matrix {
private: 
	int m;
	int n;
	double *elem;
public:
	Matrix(int m, int n) : m(m), n(n), elem(new double[m*n]) {
		for (int i = 0; i < n*m; i++)
			elem[i] = 0.;
	};
	double& at(int i, int j) {
		return elem[(i-1)*m + j-1];
	};
};

#include <iostream>

int main()
{
	Matrix A(3,3);

    std::cout << "Hello World!\n";
	std::cout << A.at(2,3)<<"\n";
}