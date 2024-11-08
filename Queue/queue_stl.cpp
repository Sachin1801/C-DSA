#include<iostream>
#include<queue>
using namespace std ;

int main(){

    freopen("output.txt", "w", stdout);
    freopen("input.txt", "r", stdin);
    
    queue<int> q;

    q.push(4);
    q.push(40);
    q.push(400);
    q.push(4000);
    q.push(40000);
    q.pop();
    q.pop();

    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }

    return 0;
}