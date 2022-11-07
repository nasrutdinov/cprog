// test_accumalate.cpp : STL - автоматическое суммирование и произведение
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

#include <numeric>

int main()
{
	std::vector<int> v = { 1,2,3,4};
	//сумма элементов вектора, начальное значение =0; 
	auto result = std::accumulate(v.begin(), v.end(), 0);
    std::cout << "result ="<<result <<"\n";

	//произведение элементов вектора, начальное значение =0; 
	//в анонимной функции p - накопленное значение
	result = std::accumulate(v.begin(), v.end(), 1, [](int p, int x) {return p * x; });
	std::cout << "result =" << result << "\n";

	//сумма четных элементов элементов вектора, начальное значение =0; 
	//в анонимной функции p - накопленное значение
	result = std::accumulate(v.begin(), v.end(), 0, [](int s, int x) { 
		if (x%2==0) 
			return s+x; 
		else  return s;
	});
	std::cout << "result =" << result << "\n";

	//перевод массива в строку 
	auto result2 = std::accumulate(v.begin(), v.end(), std::to_string(v[0]), [](std::string s, int x) {
			return s + "-"+std::to_string(x);
	});
	std::cout << "result =" << result2 << "\n";

	//перевод массива в строку - 2
	result2 = std::accumulate(next(v.begin()), v.end(), std::to_string(v[0]), [](std::string s, int x) {
		return s + "-" + std::to_string(x);
	});
	std::cout << "result =" << result2 << "\n";
}
