// sort1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <vector>

void array_print(std::vector<int> a);

int main()
{
    std::ifstream input_file("file.txt");

    if (!input_file.is_open()) {
        std::cout << "file not open! \n";
        return 1;
    }

        
    int size=0;
    input_file >> size;
    std::vector<int> a(size);

    for (int k = 0; k < size; ++k) {
        input_file >> a[k];
    }

    std::cout << "array before sorting: " << std::endl;
    array_print(a);


    for (int k = 0; k < size; ++k) {
        for (int i = 0; i < size - k - 1; ++i) {
            if (a[i] > a[i + 1]) {
                std::swap(a[i], a[i + 1]);
            }
        }
    }

    std::cout << "array after sorting: " << std::endl;
    array_print(a);

 }

void array_print(std::vector<int> a) {
    //std::cout << "array after sorting: " << std::endl;
    for (int i = 0; i < a.size(); ++i) {
        std::cout << a[i] << "\t";
    }
    std::cout << std::endl;
}
