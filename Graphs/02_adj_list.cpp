#include<iostream>
#include<list>
#include<unordered_map>
#include<vector>
using namespace std ;


class Node{
private:
    string cityname;
    list<string> nbrs;

public:
    Node(string name){
        cityname = name;
    }

    friend class Graph;
};

class Graph{

public:
    //All Nodes
    //Hashmap
    unordered_map<string, Node*> m;

    Graph(vector<string> cities){
        for(auto city: cities){
            m[city]= new Node(city);
        }
    }

    void AddEdge(string x, string y, bool undir = false){
        m[x]->nbrs.push_back(y);
        if(undir){
            m[y]->nbrs.push_back(x);
        }
    }

    void print(){
        for(auto city: m){
            auto cityname = city.first;
            Node* node = city.second;
            cout<<cityname<<"-> ";
            for(auto nbr: node->nbrs){
                cout<<nbr<<", ";
            }
            cout<<endl;
        }
    }
};

int main(){
    
    freopen("output.txt", "w", stdout);
    freopen("input.txt", "r", stdin);
        
    vector<string> cities = {"Delhi","London","Paris","New York"};
    Graph g(cities);

    g.AddEdge("Delhi","London");
    g.AddEdge("New York","London");
    g.AddEdge("Delhi","Paris");
    g.AddEdge("Paris","New York");

    g.print();

    return 0;
}