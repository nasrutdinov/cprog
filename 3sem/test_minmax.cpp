#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std; 
int main(int argc, char** argv) {
	
	vector<int> v={5,3,2,-3,2,3,3,66,3};
	list<int> l={5,3,2,-3,2,3,3,66,3};
	
	//auto it= max_element(v.begin(), v.end());
	auto it= max_element(l.begin(), l.end());
	cout<<*it<<endl;
	
	it=min_element(l.begin(), l.end());
	cout<<*it<<endl;
	
	auto it2=minmax_element(l.begin(), l.end());
	
	cout<<*it2.first<<endl;
	
	return 0;
}