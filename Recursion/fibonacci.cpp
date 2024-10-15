// fibonacci.cpp
#include<iostream>
using namespace std ;

int fiboconacci(int n){
    if(n==0)
        return 0;
    if(n==1)
        return 1;
    return fiboconacci(n-1)+fiboconacci(n-2);
}   

int main(){
    int n;
    cin>>n; 

    cout<<finbonacci(n)<<endl;
    return 0;
}