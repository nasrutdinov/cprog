//// iterators_pr.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
////
//
#include <iostream>
#include <vector>

#include <list>
using namespace std;

int main()
{
	std::vector<int> myVector = { 1,2,3,4,5 };

	list<int> myList = { 1,2,3,5,6 };

	//for (auto lst : myList) {
	//	std::cout << lst << endl; myList;
	//}


	for (auto lst = myList.begin(); lst != myList.end(); ++lst) {
		std::cout << *lst << endl;
	}

	auto it = myList.begin();
	while (it != myList.end()& (*it != 5)) {
		++it;
	}

	myList.insert(it, 4);

	std::cout << "after" << endl;
	for (auto lst = myList.begin(); lst != myList.end(); ++lst) {
		std::cout << *lst << endl;
	}




	/*for (auto v : myVector) {
		std::cout << v << endl;
	}*/


}


//#include <iostream>
//#include <vector>
//#include <algorithm>
//
////bool  MyCompare(int x, int y) { return abs(x) > abs(y); }
//
//int main()
//{
//
//	std::vector<int> vect;
//	vect.push_back(4);
//	vect.push_back(8);
//	vect.push_back(-3);
//	vect.push_back(3);
//	vect.push_back(-8);
//	vect.push_back(12);
//	vect.push_back(5);
//
//	//std::sort(vect.begin(), vect.end(), MyCompare); // выполняем сортировку элементов вектора
//
//	std::sort(vect.begin(), vect.end(), [](int x, int y) 
//	{
//		return x > y;
//	}
//	); // выполняем сортировку элементов вектора
//
//	std::vector<int>::const_iterator it; // объявляем итератор
//	for (it = vect.begin(); it != vect.end(); ++it) // выводим с помощью цикла и итератора элементы вектора
//		std::cout << *it << ' ';
//
//	std::cout << '\n';
//
//
//}

//
//#include <iostream>
//#include <vector>
//#include <algorithm>
//
////bool  MyCompare(int x, int y) { return abs(x) > abs(y); }
//
//int main()
//{
//	const int SIZE = 7;
//	int array[SIZE] = { 7,6,5,4,3,2,1 };
//	
//	std::sort(array, array+7); // выполняем сортировку элементов вектора
//
//	for (int i=0; i<SIZE; i++) 
//		std::cout << array[i] << ' ';
//
//	std::cout << '\n';
//}




