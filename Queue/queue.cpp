#include<iostream>
#include"Queue.h"
using namespace std ;

int main(){

    freopen("output.txt", "w", stdout);
    freopen("input.txt", "r", stdin);\

    Queue<int> myqueue(7);

    myqueue.push(1);
    myqueue.push(2);
    myqueue.push(5);
    myqueue.push(4);
    myqueue.push(3);
    myqueue.push(9);
    myqueue.push(19);

    myqueue.pop();
    myqueue.pop();
    myqueue.pop();
    myqueue.pop();


    while(!myqueue.empty()){
        cout<<myqueue.get_front()<<endl;
        myqueue.pop();
    }
    

    return 0;
}