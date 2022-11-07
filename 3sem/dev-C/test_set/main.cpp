#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <vector>
#include <unordered_map> 
#include <algorithm> 
#include <set>


#include <chrono>

//упорядоченный ассоциативный массив (словарь)

using namespace std;

const int n = 10;

int main()
{
	map<string, int> myMap = { {"aaa", 1}, {"abb", 4}, {"fff", 3}, {"rre", 9}, {"aaa", 1} };
	multimap<string, int> myMultiMap = { {"aaa", 1}, {"abb", 4}, {"fff", 3}, {"rre", 9}, {"aaa", 1} };

	std::cout << "myMap : \n";
	for (auto &x : myMap) {
		cout << x.first << "\t" << x.second << endl;
	}
	cout << endl;

	//вставка элемента
	myMap.insert(make_pair("aaa", 2));
	myMap.insert(make_pair("aab", 2));
	myMap.insert(pair<string, int>("aab", 2));
	myMap.emplace("ttt", 99);

	std::cout << "myMap2 : \n";
	for (auto &x : myMap) {
		cout << x.first << "\t" << x.second << endl;
	}
	cout << endl;

	std::cout << "myMultiMap : \n";
	for (auto &x : myMultiMap) {
		cout << x.first << "\t" << x.second << endl;
	}
	cout << endl;

	//чистый алгоритм 
	vector<string> v_string;
	ifstream in3("C:\\Users\\marat\\Documents\\GitHub\\sem3\\test_map\\text.txt");
	for(string word; in3 >> word; )
	{
		v_string.push_back(word);
	}

	



	//долгая реализация
	chrono::system_clock::time_point start;
	chrono::system_clock::time_point end;
	chrono::duration<double> sec;

	//system_clock::time_point start = system_clock::now();
	//// Выполняем некоторый код
	//for (long i = 1; i < 10000000000; i += 1);
	//// Получаем момент времени_2
	//system_clock::time_point end = system_clock::now();
	//// Определяем тип объекта интервала и вычисляем его значение
	//duration<double> sec = end - start;
	//// вычисляем количество тактов в интервале
	//// и выводим итог
	//cout << sec.count() << " сек." << endl;
	//return 0;
	
	//start = chrono::system_clock::now();
	

	map<string, int> dict;

	/*ifstream in("C:\\Users\\marat\\Documents\\GitHub\\sem3\\test_map\\text.txt");
	string s;
	while (in >> s) {
		dict[s] += 1;
	}

	in.close();*/

	//чистый алгоритм 
	for (auto x : v_string) {
		dict[x] += 1;
	}


	start = chrono::system_clock::now();
	set < pair<int, string>> dict2;

	std::cout << "Dictionary : \n";
	for (auto &x : dict) {
		//cout << x.first << "\t" << x.second << endl;
		dict2.emplace(x.second, x.first);
	}

	cout << endl;
	
	end = chrono::system_clock::now();
	sec = end - start;
	cout << "time 1 = " << sec.count() << " sec." << endl;

	std::cout << "Dictionary 2: \n";
	
	int j = dict2.size()-10;
	for (auto x:dict2) { 
		j--;
		if (j > 0) continue;
		cout << x.first << "\t" << x.second << endl;
		
	}

	

	cout << endl;

	
	//быстрая реализация

	cout << "quick way " << endl; 
	start = chrono::system_clock::now();
	//ifstream in2("C:\\Users\\marat\\Documents\\GitHub\\sem3\\test_map\\text.txt");

	unordered_map<string, int> udict;


	//if (in.is_open())
	//	cout << "ok" << endl;

	//for(string word; in2 >> word; )
	//{
	//	//cout << word << endl;
	//	dict[word] += 1;
	//}
	/*string s;
	while (in2 >> s) {
		udict[s] += 1;
	}*/
	//in2.close();
	//чистый алгоритм 
	for (auto x : v_string) {
		udict[x] += 1;
	}

/*
	set < pair<int, string>> undict2;

	std::cout << "Dictionary : \n";
	for (auto &x : dict) {
		//cout << x.first << "\t" << x.second << endl;
		undict2.emplace(x.second, x.first);
	}

	cout << endl;
*/

	vector< pair<int, string>> udict2(udict.size());

	std::cout << "Dictionary : \n";
	int k=0;
	for (auto &x : udict) {
		//cout << x.first << "\t" << x.second << endl;
		//udict2.push_back(pair<int, string>(x.second, x.first) );
		udict2[k++]=pair<int, string>(x.second, x.first) ;
	}

	//cout << endl;

	sort(udict2.begin(), udict2.end(), [](pair<int, string> x, pair<int, string> y) {
		return x.first > y.first;
	});

	end = chrono::system_clock::now();
	sec = end - start;
	cout << "time 2 = " << sec.count() << " sec." << endl;
	
	std::cout << "Dictionary 2: \n";
	int i = 0;
	for (auto &x : udict2) {
		i++;
		cout << x.first << "\t" << x.second << endl;
		if (i > 10) break;
	}

	cout << endl;

//	std::cout << "Dictionary 2: \n";
//
//	j = undict2.size() - 10;
//	for (auto x : undict2) {
//		j--;
//		if (j > 0) continue;
//		cout << x.first << "\t" << x.second << endl;
//
//	}


	////удаление элемента 
	//mySet.erase(2);

	////проверка - есть ли элемент в множестве. Возвращается итератор 
	//auto it = mySet.find(2);
	//if (it == mySet.end())
	//	cout << "element isn't found" << endl;
	//else cout << *it << endl;

	//it = mySet.find(5);
	//if (it == mySet.end())
	//	cout << "element isn't found" << endl;
	//else cout << *it << endl;


	return 0;
}