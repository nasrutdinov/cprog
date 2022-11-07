// test_class_const.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

class C {
    mutable size_t counter=0;
public:
    int GetZero() const {
        counter++;
        return 0;
    }
};



#include <iostream>

int main()
{
    using int_a10 = int[10];

    int_a10 x = {0,1,2,3,4,5,6,7,8,9};

    for (auto t : x) {
        std::cout << t << "\n";
    }

    std::cout << "Hello World!\n";
    const C c;
    std::cout << c.GetZero()<<"\n";

}
