#include<vector>
#include<iostream>
using namespace std;

class Heap{
    vector<int> v;

    void heapify(int i){
        int left = 2*i;
        int right = 2*i + 1;

        int minidx = i ;
        if(left < v.size() and v[left]<v[i]){
            minidx = left;
        }else if(right<v.size() and v[right]<v[minidx]){
            minidx = right;
        }
        if(minidx!=i){
            swap(v[i],v[minidx]);
            heapify(minidx);
        }
        return;
    }

public:
    Heap(int size=10){
        v.reserve(size+1);
        v.push_back(-1);
    }

    //Push Data
    void push(int d){
        v.push_back(d);
        int idx = v.size()-1;
        int parent = idx/2;
        while(idx>1 and v[idx]<v[parent]){
            swap(v[idx],v[parent]);
            idx = parent;
            parent /=2;
        }
        return;
    }

    

    //Pop Min
    void pop(){
        if(v.size()==1){
            cout<<"Pop not possible"<<endl;
        }else if(v.size()==2){
            v.pop_back();
            return;
        }
        else{
            int idx = v.size()-1;
            swap(v[1],v[idx]);
            v.pop_back();
            heapify(1);
        }
    }

    //Get min
    int top(){
        return v[1];
    }

    bool isEmpty(){
        return v.size()==1;
    }
};