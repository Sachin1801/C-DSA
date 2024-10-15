// power_function.cpp
#include<iostream>
using namespace std ;

int power(int a, int n)
{
    if(n==0)
        return 1;
    return a*power(a,n-1);
}

int powe_opt(int a, int n)
{
    if(n==1)
        return a;
    
    //rec case
    if(n&1)
        return a * powe_opt(a,n/2) * powe_opt(a, n/2);
    return powe_opt(a,n/2) * powe_opt(a,n/2);
}

int main(){

    int a,n;
    int p=1;

    cin>>a>>n;

    cout<<power(a,n)<<endl;

    cout<<powe_opt(a,n)<<endl;

    return 0;
}
