#include<iostream>
#include<queue>
using namespace std ;

class Stack{

    queue<int> q1,q2;


    public:

    Stack(){

    }

    void push(int d){
        if(q1.empty()){
            q1.push(d);
            while(!q2.empty()){
                q1.push(q2.front());
                q2.pop();
            }
        }else{
            q2.push(d);
            while(!q1.empty()){
                q2.push(q1.front());
                q1.pop();
            }
        }
    }

};

int main(){

    freopen("output.txt", "w", stdout);
    freopen("input.txt", "r", stdin);
    
    

    return 0;
}