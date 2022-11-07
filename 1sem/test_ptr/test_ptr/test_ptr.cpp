// pointer1.cpp: определяет точку входа для консольного приложения.

#include <iostream>
#include <string>
using namespace std;

struct comp {
	//string name;  // Имя переменной
	int value; // Значение переменной
	comp* next;     // Ссылка на следущий элемент списка
};


int main(int argc, char* argv[])
{
	comp* head;
	comp *tail, *curr;

	head = new comp;
	head->value = -1;
	head->next = NULL;

	tail = head;

	for (int k = 0; k < 5; k++) {
		curr = new comp;
		curr->value = k;
		curr->next = NULL;
		tail->next = curr;
		tail = curr;
	}

	curr = head;
	while (curr) {
		cout << curr->value << "\n";
		curr = curr->next;
	}
	
	return 0;
}

