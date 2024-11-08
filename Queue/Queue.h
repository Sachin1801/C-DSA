#include<iostream>
using namespace std;

template <typename T>
class Queue{

    int front;
    int rear;
    T *arr;
    int cs;
    int ms;

public:
    
    Queue(int def_size = 5){
        ms = def_size;
        arr = new T[ms];
        cs =0;
        front = 0;
        rear= ms-1;
    }

    bool full(){
        return cs==ms;
    }

    bool empty(){
        return cs==0;
    }

    void push(T d){
        if(!full()){
            rear = (rear + 1) % ms;
            arr[rear] = d;
            cs++;
        }
        return;
    }

    void pop(){
        if(!empty()){
            front = (front + 1) % ms;
            cs--;
        }
    }

    int get_front(){
        return arr[front];
    }
};