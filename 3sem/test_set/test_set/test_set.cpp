// Контейнер set - храниться в виде упорядоченного бинарного дерева
//

#include <iostream>
#include <set>

using namespace std;

const int n = 10;

int main()
{
	set<int> mySet = {5, 4, 2, 5, 9} ;
	
	
	std::cout << "mySet : \n";
	for (auto &x: mySet) {
		cout<<x<<"\t" ;
	}

	 cout << endl;


multiset<int> myMultiSet= { 5, 4, 2, 5, 9 }; 
	 std::cout << "myMultiSet : \n";
	 for (auto &x : myMultiSet) {
		 cout << x << "\t";
	 }
	 cout << endl;

	 //удаление элемента 
	 mySet.erase(2); 

	 //проверка - есть ли элемент в множестве. Возвращается итератор 
	 auto it = mySet.find(2); 
	 if (it==mySet.end())
		cout << "element isn't found" << endl;
	 else cout << *it << endl ; 

	 it = mySet.find(5);
	 if (it == mySet.end())
		 cout << "element isn't found" << endl;
	 else cout << *it << endl;


	return 0;
}
