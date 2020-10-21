#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <limits.h>
#include <queue>

using namespace std;

struct Node{
    int x;
    int y;
    int d;
};

int main(){
    
    int M = 3, N = 5, Y = 2, X = 3, P = 1;
    int graph[3][5] = {{0, 0, 0, 0, 0}, 
                       {0, 1, 0, 0, 0}, 
                       {0, 0, 0, 0, 0}};
    int holes[2][3] = {{1, 3, 1}};
    map<pair<int, int>, int> m;
    for(int i = 0; i < P; i++){
        m[make_pair(holes[i][1]-1, holes[i][0]-1)] = holes[i][2];
    }
    queue<Node> q;
    int time = 0;
    vector<vector<bool> > visited(M, vector<bool>(N, false)); 
    vector<vector<int> > distance(M, vector<int>(N, 0));
    Node home = {0, 0, -1};
    q.push(home);
    visited[0][0] = true;

    while(!q.empty()){
        Node node = q.front();
        q.pop();
        int x = node.x, y = node.y, d = node.d;
        pair<int, int> loc = make_pair(x, y);
        if(m.find(loc) != m.end() and m[loc] > time){
            continue;
        }
        int neigh_x[] = {-1, 0, 0, 1};
        int neigh_y[] = {0, -1, 1, 0};
        for(int i = 0; i < 4; i++){
            int nx = x + neigh_x[i], ny = y + neigh_y[i];
            pair<int, int> n = make_pair(nx, ny);
            int hole_time = (m.find(n) == m.end())?INT_MAX:m[n];
            if(nx >= 0 and nx <= M-1 and ny >= 0 and ny <= N-1 and time < hole_time and graph[nx][ny] == 0 and !visited[nx][ny]){
                distance[nx][ny] = d + 1;
                cout<<" x "<<x<<" y "<<y<<" nx "<<nx<<" ny "<<ny<<" d "<<distance[nx][ny]<<endl;
                visited[nx][ny] = true;
                Node nnode = {nx, ny, distance[nx][ny]};
                q.push(nnode);
                if(nx == X-1 and ny == Y-1){
                    cout<<"Shortest path "<<distance[X-1][Y-1]<<endl;
                    return 0;
                }
            }
        }
        time++;
    }
    cout<<"Work from Home"<<endl;
    return 0;
}