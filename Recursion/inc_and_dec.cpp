// inc_and_dec.cpp
#include<iostream>
using namespace std ;

void dec(int n)
{
    if(n==1)
    {
        cout<<n<<endl;
        return;
    }
    cout<<n<<", "; 
    dec(n-1);
}

void inc(int n)
{
    if(n==1)
    {
        cout<<n<<", ";
        return;
    }
    inc(n-1);
    cout<<n<<", ";
}

int main(){

    int n;
    cin>>n;

    dec(n);
    inc(n);

    return 0;
}