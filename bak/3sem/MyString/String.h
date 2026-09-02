#ifndef XXXXXXXX
#define XXXXXXXX

#include<iostream>

class String{
    public:
        String();
        String(int size);
        String(const char *str, int size);
        ~String();
        void print();
    private: 
        int size_=10;
        char *str_;
        
};
#endif