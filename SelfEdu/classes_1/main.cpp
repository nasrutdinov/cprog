#include<iostream>

class String{
private: 
    std::size_t size_;
    char *str_;
public: 
    String(const char * str){
            int size=0;
            while (str[size++]){ };
            size_=size;
            std::cout<<"size = "<< size_<<"\n";
            str_=new char[size_];
            for(int i=0; i<size_; i++){
                str_[i]=str[i];
            }

    }
    String(const char * str, std::size_t size):
        size_(size), str_(new char[size])
    {
            for (auto k=0; k< size_; k++){
                str_[k]=str[k];
            }
    }
    //конструктор копирования 
    String(const String &s){
        size_=s.size_;
        str_=new char[size_];
        for (auto k=0; k< size_; k++){
                str_[k]=s.str_[k];
            }
    }
    ~String(){
        delete[] str_;
        std::cout<<"destructor \n";
    }
    char operator[](int k){ return str_[k]; }
};




int main(){
    std::cout << "Hello World!"<< std::endl;
    //String s("abc", 3);
    String s("abs");
    for (auto k=0; k< 3; k++){
        std::cout << s[k];
    }
    std::cout<<std::endl;

    {
        String s2=s;
    }

    for (auto k=0; k< 3; k++){
        std::cout << s[k];
    }
    std::cout<<std::endl;

    return 0;
}