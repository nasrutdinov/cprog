#include <iostream>
#include <string>
#include "hello.h"

#include <omp.h>

int main(){
    
    #pragma omp parallel
    {
       std::string s= "hello from \t" + std::to_string(omp_get_thread_num())+" thread \n";
       std::cout<<s;
        //"hello from \t"<<omp_get_thread_num() <<"\n" ; 
    } 

    hello();

    
}