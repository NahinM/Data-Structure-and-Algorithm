#include "../Structurepkg.h"
#define Grid vector<string>


int row=0,col=0;
bool valid(int x, int y){
    return 0<=x && x<row && 0<=y && y<col;
}

int grid_dijkstra(Grid &grid,int ur,int uc){
    row = grid.size(); col = grid[0].length();
    int visited[row][col] = {};
    int distance[row][col];
    for(int i=0;i<row;i++) for(int j=0;j<col;j++) distance[i][j] = __INT32_MAX__;
    pii prev[row][col];
    queue<int> qr,qc;
    distance[ur][uc] = 0;
    visited[ur][uc] = 1;
    qr.push(ur); qc.push(uc);
    prev[ur][uc] = {ur,uc};
    int end_r,end_c;
    int dr[4] = {0,1,0,-1};
    int dc[4] = {1,0,-1,0};
    while (!qr.empty())
    {
        int r = qr.front(), c = qc.front();
        qr.pop();qc.pop();

        for(int i=0;i<8;i++) {
            int rr = r+dr[i], cc = c+dc[i];
            if(!valid(rr,cc)) continue;

            if(grid[rr][cc]=='E' && distance[rr][cc]>distance[r][c]+1){
                distance[rr][cc]=distance[r][c]+1;
                end_r = rr; end_c = cc;
            }
            if(!visited[rr][cc] && grid[rr][cc]!='#') {
                qr.push(rr); qc.push(cc);
                visited[rr][cc] = 1;
                distance[rr][cc]=distance[r][c]+1;
                prev[rr][cc] = {r,c};
            }
        }
    }

    int walk_r = end_r, walk_c = end_c;
    while(true){
        pii p = prev[walk_r][walk_c];
        walk_r = p.first;
        walk_c = p.second;
        if(grid[walk_r][walk_c] == 'S') break;
        grid[walk_r][walk_c] = '+';
    }

    for(int i=0;i<row;i++){
        cout << grid[i] << '\n';
    }

    return distance[end_r][end_c];
}

int main(){
    Grid grid = {
        "..........",
        "..........",
        "..........",
        "...S......",
        "......####",
        "####......",
        "..........",
        "..########",
        ".........E",
        ".........."
    };

    cout << grid_dijkstra(grid,3,3) << '\n';
}