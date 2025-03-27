#include <iostream>
#include <vector>
//using namespace std;

// A utility function to print vector of size n
void printArray(int a[], int n){
    for (int i = 0; i < n; ++i)
        std::cout << a[i] << " ";
    std::cout << "\n";
}


void siftUp(int a[], int heapSize, int x) {
    a[heapSize++]=x;
	int j= heapSize-1;
	
	while (j>0 && a[(j-1)/2] <a[j]) {
		std::swap (a[(j-1)/2], a[j]);
	}
}



void siftDown(int a[], int heapSize) {
    std::swap(a[0], a[heapSize-1]);
        --heapSize;
		
		int j=0;
        int k;
		while (true) {
				k=j;
                if (2*j+1<heapSize && a[2*j+1]>a[j]){
                    k=2*j+1;
                }
                if (2*j+2<heapSize && a[2*j+2]>a[k]){
                    k=2*j+2;
                }
                if (j==k){
                    break;
                }
                std::swap(a[k],a[j]);
                j=k;
				
        }

}  

int main(){
    const int n =6;
     int a[]={6,5,0,3,2,1}; 
     int b[n];
    printArray(a, n);

    for (int k=0; k<n; ++k){
        siftUp(a,k,a[k]);
    }

    std:: cout << "heap array is \n";
    printArray(a, n);

    for (int k=0; k<n; ++k){
        siftDown(a,n-k);
    }

    std:: cout << "sort array is \n";
    printArray(a, n);


}