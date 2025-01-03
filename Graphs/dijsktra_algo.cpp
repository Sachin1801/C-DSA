#include<iostream>
#include<list>
#include<set>
#include<vector>
#include<climits>
using namespace std ;

class Graph{
    private:
        int V;
        list<pair<int,int>> *l;
    
    public:
        Graph(int v){
            V = v;
            l = new list<pair<int, int>>[V];
        }

        void addEdge(int i, int j, int wt, bool undir = true){
            l[i].push_back({wt,j});
            if(undir){
                l[j].push_back({wt,i});
            }
        }

        int dijsktra(int src, int dest){

            vector<int> dist(V,INT_MAX);
            set<pair<int,int> > s;

            dist[src]=0;
            s.insert(make_pair(0,src));

            while (!s.empty())
            {
                auto it = s.begin();
                int node = it->second;
                int distTillNow = it->first;
                s.erase(it);

                for(auto nbrPair: l[node]){
                    int nbr = nbrPair.second;
                    int currentDist = nbrPair.first;

                    if(distTillNow + currentDist < dist[nbr]){

                        //remove if such a pair already exists
                        auto f = s.find(make_pair(dist[nbr],nbr));
                        if(f!=s.end()){
                            s.erase(f);
                        }
                        
                        dist[nbr] = distTillNow + currentDist;
                        s.insert(make_pair(dist[nbr],nbr));
                    }
                }
            }

            for(int i=0;i<V;i++){
                cout<<"Node 0 "<<i << " Dist "<<dist[i]<<endl;
            }
            
            return dist[dest];
        }
};

int main(){

    freopen("output.txt", "w", stdout);
    freopen("input.txt", "r", stdin);

    Graph g(5);

    g.addEdge(0,1,1);
    g.addEdge(1,2,2);
    g.addEdge(0,2,4);
    g.addEdge(0,3,7);
    g.addEdge(3,2,2);
    g.addEdge(3,4,3);

    cout<< g.dijsktra(0,4)<<endl;   

    return 0;
}