#include "Structurepkg.h"

void bfs(Graph &graph, int start){
    int visited[graph.nodes] = {};
    queue<int> Q;
    visited[start] = 1;
    Q.push(start);
    while(!Q.empty()){
        int at = Q.front();
        Q.pop();
        for(pii u:*graph.connected(at)) if(!visited[u.first]) {
            Q.push(u.first);
            visited[u.first]=1;
        }
        cout << at << ' ';
    }br;
}

int main(){
    vector<vector<int>> data = {
        {0, 2},
        {0, 4},
        {0, 5},
        {1, 4},
        {1, 5},
        {2, 3},
        {2, 4},
        {4, 5}
    };

    Graph graph(6,false);
    graph.readData(data);
    graph.print();br;
    bfs(graph,5);
}