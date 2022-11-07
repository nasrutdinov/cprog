// pr_class_2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

struct B;

struct A {
    std::string name = "A";
    A() =default;
    A(const B & other); // : name("A") {};
    void toString() { std::cout << "my name is "<< name << "\n";  };
    void f() { std::cout << "nothing! \n"; };
};

struct B :A {
    B() {name = "B"; };
    void f(int x) {
        std::cout << "x=" << x << "\n";
    }
};

int main()
{
    A a;
    B b;

    std::cout << "class A \n";
    a.f();
    a.toString();

    std::cout << "class B \n";
    int x = 1;
    b.f(x);
    b.toString();

    std::cout << "class C \n";
    A c = b;
    c.toString();
}

A::A(const  B& other): name("A") {}