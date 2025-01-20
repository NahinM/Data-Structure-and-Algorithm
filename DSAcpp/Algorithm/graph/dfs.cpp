#include "Structurepkg.h"

void dfs(Graph &graph, int start){
    int visited[graph.nodes] = {};
    stack<int> stk;
    visited[start] = 1;
    stk.push(start);
    while(!stk.empty()){
        int at = stk.top();
        stk.pop();
        for(pii u:*graph.connected(at)) if(!visited[u.first]) {
            stk.push(u.first);
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
    dfs(graph,5);
}