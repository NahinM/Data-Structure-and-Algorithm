#include <iostream>
#include <vector>
using namespace std;

class Edge
{
public:
    int data;
    int weight;
    Edge *next= nullptr;
    Edge(int d,int w){
        data = d;
        weight = w;
    }
};

class Connected
{
public:
    Edge *head = nullptr;
    void push(int d,int w);
    void print();
};

void Connected::push(int d, int w){
    Edge *new_E = new Edge(d,w);
    new_E->next = head;
    head = new_E; 
}

void Connected::print(){
    for( Edge *tem = head; tem != nullptr; tem = tem->next)
        printf(" -> %d(%d)",tem->data,tem->weight);
    cout << '\n';
}

class Graph
{
private:
    bool directed = true;

public:
    int nodes;
    Connected *graph = nullptr;
    Graph(int size = 50,bool dir = true){
        graph = new Connected[size];
        directed = dir;
        nodes = size;
    }

    void addEdge(int v,int u,int w);
    void print();
    void readData(vector<vector<int>> &data);
    Edge* connected(int v);
};

Edge* Graph::connected(int v){
    return graph[v].head;
}

void Graph::addEdge(int u,int v,int w=1){
    graph[u].push(v,w);
    if(!directed) graph[v].push(u,w);
}

void Graph::readData(vector<vector<int>> &data){
    for(vector<int> &e:data){
        addEdge(e[0],e[1],(e.size()==3?e[2]:1));
    }
}

void Graph::print(){
    for(int i=0;i<nodes;i++){
        cout << i << " :";
        graph[i].print();
    }cout << '\n';
}