// sort_ex.cpp : Примеры программ сортировки массива по убыванию, подсчет времени
//

#include <iostream>
#include <ctime>

#include <fstream>

using namespace std;

const int n = 10000;
const int number_count = 200;

void insert_sort(int a[], int size) {
	for (int i = 1; i < size; ++i) {
		int j = i;
		while ((j > 0) && (a[j] > a[j - 1])) {
			int c = a[j];
			a[j] = a[j - 1];
			a[j - 1] = c;
			--j;
		}
	}
}

void copy_array(int a[], int b[], int m) {
	for (int i = 0; i < m; ++i) {
		b[i] = a[i];
	}		
}

void print_array(int *a, int size) {
	cout << endl;
	for (int i = 0; i < n; ++i) {
		cout<<a[i] <<"\t";
	}
}

int main()
{
	//задаем начальное значение в псевдослучайной последовательности
	srand(42);
	int a[n], b[n], c[n];
	float time[number_count];

	for (int i = 0; i < n; ++i) {
		//заполнение массива случайными значениями
		a[i] = rand();
		//заполнение массива, отсортированного в обратном порядке
		b[i] = i;
	}

	////Вывод массива
	//cout << "a = \n";
	//for (int i = 0; i < n; ++i) {
	//	cout<<a[i] <<"\t";
	//}

	//print_array(a, n);

	cout << endl;

	float start = clock();

	//for (int i = 1; i < n; ++i) {
	//	int j = i;
	//	while ((j > 0) && (a[j] > a[j - 1])) {
	//		int c = a[j];
	//		a[j] = a[j - 1];
	//		a[j - 1] = c;
	//		--j;
	//	}
	//}

	insert_sort(a,n);
	cout << "sorted array \n";
	//print_array(a, n);

	float end = clock();
	cout << "time 1 =" << (end - start)/CLOCKS_PER_SEC << "\n";

	//insert_sort(b, n);
	//for (int i = 1; i < n; ++i) {
	//	int j = i;
	//	while ((j > 0) && (b[j] > b[j - 1])) {
	//		int c = b[j];
	//		b[j] = b[j - 1];
	//		b[j - 1] = c;
	//		--j;
	//	}
	//}

	//cout << "time 2 =" << (clock() - end) / CLOCKS_PER_SEC << "\n";

	//cout << "sorted a = \n";
	//for (int i = 0; i < n; ++i) {
	//	cout << a[i] << "\t";
	//}

	//print_array(b, n);

	int counts = n / number_count;
	for (int i = 0; i < counts; ++i) {
		int size = number_count * i;
		copy_array(b, c, size);
		float start = clock();
		insert_sort(c, size);
		time[i] = (clock() - start);
	}

	ofstream out("time.txt");
	
	for (int i = 0; i < counts; ++i) {
		out << time[i] << "\n";
	}
    
}

