// set_pr.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <set>
#include <algorithm>
//#include <vector>   
#include <iterator>
using namespace std;

#pragma once

#include <chrono>
#include <optional>
#include <string>
#include <sstream>

class LogDuration {
public:
	explicit LogDuration(const std::string& msg = "")
		: message(msg + ": ")
		, start(std::chrono::steady_clock::now())
	{
	}

	~LogDuration() {
		auto finish = std::chrono::steady_clock::now();
		auto dur = finish - start;
		std::ostringstream os;
		os << message
			<< std::chrono::duration_cast<std::chrono::milliseconds>(dur).count()
			<< " ms" << std::endl;
		std::cerr << os.str();
	}
private:
	std::string message;
	std::chrono::steady_clock::time_point start;
};

#ifndef UNIQ_ID
#define UNIQ_ID_IMPL(lineno) _a_local_var_##lineno
#define UNIQ_ID(lineno) UNIQ_ID_IMPL(lineno)
#endif

#define LOG_DURATION(message) \
  LogDuration UNIQ_ID(__LINE__){message};



int main()
{
	{
		LogDuration("begint");
		std::cout << "Hello World!\n";

		std::set<int> mySet1 = { 1,2,3,4 };
		std::set<int> mySet2 = { 4,5,6,7 };
		std::set<int> mySet3;
		std::set_intersection(mySet1.begin(), mySet1.end(), mySet2.begin(), mySet2.end(), inserter(mySet3, mySet3.begin()));
	
	for (const auto &elem : mySet1) {
		cout << elem << "\t";
	}
	cout << "\n";
	cout << "set 2 \n";
	for (const auto &elem : mySet2) {
		cout << elem << "\t";
	}
	cout << "\n";
	cout << "set 3 \n";
	for (const auto &elem : mySet3) {
		cout << elem << "\t";
	}
}

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
