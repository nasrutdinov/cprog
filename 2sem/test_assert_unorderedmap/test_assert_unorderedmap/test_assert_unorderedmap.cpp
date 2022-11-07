// test_assert_unorderedmap.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

// Здесь реализован класс и использован подход близкий к тому, 
// что делается в Java (в том месте где мы используем static). Мы используем методы буз создания объекта

// Оборачивается все в класс. Используется unordered_map. Что достаточно экзотично. 
// В результате показывается, что классический итеративный вариант быстрее всего.  

#include <iostream>
#include <cassert>
#include <chrono>

#include<unordered_map>

class Fib {
public:
    static int get(int n) {
        assert(n >= 0);
        if (n < 2)
            return n;
        return get(n - 1) + get(n - 2);
    }
};

class Fib2 {
public:
    static int get(int n) {
        assert(n >= 0);
        if (n < 2)
            return n;
       
        static std::unordered_map<int, int> cache;
        auto& result = cache[n];
        if (result == 0) {
            result= get(n - 1) + get(n - 2);
        }
        
        return result;

    }
};


class Fib3 {
public:
    static int get(int n) {
        assert(n >= 0);
        if (n < 2)
            return n;

        int current = 1, prev = 0;
        
        for (int i = 2; i <= n; i++) {
            int new_current =current + prev;
            prev = current;
            current = new_current;
        }

        return current;

    }
};

int main()
{
    std::cout << "version 1 \n";
    auto start = std::chrono::steady_clock::now();
    //Fib x;
    //for (int n = 0; n < 40; n++)
    int n = 46;
        std::cout << "n= " << n << " fib= " << Fib::get(n) << "\n";
        //std::cout << "n= " << n << " fib= " << x.get(n) << "\n";
    auto finish = std::chrono::steady_clock::now();

    std::chrono::duration<double> elapsed_seconds = finish - start;
    std::cout << "elapsed time 1: " << elapsed_seconds.count() << "s\n";

    std::cout << "version 2 \n";
    start = std::chrono::steady_clock::now();
    //Fib x;
    //for (int n = 0; n < 40; n++)
          std::cout << "n= " << n << " fib= " << Fib2::get(n) << "\n";
    //std::cout << "n= " << n << " fib= " << x.get(n) << "\n";
    finish = std::chrono::steady_clock::now();

    elapsed_seconds = finish - start;
    std::cout << "elapsed time 2: " << elapsed_seconds.count() << "s\n";

    std::cout << "version 3 \n";
    start = std::chrono::steady_clock::now();
    //Fib x;
    //for (int n = 0; n < 40; n++)
    std::cout << "n= " << n << " fib= " << Fib3::get(n) << "\n";
    //std::cout << "n= " << n << " fib= " << x.get(n) << "\n";
    finish = std::chrono::steady_clock::now();

    elapsed_seconds = finish - start;
    std::cout << "elapsed time 3: " << elapsed_seconds.count() << "s\n";
    
}

