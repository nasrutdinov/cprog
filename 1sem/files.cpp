#include <iostream>
#include <fstream>
#include <string>

using namespace std;


int main()
{
	ifstream file("input.txt");
	ofstream output("output.txt", ios::app);
	string line;
	if (file.is_open())
		while (getline(file, line)) {
			output << line <<endl;
		}



}