#include<vector>
using namespace std;

template<typename T>
class Stack{
    vector<T> s;
    int cs=0;

    public:
    void push(T d){
        s.push_back(d);
        cs++;
    }

    bool empty(){
        return cs==0;
    }

    T top(){
        if(cs!=0){
            return s[cs-1];
        }
    }

    void pop(){
        if(cs!=0){
            s.pop_back();
            cs--;
        }
    }
};