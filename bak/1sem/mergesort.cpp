#include <iostream>

void print_array(int a[], int size);
void merge(int a[], int left, int mid, int right);
void mergeSortRecursive(int a[], int left, int right);
    
int main() {
    const int n = 18;
    int a[] = { 1,3,5,7,2,4,6,8,-1,1,3,5,7,2,4,6,8,-1 };
    
    print_array(a, n);
    
    mergeSortRecursive(a, 0, n);

    print_array(a, n);
}


void print_array(int a[], int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << a[i] << "  ";
    }
    std::cout << std::endl;
}

void merge(int a[], int left, int mid, int right) {
    int it1 = 0, it2 = 0;

    int* result = new int[right - left];


    while (left + it1 < mid && mid + it2 < right) {
        if (a[left + it1] < a[mid + it2]) {
            result[it1 + it2] = a[left + it1];
            it1 += 1;
        }
        else {
            result[it1 + it2] = a[mid + it2];
            it2 += 1;
        }
    }
    while (left + it1 < mid) {
        result[it1 + it2] = a[left + it1];
        it1 += 1;
    }

    while (mid + it2 < right) {
        result[it1 + it2] = a[mid + it2];
        it2 += 1;
    }

    for (int i = 0; i < it1 + it2; ++i) {
        a[left + i] = result[i];
    }
    delete[] result;
}

void mergeSortRecursive(int a[], int left, int right) {
    if (left + 1 >= right) {}
    else {
        int mid = (left + right) / 2;
        mergeSortRecursive(a, left, mid);
        mergeSortRecursive(a, mid, right);
        merge(a, left, mid, right);
    }
}