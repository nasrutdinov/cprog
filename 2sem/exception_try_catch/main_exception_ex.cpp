#include <iostream>
#include <fstream>
#include <string>
#include <exception>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void func(int x){
	////ver 2.1
//	if (x<0) throw x;
//	cout<< "value =" << x <<"\n";

//ver 2.2
	if (x<0) throw "value is less 0";
		cout<< "value =" << x <<"\n";

////ver 2.3	 it works in VS, but not here	
//	if (x<0) throw exception("value is less 0");
//		cout<< "value =" << x <<"\n";
}

int main(int argc, char** argv) {
	
	string path ="text.txt";
	ifstream fin;
//it's a feature of ifstream. we swich on flag
	fin.exceptions(ifstream::badbit | ifstream::failbit);
	
/*	
//it's ordinary way to check if the file is opened
	ifstream fin(path);
	if(fin.is_open()){
		std::cout<<"File is open! \n";
		string s;
		fin>>s;
		cout<<"the first word is "<< s << "\n";
	}
	else {
		std::cout<<"File isn't' open! \n";
	}
*/

/*
//case 1
// try catch
	try	{
		cout<<"try to open file \n"; 
		fin.open(path);
		cout<<"File is open! \n"; 
		
	}	
	catch (const ifstream::failure &ex)
	//catch (const exception &ex)
	{
		cout << ex.what() << "\n";
		cout <<"error code: "<< ex.code() << "\n";
	}

	fin.close();
	*/	
	
	/*
//case 2
	int x = 0;
	try {
 		//cout <<2/x; // Здесь произойдет выброс исключения
		// Последующие операторы выполняться не будут
		if (x==0) throw invalid_argument("Division by zero");
	}
	catch (const exception &ex) {
		 cout << "Division by zero" << endl;
	}
	*/
	int x= -55; 
	try {
		func(x);
	}
	//// ver 2.1
//	catch (...){
//		cout<<"exception ! " ;  
//	}
	//// ver 2.2
	catch (const int ex)			{
				cout<<"exception ! " << ex;  
			}
	catch (const char *ex )	{
				cout<<"exception ! " << ex;  
	}
	
	return 0;
}