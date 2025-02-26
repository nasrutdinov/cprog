#include<iostream>
#include<chrono>

/* Function to sort array using insertion sort */
void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;

        /* Move elements of arr[0..i-1], that are 
        greater than key, to one position ahead
        of their current position */
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void printArr(int arr[], int size){
    for (int k=0; k<size; ++k){
        std::cout<<arr[k]<<"\t";
    }
    std::cout<<std::endl;
}

int main(){
    int const size=10;
    int arr[]={9, 8, 7,6,5,4,3,2,1,0}; 

    std::cout<<"array before sorting \n";
    printArr(arr, size);

    //замер времени 
    auto start = std::chrono::steady_clock::now();

    //сортировка
    insertionSort(arr,size);

    //замер времени
    auto end = std::chrono::steady_clock::now();   
    std::chrono::duration<double> elapsed_seconds = end-start;

    //вывод массива и времени работы
    
    std::cout << "elapsed time: " << elapsed_seconds.count() << "s\n";
    std::cout<<"array after sorting \n";
    printArr(arr, size);

    return 0;
}