// openmp_pr.cpp : умножение матриц В том числе с применением openMP
//

#include <iostream>
#include <stdio.h>
#include <omp.h>

#include <ctime> 

const int N = 1000;

int main()
{
	//std::cout << "Hello World!\n";
	
	unsigned int start_time, finish_time; 
	//float a[N][N], b[N][N], c[N][N];
	
	float **a, **b, **c;
	
	a=new float*[N];
	b=new float*[N];
	c=new float*[N];
	
	for (int i = 0; i < N; i++) {
		a[i]=new float[N];
		b[i]=new float[N];
		c[i]=new float[N];
		}
	
	
	
	/*
	for (int i = 0; i < N; i++) 
		for (int j = 0; j < N; j++) {
		a[i][j] = rand();
		b[i][j] = rand();
		}
	*/
	
	for (int i = 0; i < N; i++) 
		for (int j = 0; j < N; j++) {
			a[i][j] = i;
			b[i][j] = j;
		}
		
	for (int i = 0; i < N; i++) 
		for (int j = 0; j < N; j++)	
			c[i][j]=0;

	start_time = clock();

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++)
				c[i][j] += a[i][k] * b[k][j];
		}
	}

	finish_time = clock();
	
	std::cout << "i-j-k-time =" <<(finish_time-start_time)/CLOCKS_PER_SEC<<"\n";
			
	for (int i = 0; i < N; i++) 
		for (int j = 0; j < N; j++)	
			c[i][j]=0;
			
		start_time = clock();

	
	for (int j = 0; j < N; j++) {
		for (int i = 0; i < N; i++) {
			for (int k = 0; k < N; k++)
				c[i][j] += a[i][k] * b[k][j];
		}
	}

	finish_time = clock();
	
	std::cout << "j-i-k-time ="  <<(finish_time-start_time)/CLOCKS_PER_SEC<<"\n";
	
		for (int i = 0; i < N; i++) 
		for (int j = 0; j < N; j++)	
			c[i][j]=0;
			
		start_time = clock();

	
	for (int k = 0; k < N; k++)
		for (int j = 0; j < N; j++) {
			for (int i = 0; i < N; i++) {
				c[i][j] += a[i][k] * b[k][j];
		}
	}

	finish_time = clock();
	
	std::cout << "k-j-i-time =" << (finish_time-start_time)/CLOCKS_PER_SEC<<"\n";
	
	
			for (int i = 0; i < N; i++) 
		for (int j = 0; j < N; j++)	
			c[i][j]=0;
			
		start_time = clock();

	
/*	for (int j = 0; j < N; j++) 
		for (int k = 0; k < N; k++) {
			for (int i = 0; i < N; i++) {
				c[i][j] += a[i][k] * b[k][j];
		}
	}

	finish_time = clock();
	
	std::cout << "j-k-i-time =" << (finish_time-start_time)/CLOCKS_PER_SEC<<"\n";

*/
	
	


}
