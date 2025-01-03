#include<iostream>
#include<list>
using namespace std ;

class Graph{
    private:
        int v;
        list<int> *l;

    public:
        Graph(int v){
            this->v = v;
            l = new list<int>[v];
        }

        void addEdge(int i, int j, bool undir=true){
            l[i].push_back(j);
            if(undir){
                l[j].push_back(i);
            }
        }


    void dfs_helper(int src, bool *visited){
            visited[src]=true;
            cout<<src<<", ";
            for(auto nbr: l[src]){
                if(!visited[nbr])
                    dfs_helper(nbr,visited);
            }
            return;
        }

        void dfs(int src){
            bool *visited = new bool[v]{0};
            dfs_helper(src,visited);
        }

};

int main(){

    freopen("output.txt", "w", stdout);
    freopen("input.txt", "r", stdin);
    
    Graph g(7);

    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(4,5);
    g.addEdge(5,6);
    g.addEdge(3,5);
    g.addEdge(0,4);

    g.dfs(1);

    return 0;
}