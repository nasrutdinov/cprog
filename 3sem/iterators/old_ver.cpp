#include<iostream>
#include<vector>
int k=0;
void boo()
{
    ++k;
    std::cout<<"hello ! << k << "\n";
    boo();
}
 
int main()
{
    
    boo();
 
    return 0;
}
/*
int main(){
    
    int stack[10000000000000];
    std::cout<<"print \n";
    return 0;

       //
    std::cout<<"hello 2-3! \n";
    std::vector<int> v={1,2,3,4,5,6,7,8,9};

    std::vector<int>::iterator  iter=v.begin();

    std::cout<<"iterator type = " << *iter;
    
    return 0;
    
}

*/

