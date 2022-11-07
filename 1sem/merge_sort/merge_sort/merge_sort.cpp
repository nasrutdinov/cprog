// merge_sort.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

float * merge(float *a, float *b, int m, int n) {
	float *c = new float[m + n];
	int i = 0, j = 0, k = 0;
	while ((i < m) && (j < n)) {
		if (a[i] < b[j]) {
			c[k++] = a[i++];
		}
		else {
			c[k++] = b[j++];
		}
	}
	while (i < m) c[k++] = a[i++];
	while (j < n) c[k++] = b[j++];

	return c;
}


float * merge_sort(float *a, int size) {
	if (size < 2) return a;
	int size_2 = size / 2;
	float *x = new float[size_2];
	float *y = new float[size-size_2];
	for (int i = 0; i < size_2; i++)
		x[i] = a[i];
	for (int i = size_2; i < size; i++)
		y[i-size_2] = a[i];
	return merge(merge_sort(x, size_2), merge_sort(y, size - size_2), size_2, size - size_2);
}


void merge(float *a, int left, int mid, int right) {
	int it1 = 0, it2 = 0;
	float *result =new float[right - left];

	while (left + it1 < mid && mid + it2 < right) {
		if (a[left + it1] < a[mid + it2]) {
			result[it1 + it2] = a[left + it1];
			it1 += 1;
		}
		else {
			result[it1 + it2] = a[mid + it2];
			it2 += 1;
		}
	}
					
	while (left + it1 < mid) {
		result[it1 + it2] = a[left + it1];
		it1 += 1;
	}
				
	while (mid + it2 < right) {
		result[it1 + it2] = a[mid + it2];
		it2 += 1;
	}
					
	for (int i = 0; i < it1 + it2; i++)
		a[left + i] = result[i];

	delete[] result;
}


void mergeSort(float *a, int left, int right) {
	if (left + 1 >= right)
		return;
	int mid = (left + right) / 2;
	mergeSort(a, left, mid);
	mergeSort(a, mid, right);
	merge(a, left, mid, right);
}
	


int main()
{
	/*int m = 5, n = 5;
	float a[] = { 2,4,6,8, 10};
	float b[] = { 1,3,5,7, 9 };

	float *c = merge(a, b, m, n);*/

	float a[] = { 2,4,6,8, 10, 1,3,5,7, 9 };
	
	/*int n = 10;
	float *c = merge_sort(a, n);
	for (int i = 0; i < n; i++) {
		std::cout << c[i] <<"\t";
	}*/

	int n = 10;
	mergeSort(a, 0, n);
	for (int i = 0; i < n; i++) {
		std::cout << a[i] <<"\t";
	}



    std::cout << "\n";
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
