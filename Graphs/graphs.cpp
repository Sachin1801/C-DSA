#include<iostream>
#include"adj_list.h"
using namespace std ;

int main(){

    freopen("output.txt", "w", stdout);
    freopen("input.txt", "r", stdin);
    
    Graph g(6);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(0,4);
    g.addEdge(4,5);
    g.addEdge(3,4);
    g.addEdge(3,5);
    g.addEdge(2,3);

    g.printAdj();
    return 0;
}