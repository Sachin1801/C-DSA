#include<iostream>
#include<list> //doubly linked list 
using namespace std ;

class Graph{
    int V;
    list<int> *l;

    public:
        Graph(int v){
            V = v;
            l = new list<int>[V]; //this is an array of size v each element
                                // in the array is linked list pointer 
        }

        void addEdge(int i, int j, bool undir =true){
            l[i].push_back(j);
            if(undir)
                l[j].push_back(i);
        }

        void printAdj(){
            //iterate over all rows
            for(int i =0;i<V;i++){
                cout<<i<<"-->";
                for(auto node: l[i]){
                    cout<<node<<", ";
                }
                cout<<endl;
            }
        }
};
