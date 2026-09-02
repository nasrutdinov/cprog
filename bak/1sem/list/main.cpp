#include <iostream>

template <typename T>
struct Node {
	T value;
	struct Node* next;
};

// Вставка нового узла после узла curr
template <typename T>
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

template <typename T>
Node<T>* push_back(Node<T>* curr, T value) {
	Node<T>* node = new Node<T>;
	node->value = value;
	if (curr != nullptr) {
		node->next = curr->next;
		curr->next = node;
		return node;
	}
	else { // эта часть для случая, когда изначальный список пуст 
		curr = node;
		curr->next = nullptr;
		return node;
	}
}

// Удаляем узел из списка после элемента curr
template <typename T> 
void remove(Node<T> *curr) {
	if (curr->next != nullptr) {
		Node<T>* p = curr->next;
		curr->next = p->next;
		delete p;
	}
}


template <typename T>
bool is_empty(Node<T>* head) {
	return head == nullptr;
}


//поиск узла перед узлом со значением value
template <typename T>
Node<T>* find_before(Node<T> *head, T value) {
        if (is_empty(head)) return nullptr;

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
template <typename T>
Node<T>* find(Node<T>* head, T value) {

	Node<T>* curr = head;
	while (curr) {
		if (curr->value == value) {
			return curr;
		}
		curr = curr->next;
	}
	return nullptr;
}

template <typename T>
void PrintList(Node<T>* head) { //thats just simple.
	Node<T>* curr = head;
	if (head == nullptr) {
		std::cout<< "List is empty \n";
		return;
	} 
	
	std::cout << "\n";
	while (curr) {
		std::cout << curr->value << "\t";
		curr = curr->next;
	};
} 

int main() {
	
	Node<int>* head{nullptr};
	Node<int>* curr{nullptr};
	Node<int>* tail;

	/*head = new Node<int>;
	head->value = 0;
	head->next = nullptr;*/

	//head = insert(head, 0);

	
	head = push_back(head, 0);
	tail = head;

	for (int k = 1; k < 10; ++k) {
		tail=push_back(tail, k);
	}

	PrintList(head);

	//Удаление узла с 4 
	remove(find_before(head, 4));


	PrintList(head);

	//Удаление узла с 4 
	insert(find(head, 5), 33);
	PrintList(head);

	return 0;
};



