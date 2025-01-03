#include<iostream>
#include<list>
#include<queue>
#include<vector>

using namespace std ;

class Graph{
    private:
        int V;
        list<int> *l;
    
    public:
        Graph(int v){
            V = v;
            l = new list<int>[V];
        }

        void addEdge(int i, int j){
            l[i].push_back(j);
        }

        void topological_sort(){
            vector<int> inDegree(V,0);

            //iterate over all the edges to find the right indegree
            for(int i=0;i<V;i++){
                for(auto nbr: l[i]){
                    inDegree[nbr]++;
                }
            }

            //bfs kind of logic
            queue<int> q;
            for(int i=0;i<V;i++){
                if(inDegree[i]==0){
                    q.push(i);
                }
            }
            //now we have the nodes with 0 indegree in the queue

            while (!q.empty())
            {
                int f = q.front();
                cout<<f<<", ";
                q.pop();
                for(auto nbr: l[f]){
                    inDegree[nbr]--;
                    if(inDegree[nbr]==0){
                        q.push(nbr);
                    }
                }
            }
            return;
        }
};

int main(){

    freopen("output.txt", "w", stdout);
    freopen("input.txt", "r", stdin);
    
    Graph g(7);

    g.addEdge(0,2);
    g.addEdge(1,2);
    g.addEdge(1,4);
    g.addEdge(2,3);
    g.addEdge(4,5);
    g.addEdge(3,5);
    g.addEdge(6,4);

    g.topological_sort();

    return 0;
}