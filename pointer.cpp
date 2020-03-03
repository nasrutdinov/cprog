#include <iostream>

int main()
{
	// указатель на объект типа int, здесь * используется для описания указателя
	int * pArray=NULL; 

	int N = 0;
	std::cout << "Input size of array :";
	std::cin >> N;
	//выделяем память под одномерный массив динамически
	pArray = new int[N];
	
	//обращение к элементам - способ 1
	for (int i = 0; i < N; i++)
		pArray[i] = i;
	
	std::cout << "array-1 \n";
	for (int i = 0; i < N; i++)
		std::cout<<pArray[i] <<std::endl;
	
	//обращение к элементам - способ 2
	std::cout << "array-2 \n";
	for (int i = 0; i < N; i++)
		*(pArray+i) = i+i;

	for (int i = 0; i < N; i++)
		std::cout << *(pArray+i)<< std::endl;

	delete []  pArray;

	
	//Создание двумерного динамического массива
	int m, n; 
	m = n = 0;
	std::cout << "Matrix - Input number of string :";
	std::cin >> m;

	std::cout << "Matrix - Input number of columns :";
	std::cin >> n;

	std::cout << "Matrix \n";
	int **massive;
	massive = new int*[m];
	for (int k = 0; k < m; k++)
		massive[k] = new int [n];

	for (int i = 0; i < m; i++)
		for (int j = 0; j < m; j++)
			massive[i][j] = 10 * i + j;

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++)
					std::cout<<massive[i][j] <<"\t";
		std::cout << "\n";
	}
	//Удаление маасива - очистка памяти
	for (int i = 0; i < m; i++) {
        	delete [] massive[i];
    	}
   	delete [] massive;
}
