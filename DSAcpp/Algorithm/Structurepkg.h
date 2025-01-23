#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <queue>
using namespace std;
#define br cout << '\n'
#define pii pair<int,int>

class Graph
{
private:
    bool directed;
public:
    int nodes;
    vector<vector<pii>> graph;
    Graph(int n,bool dir = false){
        nodes = n;
        directed = dir;
        graph.resize(n);
    }
    void addEdge(int u,int v,int w);
    void readData(vector<vector<int>> &data);
    void print();
    vector<pii>* connected(int v);

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

vector<pii>* Graph::connected(int v){
    return &graph[v];
}

void Graph::print(){
    for(int i=0;i<nodes;i++){
        cout << i << " :";
        for(pair<int,int> &e:graph[i]){
            printf(" -> %d(%d)",e.first,e.second);
        }cout << '\n';
    }
}

class Disjn_set
{
private:
    int *arr = nullptr;
    int size = 0;
    int pathCompression(int a);
    int components = 0;
public:
    Disjn_set(int sz){
        arr = new int[sz];
        for(int i=0;i<sz;i++) arr[i]=i;
        components = size = sz;
    }
    int parent(int a);
    int getSize();
    int getComponentNum();
    void frnd(int a, int b);
    void print();
    bool isFrnd(int a, int b);
};

int Disjn_set::getSize(){
    return size;
}

int Disjn_set::getComponentNum(){
    return components;
}

int Disjn_set::pathCompression(int a){
    if(arr[a] == a) return a;
    arr[a] = pathCompression(arr[a]);
    return arr[a];
}

int Disjn_set::parent(int a){
    if(a<0 || a>=size) return -1;
    if(arr[a] == a) return a;
    return pathCompression(a);
}

void Disjn_set::frnd(int a,int b){
    if(a<0 || a>=size || b<0 || b>=size) return;
    arr[parent(a)] = parent(b);
    components--;
}

void Disjn_set::print(){
    for(int i=0;i<size;i++) 
        cout << i << '(' << arr[i] << ") ";
    cout << '\n';
}

bool Disjn_set::isFrnd(int a, int b){
    return parent(a)==parent(b);
}
