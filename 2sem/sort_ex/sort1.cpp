// sort1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <vector>

void array_print(std::vector<int> a, int size);

int main()
{
    std::ifstream f("file.txt");
    
    int size=0;
    f >> size;
    
    std::vector<int> a(size);

    if (f.is_open()) {
        std::cout << "ok! \n";
    }

    for (int k = 0; k < size; ++k) {
        f >> a[k];
    }

    std::cout << "array before sorting: " << std::endl;
    array_print(a, size);


    for (int k = 0; k < size; ++k) {
        for (int i = 0; i < size - k - 1; ++i) {
            if (a[i] > a[i + 1]) {
                std::swap(a[i], a[i + 1]);
            }
        }
    }

    std::cout << "array after sorting: " << std::endl;
    array_print(a, size);

 }

void array_print(std::vector<int> a, int size) {
    //std::cout << "array after sorting: " << std::endl;
    for (int i = 0; i < size; ++i) {
        std::cout << a[i] << "\t";
    }
    std::cout << std::endl;
}
