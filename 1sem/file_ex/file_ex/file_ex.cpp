// file_ex.cpp : Пример работы с файлами.
//

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	// связываем объект с файлом, по умолчанию файл ищется в папке программы
	// лучше прописать полный путь
	ifstream input_file("input.txt");

	int N, M;
	//проверяем открылся ли файл
	if (!input_file.is_open()) // если файл не открыт
		cout << "Файл не может быть открыт!\n";
	else
	{
		input_file >> N >> M;
		cout << "sum =" << N + M << endl;
	}

	// связываем объект с файлом, при этом файл открываем в режиме 	
	// записи, предварительно удаляя все данные из него

	ofstream file_output("data.txt"); 
	//ofstream file_output("data.txt", ios_base::out);

	// проверка отрытия файла
	if (!file_output.is_open())
	{
		cout << "Файл не может быть открыт или создан \n";
		// выполнить выход из программы
		return 1;
	}

	file_output << "sum="<<N+M ;

	// программа больше не использует файл, 
	//поэтому его нужно закрыть
	file_output.close();


	return 0;
}
