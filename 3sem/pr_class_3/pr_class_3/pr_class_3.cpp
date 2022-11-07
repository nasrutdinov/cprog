#include <iostream>
#include <string>

struct B;

struct A {
    std::string name = "A";
    A() = default;
    A(const B& other); // : name("A") {};
    void toString() { std::cout << "my name is " << name << "\n"; };
    virtual void f() { std::cout << "I am a class A" << "\n"; };
};

struct B :A {
    B() { name = "B"; };
    void f() {
        std::cout << "I am a class B" << "\n";
    }
};

int main()
{
    A a;
    B b;
    A* c = &b;

    std::cout << "class A \n";
    a.f();
   

    std::cout << "class B \n";
    b.f();


    std::cout << "class C \n";
    c->f();
    
}

A::A(const  B& other) : name("A") {}