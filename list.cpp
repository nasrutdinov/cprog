// list.cpp : ручное создание списка (двустороннего)
// 

#include <iostream>

struct list {
	int x;
	list *next;
	list *pred;
};

int main()
{
	list *p, *start, *finish;
	//list.x = 1;
	finish = new list;
	finish->x = 1;
	finish->next = NULL;
	finish->pred = NULL;
	start = finish;

	for (int i = 2; i < 10; i++) {
		finish->next = new list;
		finish->next->x = i;

		//Ссылка на предыдущий элемент
		finish->next->pred = finish;

		//Заменяем ссылку на конечный элемент
		finish = finish->next;
		finish->next = NULL;
	}

	p = start;
	while (p) {
		std::cout << p->x << "\n";
		p = p->next;
	}

	//удаление
	p = start;
	while (p->x!=5) {
		p = p->next;
	}

	//Удаление элемента
	p->pred->next = p->next;
	p->next->pred = p->pred;
	delete p;

	std::cout << "new list \n";
	p = start;
	while (p) {
		std::cout << p->x << "\n";
		p = p->next;
	}

	//вставка элемента в список?

	p = start;
	while (p->x != 4) {
		p = p->next;
	}

	list *q = new list;
	q->x = 55;

	q->next = p->next;
	q->pred = p;
	p->next = q;

	std::cout << "new list 2 \n";
	p = start;
	while (p) {
		std::cout << p->x << "\n";
		p = p->next;
	}


 //   std::cout << "Hello World!\n"; 
}