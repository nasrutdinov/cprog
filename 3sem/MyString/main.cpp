#include "hello.h"
#include "String.h"


int main(){

    String s("hello", 6);
    s.print(); 

    String s1=s;

    std::cout <<&s << "\n";
    std::cout <<&s1 << "\n";

}