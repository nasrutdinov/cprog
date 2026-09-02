#include<iostream>

#include <iostream>

template <typename T>
struct Node {
	T value;
	struct Node* next;
};

template <typename T>
struct List {
	Node<T>* head;
	Node<T>* tail;
	List() : head(nullptr), tail(nullptr) {}
	bool is_empty() { return head == nullptr;}
	// Вставка нового узла после узла curr
	Node<T>* insert(Node<T>* curr, T value) {
		Node<T>* node = new Node<T>;
		node->value = value;
		if (curr != nullptr) {
			node->next = curr->next;
			curr->next = node;
		}
		else { // эта часть для случая, когда изначальный список пуст 
			curr = node;
			curr->next = nullptr;
		}
		return node;
	}
	void push_back(T value) {
		Node<T>* node = new Node<T>;
		node->value = value;
		node->next = nullptr;
		if (tail != nullptr) {
			tail->next = node;
			tail = node;
		}
		else { // эта часть для случая, когда изначальный список пуст 
			head = node;
			tail = node;
		}
	}
	void remove(Node<T>* curr) {
		if (curr->next != nullptr) {
			Node<T>* p = curr->next;
			curr->next = p->next;
			delete p;
		}
	}
	Node<T>* find_before(T value) {
		if (this->is_empty()) return nullptr;

		if (head->value == value) {
			return head;
		}

		Node<T>* pred = head;
		Node<T>* curr = head->next;

		while (curr) {
			if (curr->value == value) {
				return pred;
			}
			pred = curr;
			curr = curr->next;
		}
		return nullptr;
	}

	//поиск узла перед узлом со значением value
	Node<T>* find(T value) {

		Node<T>* curr = head;
		while (curr) {
			if (curr->value == value) {
				return curr;
			}
			curr = curr->next;
		}
		return nullptr;
	}

	void PrintList() { //thats just simple.
		Node<T>* curr = this->head;
		if (head == nullptr) {
			std::cout << "List is empty \n";
			return;
		}

		std::cout << "\n";
		while (curr) {
			std::cout << curr->value << "\t";
			curr = curr->next;
		};
	}

};

int main() {

	List<int> L;

	for (int k = 1; k < 10; ++k) {
		L.push_back(k);
	}

	L.PrintList();

	////Удаление узла с 4 
	L.remove(L.find_before(4));


	L.PrintList();

	//Добавление узла после узла со значением 5
	L.insert(L.find(5), 33);
	L.PrintList();

	return 0;
};

