#include<iostream>

int add(int &x, int &y){
    
    return x+y;
}

int main(){
    std::cout << "Hello World!"<< std::endl;
    std::cout << "sum=" << add(3,5) << std::endl;
    return 0;
}