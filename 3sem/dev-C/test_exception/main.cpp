// ??????? ?????? ? ????????????
//
//#include <exception>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class MyException: public exception {
public:
	//MyException(const char * msg): exception(msg) {};
	MyException(const std::string& msg, int dataState) : _msg(msg),  dataState(dataState){}
	//~MyException() override {}
	virtual const char* what() const throw() //noexcept //throw()
  {
    return "My message";
  }
  
	//const char* what() noexcept {return "Ooops!\n";}
    //{       return _msg.c_str(); 	}
	int getDataState() const { return dataState; }
private:
	int dataState=0;
	
	std::string _msg;
};

void func(int x); 

int main()
{
	/*int N, M;*/


	/*ifstream input_file("file.txt");

	input_file.exceptions(ifstream::badbit|ifstream::failbit);
*/
	
	//if (!input_file.is_open()) // ???? ???? ?? ??????
	//	cout << "file isn't open! \n";
	//else
	//{
	//	input_file >> N >> M;
	//	cout << "sum =" << N + M << endl;
	//}

	//input_file.close();

	//try
	//{
	//	input_file >> N >> M;
	//	cout << "sum =" << N + M << endl;
	//	input_file.close();
	//}
	//catch  (const std::exception& ex) //(const ifstream::failure & ex)
	//{
	//	cout << "file isn't open! \n";
	//	cout << ex.what() <<"\n";
	//	//cout << ex.code() << "\n";
	//}
	///////////////////////////////////////////////////////////////////////////////////////
////case 1
	//try
	//{
	//	func(-4);
	//}
	//catch (const int &ex)
	//{
	//	std::cout << "we have wrong x<0 x=" << ex << std::endl;
	//}

////case 2
	//try
	//{
	//	func(-4);
	//}
	//catch (const char *ex)
	//{
	//	std::cout << ex << std::endl;
	//}

////case 3
	//try
	//{
	//	func(-4);
	//}
	//catch (const exception &ex)
	//{
	//	std::cout << ex.what() << std::endl;
	//}

////case 4
	try
	{
		func(1);
	}
	catch (const int &ex)
	{
		std::cout << "we have wrong x<0 x=" << ex << std::endl;
	}
	catch (const char *ex)
	{
		std::cout << ex << std::endl;
	}
	catch (const MyException &ex)
	{
		std::cout << ex.getDataState() << std::endl;
		std::cout << ex.what() << std::endl;

	}
	catch (const exception &ex)
	{
		std::cout << ex.what() << std::endl;
	}
	catch (...) {
		std::cout << "smtg wrong" << std::endl;
	};

	

	return 0;
}



void func(int x) {
	if (x < 0) {
		////case 1
		//throw x;

		//case 2
		throw "wrong x";

		////case 3
		//throw exception("wrong x");
	}

	if (x == 1) {
		////case 1
		//throw x;

		//case 2
		

		////case 3
		//throw exception("wrong x");

		////case 4
		//throw 3.2;

		////case 5
		
		throw MyException("ttt", x);
	}


	std::cout << "x=" << x << std::endl;
}

