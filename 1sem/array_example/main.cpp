#include<iostream>

void print(int a[], int n){
    for (int k=0; k<n; ++k){
        std::cout<<a[k]<< "\t";
    }
    std::cout<<std::endl;
}

int main(){
    int const n=5;

    int a[n];
    print(a,n);

    int b[n]{1};
    print(b,n);

    int c[n]{};
//    c[6000]=5;
//    c[6]=3;
    print(c,n);
    std::cout << sizeof(c) << std::endl;
    
    return 0;
}