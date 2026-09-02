#include<iostream>
#include<chrono>

float fib(int n){
    if (n<2){
        return n;
    }
    return fib(n-1)+fib(n-2);
}

int const N=45;

int main(){

    for (int k=0; k<N; ++k){
        auto start = std::chrono::steady_clock::now();

        std::cout<<"f("<<k<<")= \t "<< fib(k)<<"\n";

        auto end = std::chrono::steady_clock::now();
        std::chrono::duration<double> elapsed_seconds = end-start;
        std::cout << "elapsed time: " << elapsed_seconds.count() << "s\n";
    }
    
    return 0;
}