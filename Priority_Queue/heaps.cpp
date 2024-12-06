#include<iostream>
#include"heap.h"
using namespace std ;


int main(){

    freopen("output.txt", "w", stdout);
    freopen("input.txt", "r", stdin);
    
    Heap h;
    h.push(5);
    h.push(3);
    h.push(10);
    h.push(2);
    h.push(6);
    h.push(16);
    h.push(4);

    while(!h.isEmpty()){
        cout<<h.top()<<" ";
        h.pop();
    }

    h.push(1);
    while(!h.isEmpty()){
        cout<<h.top()<<" ";
        h.pop();
    }

    return 0;
}