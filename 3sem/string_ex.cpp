// string_ex.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>

using  std::string;
//
//class MyString {
//private:
//	string name;
//	static int next_id;
//	int id;
//public:
//	MyString() {
//		id = MyString.next_user_id();
//	};
//	string getName() { return name; };
//	static int next_user_id() { 
//		next_id++;
//		return next_id; };
//	int getID() {
//		return id;
//	};
//};

class user
{
private:
	const int id;
	static int next_id;

public:
	static int next_user_id()
	{
		next_id++;
		return next_id;
	}
	// остальные методы для класса user
	user() : id(user::next_id++)// конструктор класса
	{
		//id = user::next_id++; // или вызов метода, id = user.next_user_id();
	}
	int getID() {
		return id;
	}
};
int user::next_id = 0;

int main()
{
	user a, b, c;
	
	std::cout << a.getID()<<std::endl;
	std::cout << b.getID() << std::endl;
	std::cout << c.getID() << std::endl;
	std::cout << c.getID() << std::endl;
	/*MyString a, b;
	string str = "Hello World!\n"; 
	std::cout << str ;
	std::cout << a.getName()<<"\t"<< a.getID() <<"\n";
	std::cout << a.getName() << "\t" << a.getID() << "\n";*/
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
