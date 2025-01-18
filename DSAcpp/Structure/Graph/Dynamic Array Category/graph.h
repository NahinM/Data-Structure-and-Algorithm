#include <iostream>
#include <vector>
using namespace std;

class Graph
{
private:
    bool directed;
public:
    int nodes;
    vector<vector<pair<int,int>>> graph;
    Graph(int n,bool dir = true){
        nodes = n;
        directed = dir;
        graph.resize(n);
    }
    void addEdge(int u,int v,int w);
    void readData(vector<vector<int>> &data);
    void print();
    vector<int>* connected(int v);

};

void Graph::addEdge(int u,int v,int w=1){
    graph[u].push_back(make_pair(v,w));
    if(!directed) graph[v].push_back(make_pair(u,w));
}

void Graph::readData(vector<vector<int>> &data){
    for(vector<int> &e:data){
        addEdge(e[0],e[1],(e.size()==3?e[2]:1));
    }
}

void Graph::print(){
    for(int i=0;i<nodes;i++){
        cout << i << " :";
        for(pair<int,int> &e:graph[i]){
            printf(" -> %d(%d)",e.first,e.second);
        }cout << '\n';
    }
}