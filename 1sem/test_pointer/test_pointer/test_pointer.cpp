/* описание указателей, динамическое выделение памяти */

#include <iostream> 
#include <fstream> 
#include <vector> 

using namespace std;

//void PrintArray(float **a, int m, int n) {
//
//	for (int i = 0; i < m; ++i) {
//		for (int j = 0; j < n; ++j) {
//			cout << a[i][j] << "\t";
//		}
//		cout << endl;
//	}
//}

void changeArray( int m, int n, float **a) {
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			a[i][j]+=1000;
		}
	}
}

void PrintArray(int m, int n, float *a[]) {

	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << a[i][j] << "\t";
		}
		cout << endl;
	}
}

void PrintArray(vector<vector<float>> a) {

	for (int i = 0; i < a.size(); ++i) {
		for (int j = 0; j < a[i].size(); ++j) {
			cout << a[i][j] << "\t";
		}
		cout << endl;
	}
}

void PrintArray2(int m, int n, float a[]) {

	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << a[i*m+j] << "\t";
		}
		cout << endl;
	}
}

int main(int argc, char** argv) {
	const int m = 3;
	const int n = 3;
	/*int m = 3;
	int n = 3; */

	vector<vector<float>> V = { {2,0,0},
	{0,2,0},
	{0,0,2}
	};

	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << V[i][j] << "\t";
		}
		cout << endl;
	}

	//PrintArray(V);


	//ifstream in("file.txt");

	float **a;
	a = new float*[m];
	for (int i = 0; i < m; i++)
		a[i] = new float[n];

	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			//a[i][j]=i+j;  
			//in >> a[i][j];
			a[i][j] = i + j;
		}
	}

	//in.close();

	cout << "a= \n";
	//PrintArray(a, m, n);
	PrintArray(m, n, a);

	cout << "a= \n";
	changeArray(m,n, a); 
	PrintArray(m, n, a);
	
	//умножение матриц 
	float b[m][n] = { {1,0,0},
	{0,1,0},
	{0,0,1}
	};

	cout << "b= \n";
	PrintArray2(m,n, &b[0][0]); 
	
	float **c = new float*[m];
	for (int i = 0; i < m; i++)
		c[i] = new float[n];
	   
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			c[i][j] = 0;
			for (int k = 0; k < n; k++)
				c[i][j] += a[i][k] * b[k][j];
		}
	}

	cout << "c= \n";
	//PrintArray(c, m, n);

	for (int i = 0; i < m; i++)
		delete[] a[i];
	delete[] a;

	return 0;

}