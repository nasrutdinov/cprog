// Реализация подсчета частоты слов в текстовом файле. 
// Реализация через map (ассоциативный массив на основе сбалансированного дерева) и 
// через unordered_map (ассоциативный массив на основе хеш-функции) 

#include <iostream>
#include <map>
#include <string>

#include <fstream>
#include <vector>
#include <unordered_map> 
#include <algorithm> 
#include <set>


#include <chrono>



using namespace std;

const int n = 10;

int main()
{
//// упорядоченный ассоциативный массив (словарь)
	//map<string, int> myMap = { {"aaa", 1}, {"abb", 4}, {"fff", 3}, {"rre", 9}, {"aaa", 2} };

////вывод ассоциативного массива
	//std::cout << "myMap : \n";
	//for (auto &x : myMap) {
	//	cout << x.first << "\t" << x.second << endl;
	//}
	//cout << endl;

////////вставка элемента
	//myMap.insert(make_pair("aaa", 2));
	//myMap.insert(make_pair("aab", 2));
	//myMap.insert(pair<string, int>("aab", 2));
	//myMap.emplace("ttt", 99);

	

//////долгая реализация
	chrono::system_clock::time_point start;
	chrono::system_clock::time_point end;
	chrono::duration<double> sec;
//
///////////////////////////////////////////////////////////	
	start = chrono::system_clock::now();
	

	map<string, int> dict;

	ifstream in(".\text.txt");
	string s;
	while (in >> s) {
		dict[s] += 1;
	}

	in.close();

	set < pair<int, string>> dict2;

	for (auto &x : dict) {
		dict2.emplace(x.second, x.first);
	}

	end = chrono::system_clock::now();
	sec = end - start;
	cout << "time 1 = " << sec.count() << " sec." << endl;

	std::cout << "Dictionary : \n";
	////вывод первых десяти по частоте слов
	
	int j = dict2.size()-10;
	for (auto x:dict2) { 
		j--;
		if (j > 0) continue;
		cout << x.first << "\t" << x.second << endl;
		
	}

//////	///////////////////////////////////////////////////////
////быстрая реализация

	cout << "quick way " << endl; 
	start = chrono::system_clock::now();
	ifstream in2(".\text.txt");

	unordered_map<string, int > udict;
	
	while (in2 >> s) {
		udict[s] += 1;		
	}
	in2.close();

	//set < pair<int, string>> undict2;

	//std::cout << "Dictionary : \n";
	//for (auto &x : dict) {
	//	//cout << x.first << "\t" << x.second << endl;
	//	undict2.emplace(x.second, x.first);
	//}

	//cout << endl;


	vector< pair<int, string>> udict2(udict.size());

	int k = 0;
	std::cout << "Dictionary : \n";
	for (auto &x : udict) {
		//cout << x.first << "\t" << x.second << endl;
		//udict2.push_back(pair<int, string>(x.second, x.first) );
		udict2[k++]=pair<int, string>(x.second, x.first);
	}

	//cout << endl;

	sort(udict2.begin(), udict2.end(), [](pair<int, string> x, pair<int, string> y) {
		return x.first > y.first;
	});

	end = chrono::system_clock::now();
	sec = end - start;
	cout << "time 2 = " << sec.count() << " sec." << endl;
	//
	std::cout << "Dictionary 2: \n";
	int i = 0;
	for (auto &x : udict2) {
		i++;
		cout << x.first << "\t" << x.second << endl;
		if (i > 10) break;
	}

	return 0;
}