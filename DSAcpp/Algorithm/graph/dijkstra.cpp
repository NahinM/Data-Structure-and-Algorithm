#include "../Structurepkg.h"

#define INF 2147483647
#define rept(i,a,b) for(int i=a;i<b;i++)


void dijkstra(Graph &graph,int from,int to){
    priority_queue<pii> pq;
    vector<int> distance(graph.nodes,INF);
    vector<int>prev(graph.nodes);
    distance[from] = 0;
    prev[from]=from;
    pq.push(make_pair(0,from));


    while(!pq.empty()){
        pii tem = pq.top();
        int at=tem.second, d=tem.first;
        pq.pop();
        for(pii &e:*graph.connected(at)){
            int v=e.first,w=e.second;
            if(d+w < distance[v]){
                pq.push(make_pair(d+w,v));
                distance[v] = d+w;
                prev[v]=at;
            }
        }
    }

    cout << "Distance : " << distance[to];br;
    cout << "Path : ";
    for(int i = to; i!=prev[i]; i = prev[i]) cout << i << " -> "; cout << from;br;
}

int main(){
    vector< vector<int> > data = {
        {0, 2, 2 },
        {0, 4, 5 },
        {0, 5, 1 },
        {1, 4, 2 },
        {1, 5, 1 },
        {2, 3, 6 },
        {2, 4, 10},
        {4, 5, 7 }
    };
    Graph graph(6,false);
    graph.readData(data);
    graph.print();br;
    dijkstra(graph,4,3);
}


// 0 2 2
// 0 4 5
// 0 5 1
// 1 4 2
// 1 5 1
// 2 3 6
// 2 4 10
// 4 5 7