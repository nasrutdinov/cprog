#include "String.h"


 String::String(){
        str_=new char[size_];
    }


 String::String(int size):size_(size){
        str_=new char[size_];
    }

 String::String(const char *str, int size):size_(size), str_(new char[size_]){
    for(int i=0; i<size; ++i){
        str_[i] = str[i];
    }
    str_[size-1]='\n';
 }

String:: ~String(){ 
    std::cout<<" \n String destructor \n";
    delete[] str_;

 }

 void String::print(){
    for(int i=0; i<size_; ++i){
      std::cout<<str_[i];
    }
 }