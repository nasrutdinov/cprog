#include <iostream>
#include <vector>

using namespace std;

int main()
{
	
		int  A, B;
	cin >> A >> B;
	while (A > 0 && B > 0)
		if (A > B)
			A = A % B;
		else B = B % A;

	cout<<(A + B);
	/*
	int N;
	cin >> N;
	vector<int> v;

	while (N > 0) {
		v.push_back(N%2);
		N = N / 2;
	}

	for (int t=v.size()-1; t>=0; t--)
		cout << v[t];*/

}

	
