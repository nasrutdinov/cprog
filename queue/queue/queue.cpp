// queue.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include<map>

using namespace std;

int main() {
	map<int, string> m = { {1, "odd"}, {2, "even"}, {1, "one"} };

	for (auto t : m) {
		cout << t.first<<"---"<<t.second<<endl;
	}
	

	m[2] = "two";
	m.erase(1);
	m[3] = "three";
	m.erase(4);
	m[5] = "five";
	cout << m.size();
		//int q;
		//cin >> q;
		//vector<bool> is_nervous;

		//for (int i = 0; i < q; ++i) {
		//	string operation_code;
		//	cin >> operation_code;

		//	if (operation_code == "WORRY_COUNT") {

		//		// подсчитываем количество элементов в векторе is_nervous, равных true
		//		cout << count(begin(is_nervous), end(is_nervous), true) << endl;

		//	}
		//	else {
		//		if (operation_code == "WORRY" || operation_code == "QUIET") {

		//			int person_index;
		//			cin >> person_index;

		//			// выражение в скобках имеет тип bool и равно true для запроса WORRY,
		//			// поэтому is_nervous[person_index] станет равным false или true
		//			// в зависимости от operation_code
		//			is_nervous[person_index] = (operation_code == "WORRY");

		//		}
		//		else if (operation_code == "COME") {

		//			int person_count;
		//			cin >> person_count;

		//			// метод resize может как уменьшать размер вектора, так и увеличивать,
		//			// поэтому специально рассматривать случаи с положительным
		//			// и отрицательным person_count не нужно
		//			is_nervous.resize(is_nervous.size() + person_count, false);

		//		}
		//	}
		//}

		return 0;
}
    
