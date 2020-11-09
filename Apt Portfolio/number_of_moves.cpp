#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

void bfs(int ux, int uy, int vx, int vy, int n, int &min_dist){
    if(ux == vx and uy == vy){
        min_dist = 0;
        return;
    }
    vector<vector<bool> > visited(n+1, vector<bool>(n+1, false));
    vector<vector<int> > distance(n+1, vector<int>(n+1, 0));
    queue<pair<int, int> > q;
    q.push(make_pair(ux, uy));
    visited[ux][uy] = true;
    distance[uy][uy] = 0;
    while(!q.empty()){
        pair<int, int> front = q.front();
        int nodex = front.first, nodey = front.second;
        visited[nodex][nodey] = true;
        if(nodex == vx and nodey == vy){
            min_dist = distance[nodex][nodey];
            return;
        }
        q.pop();
        int x[] = {-2, -2, -1, -1, 1, 1, 2, 2};
        int y[] = {-1, 1, -2, 2, -2, 2, -1, 1};
        for(int k = 0; k < 8; k++){
            int nx = nodex + x[k], ny = nodey + y[k];
            if(nx >= 1 and nx <= n and ny >= 1 and ny <= n and !visited[nx][ny]){
                q.push(make_pair(nx, ny));
                distance[nx][ny] = distance[nodex][nodey] + 1;
            }
        }
    }
    if(visited[vx][vy]==false)
        min_dist = -1;
}

int main(){
    int n = 9;
    int ux = 4, uy = 4;
    int vx = 4, vy = 7;
    int min_dist;
    bfs(ux, uy, vx, vy, n, min_dist);
    cout<<"Min distance "<<min_dist<<endl;
    return 0;
}