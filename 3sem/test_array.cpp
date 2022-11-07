#include <iostream>
#include <array>

using namespace std;


const int n = 3;

void PrintArray(array<int, n> myArray) {
	for (auto t : myArray) {
		cout << t << "\t";
	}
	cout << "\n";
}

int main() {
	array<int, n> myArray;
	array<int, n> myArray2 = { -1,4,5};

	for (int i = 0; i < n; i++) {
		myArray[i]= i;
	}
	
	cout << "myArray -1: \n";
	PrintArray(myArray);

}