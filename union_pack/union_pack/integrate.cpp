#include"integrate.h"

double trap(float(*f)(float ), float a, float b, int n ){
	double sum = 0;
	double h = (b - a) / n;

	for (int i = 0; i < n; i++) {
		sum += f(a + i * h);
	}
	return sum * h;
}

float rect(float(*f)(float), float a, float b, int n) {
	float sum = 0;
	float h = (b - a) / n;

	for (int i = 0; i < n; ++i) {
		sum += f(a + i * h);
	}
	return sum*h;
}