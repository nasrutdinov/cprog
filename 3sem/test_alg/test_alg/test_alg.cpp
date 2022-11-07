// test_alg.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Person {
private:
	string name;
	//string surname;
	int age;
public:
	Person(string name, int age) : name(name), age(age) {}
	bool operator <(const Person &p) {
		return name < p.name;
	}
	friend ostream & operator <<(ostream &os, const Person &v) {
			os << v.name << "\t" << v.age<<"\n";
			return os;
	}
};

ostream & operator <<(ostream &os, const vector<int> &v) {
	for (auto x : v) {
		os << x << "\t";
	}
	return os;
}

int main()
{
    std::cout << "Hello World!\n";
	vector<int> v = {5,2,6,10,3};
	cout << v << endl;
	sort(v.begin(), v.end());
	cout << v << endl;

	vector<Person> people = {
		Person("aaa", 12),
		Person("baa", 13),
		Person("caa", 11),
		Person("daa", 15),
		Person("eaa", 22),
		Person("aab", 12),
	};

	for (auto x : people) {
		cout << x;
	}

	sort(people.begin(), people.end());
	cout << "after sorting \n"; 
	for (auto x : people) {
		cout << x;
	}

}
