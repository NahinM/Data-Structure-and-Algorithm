#include "../Structurepkg.h"

#define Grid vector<string>

int row=0,col=0;
bool valid(int x, int y){
    return 0<=x && x<row && 0<=y && y<col;
}

void bfs(const Grid &grid,int x,int y){
    row = grid.size(); col = grid[0].length();
    if(x<0 || x>=row || y<0 || y>=col) return;
    int dr[8] = {-1,0,1,1,1,0,-1,-1};
    int dc[8] = {1,1,1,0,-1,-1,-1,0};
    int visited[row][col] = {};
    visited[x][y] = 1;
    queue<int> Qx,Qy;
    Qx.push(x); Qy.push(y);


    while(!Qx.empty()){
        int r = Qx.front(), c = Qy.front();
        Qx.pop(); Qy.pop();

        for(int i=0;i<8;i++) {
            int rr = r+dr[i], cc = c+dc[i];
            if(valid(rr,cc) && !visited[rr][cc]){
                Qx.push(rr); Qy.push(cc);
                visited[rr][cc] = 1;
            }
        }
        cout << grid[r][c] << '\n';
    }
}

int main(){
    Grid grid = {
        "12345",
        "12345",
        "12345",
        "12345",
        "12345"
    };
    // string s;
    // while(cin >> s) grid.push_back(s);

    bfs(grid,2,2);
}