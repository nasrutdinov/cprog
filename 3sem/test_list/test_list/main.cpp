#include <iostream>
#include <list>

using namespace std; 
void PrintList(list<int> myList) {
	for (auto t : myList) {
		cout << t << "\t";
	}
	cout <<  "\n";
}

const int n = 3;

int main() {
	list<int> myList;
	list<int> myList2 = {-1,4,5,6};

	for (int i = 0; i < n; i++) {
		myList.push_back(i);
	}
	for (int i = 0; i < n; i++) {
		myList.push_front(i);
	}
	cout << "myList -1: \n";
	PrintList(myList);

	cout << "myList -sort: \n";
	myList.sort([](int x, int y) {return x > y; });
	PrintList(myList);


	//вставка и удаление элемента
	list<int>::iterator it = myList.begin();
	myList.insert(it, 99);
	//быстрый переход на k элементов
	advance(it, 3);
	//it++;
	myList.erase(it);
	cout << "myList - add -0, erase 3: \n";
	PrintList(myList);
	
	//удаление числа из списка 
	myList.remove(99);
	cout << "myList - remove 99 : \n";
	PrintList(myList);

	//объединение списков 
	cout << "myList - merge: \n";
	myList.sort();
	myList2.sort();
	myList.merge(myList2);	 
	PrintList(myList);

	cout << "myList - first and last elements: \n";
	cout << myList.front() << "\n";
	cout << myList.back() << "\n";

	//длина списка	
	cout << "size list "<< myList.size() << "\n";
	//очистка списков 
	myList.clear();
	cout << "size list after clear " << myList.size() << "\n";


	

}