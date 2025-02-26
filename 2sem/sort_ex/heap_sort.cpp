// heap_sort.cpp : Пример-заготовка для сортировки кучей
//

#include <iostream>
#include <vector>

using namespace std;

void print(vector<int> a);
void sift_up(vector<int> &a, int x);

int main()
{
    // Это для ввода массива
    vector<int> b = { 5,3,2,4,7,6 };

    // Массив, который будет сортироваться
    vector<int> a;

    cout << "before \n";
    print(b);

    // Читаем элементы в массив, сразу делаем очередь с приоритетами 
    for (int k = 0; k < b.size(); ++k) {
        sift_up(a, b[k]);
    }

    //cout << "after \n";
    //sift_up(a, 1);
    print(a);

    
}
void print(vector<int> a) {
    for (int k = 0; k < a.size(); ++k) {
        cout << a[k] << "\t";
    }
    cout <<  "\n";
}

void sift_up(vector<int>& a, int x) {
    int n = a.size();
    a.push_back(x);
    int j = n;
    while ( (j > 0) && (a[j] < a[(j - 1) / 2])) {
        swap(a[j], a[(j - 1) / 2]); 
        //print(a);
        j = (j - 1) / 2;
    }

}
