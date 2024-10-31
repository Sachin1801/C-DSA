#include<iostream>
#include"stackV.h"
using namespace std ;

void print(Stack<int> s){
    while(!s.empty()){
        cout<<s.top()<<",";
        s.pop();
    }
    cout<<endl;
    return;
}

int main(){

    freopen("output.txt", "w", stdout);
    freopen("input.txt", "r", stdin);
    
    Stack<int> s;
    s.push(1);
    s.push(2);
    s.push(2);
    s.push(4);
    s.push(10);
    // cout<<s.top()<<endl;

    // print(s);

    // s.pop();

    print(s);

    return 0;
}