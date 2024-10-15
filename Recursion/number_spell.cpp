// number_spell.cpp
#include<iostream>
#include<stack>
using namespace std ;

string number[10]={"zero","one","two","three","four","five","six","seven","eight","nine"};

void number_spell(int n){
    if(n==0)
        return;
    
    //rec case
    number_spell(n/10);
    int digit = n%10;
    cout<<number[digit]<<" ";
    cout<<number[digit]<<" ";
    // cout<<number[digit]<<" ";
    return;
}

int main(){

    int n;
    cin>>n;

    number_spell(n);

    return 0;
}