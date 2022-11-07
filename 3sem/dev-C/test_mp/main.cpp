#include <iostream>
#include <vector>
#include<chrono>
#include <omp.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

int main(int argc, char** argv) {

		int m= 20000;
		int n= 20000; 

chrono::system_clock::time_point start ;
chrono::system_clock::time_point end ;
chrono::duration<double> sec ;

//		vector<vector<float> > a(m, vector<float>(n));
//		vector<float>  b(n); 
//		vector<float>  c(n);
		

		double **a = new double*[m];
		for (int i = 0; i < m; i++)
			a[i] = new double[n];
		double *b = new double[n];
		double *c = new double[n];
		
#pragma omp parallel for 
	for (int i=0; i<m; i++){
			b[i]=1.1;}	 
 
#pragma omp parallel for collapse(2)
		for (int i=0; i<m; i++){
			for (int j=0; j<n; j++)
					a[i][j]=i+j;
		}
				 
		start = chrono::system_clock::now();

		for (int i = 0; i < m; i++)
			c[i] = 0;

		for (int i = 0; i < m; i++) {
			double s = 0;
				for (int j = 0; j < n; j++)
					s += a[i][j] * b[j];
			c[i] = s;
		}

		end = chrono::system_clock::now();

		sec = end - start;
		// вычисляем количество тактов в интервале
		// и выводим итог
		cout << "sequntional time = " << sec.count() << " sec" << endl;

//		
//
//					
start = chrono::system_clock::now();
//		
//		for (int i=0; i<m; i++)
//			c[i]=0;	
			
//#pragma omp parallel 
//			cout<<"hello \n";
		
//#pragma omp parallel 
#pragma omp parallel for	//collapse (2)
		for (int i=0; i<m; i++){
			double s = 0;
#pragma omp parallel for reduction(+:s)
			for (int j=0; j<n; j++)	
				//c[i]+= a[i][j] * b[j];
				s += a[i][j]* b[j];
			c[i] = s;
		}
		
		end = chrono::system_clock::now();
		
		sec = end - start;
	    // вычисляем количество тактов в интервале
	    // и выводим итог
	    cout << "parallel time = "<< sec.count() << " sec" << endl;
		
	return 0;
}