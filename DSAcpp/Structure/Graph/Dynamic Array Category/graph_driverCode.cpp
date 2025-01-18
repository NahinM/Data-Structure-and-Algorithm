#include <iostream>
#include "graph.h"
#include <vector>
using namespace std;

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
    Graph graph = Graph(6);
    graph.readData(data);
    graph.print();
}