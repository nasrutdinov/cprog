// MyVector_ex.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

template <typename T>
class MyVector
{
private:
	T *_array;
	int _arraySize;
	int _globalSize=10;
public:
	void push_back(T data);
	T pop();
	void clear();
	T operator [](int index);
	int size();
	void pushIndex(T data, int index);
	T popIndex(int index);
	MyVector();
	void printVector();
};


int main()
{
	vector<int> a = { 1,2,3,4 };
	vector <string> ivector;


	setlocale(LC_CTYPE, "rus");


	MyVector<int> myVect;
	int size;

	cout << "Введите кол-во элементов: " << endl;
	cin >> size;

	for (int index = 0; index < size; ++index)
		myVect.push_back(rand() % 100 + index);

	myVect.printVector();

	myVect.clear();
	myVect.printVector();;

	myVect.push_back(5000);
	myVect.printVector();

	myVect.pushIndex(4000, myVect.size());
	myVect.printVector();

	myVect.popIndex(myVect.size() - 1);
	myVect.printVector();

	return 0;
}

template <typename T>
void MyVector<T>::push_back(T data)
{
	if (_arraySize == _globalSize - 1) {
		_globalSize *= 2;
		T *_result = new T[++this->_globalSize];
		for (int index = 0; index < this->_arraySize; index++)
		{
			_result[index] = this->_array[index];
		}
		_result[_arraySize] = data;
		delete[] this->_array;
		this->_array = _result;
	} 
	else {
		this->_array[_arraySize++] = data;
	}
}

template <typename T>
T MyVector<T>::pop()
{
	return this->popIndex(this->_arraySize - 1);
}

template <typename T>
void MyVector<T>::clear()
{
	if (this->_array != NULL)
	{
		//::ZeroMemory(this->_array, this->_arraySize);'
		delete[] this->_array;
		this->_arraySize = 0;
		_globalSize = 10;
		this->_array = new T[this->_globalSize];
	}
	//this->_arraySize = 0;
	//this->_array = new T[this->_arraySize];
}

template <typename T>
T MyVector<T>::operator [](int index)
{
	return this->_array[index];
}

template <typename T>
int MyVector<T>::size()
{
	return this->_arraySize;
}

template <typename T>
void MyVector<T>::pushIndex(T data, int index)
{
	int oldSize = this->_arraySize;

	this->_arraySize = (this->_arraySize >= index) ? (++this->_arraySize) : (this->_arraySize + (index - this->_arraySize));

	T *_result = new T[this->_arraySize];

	int arrIndex = 0;

	for (int index2 = 0; index2 < this->_arraySize; index2++)
	{
		if (index2 == index)
		{
			_result[index2] = data;
			continue;
		}

		if (arrIndex != oldSize)
		{
			_result[index2] = this->_array[arrIndex++];
		}
	}
	delete[] this->_array;
	this->_array = _result;
}

template <typename T>
T MyVector<T>::popIndex(int index)
{
	T *_result = new T[--this->_arraySize];

	T resItem;

	int resIndex = 0;

	for (int index2 = 0; index2 < this->_arraySize + 1; index2++)
	{
		T item = this->_array[index2];

		if (index == index2)
		{
			resItem = item;
			continue;
		}
		_result[resIndex++] = this->_array[index2];
	}
	delete[] this->_array;
	this->_array = _result;
	return resItem;
}

template <typename T>
MyVector<T>::MyVector(): _globalSize(10)
{
	this->_arraySize = 0;
	this->_array = new T[this->_globalSize];
}

template <typename T>
void MyVector<T>::printVector()
{
	for (int k = 0; k < _arraySize; k++)
		cout << _array[k] << " ";
	cout << endl;
}