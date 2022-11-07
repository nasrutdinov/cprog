// stack_ex_1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stack>

using namespace std;
//Класс реализации стека на массиве
template <typename T>
class stackInArray {
private:
    unsigned int sizeOfStack;
    T* array;
public:
    stackInArray(const unsigned int maxSize) {
        sizeOfStack = 0;
        array = new T[maxSize];
    }
    ~stackInArray() {
        delete[] array;
    }
    void push(const T newElement) {
        array[sizeOfStack] = newElement;
        sizeOfStack++;
    }
    void pop() {
        sizeOfStack--;
    }
    T top() {
        return array[sizeOfStack - 1];
    }
    unsigned int size() {
        return sizeOfStack;
    }
};

//Реализация стека с помощью списка

//Элемент односвязного списка
template <typename T>
struct TNode {
    T data;
    TNode <T> *next;
    TNode (T newData, TNode <T> *nextNode) {
        data = newData;
        next = nextNode;
    }
};

// Список
template <typename T>
class stackInList {
private:
    unsigned int sizeOfStack;
    TNode <T> *currentTop;
public:
    stackInList() {
        sizeOfStack = 0;
        currentTop = NULL;
    }
    ~stackInList() {
        while (size())
            pop();
    }
    void push (const T element) {
        TNode <T> *node = new TNode <T> (element, currentTop);
        sizeOfStack++;
        currentTop = node;
    }
    void pop() {
        sizeOfStack--;
        TNode <T> *node    = currentTop;
        currentTop = currentTop->next;
        delete node;
    }
    T top () {
        return currentTop->data;
    }
    unsigned int size() {
        return sizeOfStack;
    }
};

void testFunctionForStack(int ); 

int main()
{
    std::cout << "Hello World!\n";
    testFunctionForStack(100000);
}


void testFunctionForStack(int size) {
    srand(time(NULL));
    unsigned int testStackSize = size;
    stackInArray<int> arrayStack(testStackSize);
    stackInList<int> listStack;
    stack<int> stlStack;
    clock_t time;

    cout << "Stack size: " << testStackSize << endl;

    cout << "Test for stack in array:" << endl;

    time = clock();
    for (unsigned int i = 0; i < testStackSize; i++) {
        arrayStack.push(rand() % RAND_MAX);
    }

    time = clock() - time;
    cout << "push for stack in array end: " << (double)time / CLOCKS_PER_SEC << "sec." << endl;

    time = clock();
    while (arrayStack.size()) {
        arrayStack.pop();
    }

    time = clock() - time;
    cout << "pop for stack in array end: " << (double)time / CLOCKS_PER_SEC << "sec." << endl;

    cout << "Test for stack in array end." << endl;
    cout << "---------------------------------------------------------------" << endl;
    cout << "Test for stack in list:" << endl;

    time = clock();
    for (unsigned int i = 0; i < testStackSize; i++) {
        listStack.push(rand() % RAND_MAX);
    }

    time = clock() - time;
    cout << "push for stack in list end: " << (double)time / CLOCKS_PER_SEC << "sec." << endl;

    time = clock();
    while (listStack.size()) {
        listStack.pop();
    }

    time = clock() - time;
    cout << "pop for stack in list end: " << (double)time / CLOCKS_PER_SEC << "sec." << endl;

    cout << "Test for stack in list end." << endl;
    cout << "---------------------------------------------------------------" << endl;
    cout << "Test for STL stack:" << endl;

    time = clock();
    for (unsigned int i = 0; i < testStackSize; i++) {
        stlStack.push(rand() % RAND_MAX);
    }

    time = clock() - time;
    cout << "push for STL stack end: " << (double)time / CLOCKS_PER_SEC << "sec." << endl;

    time = clock();
    while (stlStack.size()) {
        stlStack.pop();
    }

    time = clock() - time;
    cout << "pop for STL stack end: " << (double)time / CLOCKS_PER_SEC << "sec." << endl;

    cout << "Test for STL stack end." << endl;
}