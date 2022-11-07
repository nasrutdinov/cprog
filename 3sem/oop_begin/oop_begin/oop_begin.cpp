// oop_begin.cpp : Пример работы с классами
//

#include <iostream>

using namespace std;

struct Apple { // структура Яблоко
	int health = 10;
};

struct Orange { // структура Апельсин
	int health = 5;
};

class Cat { // создаём класс Кошка
public:
	void Meow() const { // кошка может мяукать
		cout << " meow ! ";
	}
	void Eat(const Apple& a) { // кошка может есть яблоко
		cout << " Cat eats apple . " << a.health << " hp . " << endl;
	}
};

int main() {
	Cat c; // создали кошку
	c.Meow(); // помяукали
	Apple a; // создали яблоко
	c.Eat(a); // съели яблоко кошкой
	return 0;
}
