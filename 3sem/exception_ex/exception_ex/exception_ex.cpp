// Примеры работы с исключениями
//

#include <iostream>
#include <fstream>

using namespace std;

class MyException: public exception {
public:
	//MyException(const char * msg): exception(msg) {};
	MyException(const char * msg, int dataState) : exception(msg) {
		this->dataState = dataState;
	};
	int getDataState() const { return dataState; }
private:
	int dataState=0;
};

void func(int x); 

int main()
{
	/*int N, M;*/

	// связываем объект с файлом, по умолчанию файл ищется в папке программы
	/*ifstream input_file("file.txt");

	input_file.exceptions(ifstream::badbit|ifstream::failbit);
*/
	////проверяем открылся ли файл
	//if (!input_file.is_open()) // если файл не открыт
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
		
		throw MyException("error", x);
	}


	std::cout << "x=" << x << std::endl;
}
