#include<iostream>
#include<memory>

int main()
{
int n=10;    

std::shared_ptr<int[]> a(new int[n]); 

for (int k=0; k<n; ++k){
    a[k]=k;
}

for (int k=0; k<n; ++k){
    std::cout<< a[k] << "\t";
}

}
