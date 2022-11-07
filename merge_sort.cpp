// merge_sort.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

int *merge(int *a, int *b, int p, int q) {
	int n;

	if (p <= 0)
		p = 0;

	if (q <= 0)
		q = 0;

	n = p + q;
	int *c = new int[n];

	int i, j, k;
	i = j = k = 0;
	while ((i < p) && (j < q)) {
		if (a[i] <= b[j]) {
			c[k++] = a[i++];
		}
		else {
			c[k++] = b[j++];
		}
	}

	if (i == p) {
		for (int s = j; s < q; s++) {
			c[k++] = b[j++];
		}

	}
	else {
		for (int s = i; s < p; s++) {
			c[k++] = a[j++];
		}
	}

	return c;
}


void merge2(int *a, int left, int mid, int right) {
	int i = 0, j = 0;

	int *result = new int[right - left];

	while ((left + i < mid)&&(mid + j < right)){
		if (a[left + i] < a[mid + j]) {
			result[i + j] = a[left + i];
			++i;
		}
		else {
			result[i + j] = a[mid + j];
			++j;
		}
}
	while (left + i < mid) {
		result[i + j] = a[left + i];
		++i;
	}

	while ((mid + j)< right) {
		result[i + j] = a[mid + j];
		++j;
	}
		
	for (int k = 0; k < i + j; k++)
		a[left + k] = result[k];
}

void mergesort2(int *a, int left, int right) {
	if (left == right)
		return;
	int mid = left + (right - left) / 2;

	mergesort2(a, left, mid);
	mergesort2(a, mid + 1, right);
	merge2(a, left, mid, right);
}
			

				
					
int *mergesort(int *a, int n) {
	if (n <2)
		return a;
	int m = n / 2;
	std::cout <<"m="<< m << "\n";
	int *x = new int[m];
	int *y = new int[n-m];
	for (int i = 0; i <= (m - 1); i++)
		x[i] = a[i];
	int j = 0;
	for (int i = m ; i < n; i++) {
		y[j] = a[i];
		++j;
	}
		
	return merge(mergesort(x,m), mergesort(y,n-m), m , n- m);

}

int main()
{
	std::cout << "Hello World!\n";

	int a[] = { 21, 1, 2, 3, 8, 9, 4, 5, 6, 5, 18, 19};
	int b[] = { 4, 5 ,6, 18, 19 };



	int *c = new int[12];
	//c = merge(a, b, 5, 5);
	mergesort2(a, 0,12);
	////int c[10];

	//for (int i = 0; i < 10; i++) 
	//	c[i] =i;

	for (int i = 0; i < 12; i++) {
		std::cout << a[i]<<"\n";
	}
}
