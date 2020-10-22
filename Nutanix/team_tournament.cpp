#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

bool is_bipartite(vector<vector<int> > &graph){
    int v = graph.size();
    int node = 1;
    queue<int> q;
    q.push(node);
    vector<bool>visited(v+1, false);
    vector<int> parent(v+1, -1);
    vector<int> color(v+1, -1);
    color[node] = 1;
    visited[node] = true;
    while(!q.empty()){
        int top = q.front();
        int top_color = color[top];
        q.pop();
        for(int i = 0; i < graph[top].size(); i++){
            int neighbor = graph[top][i];
            if(!visited[neighbor]){
                q.push(neighbor);
                visited[neighbor] = true;
                parent[neighbor] = top;
                color[neighbor] = 1 - top_color;
            }
            if(visited[neighbor] and parent[node] != neighbor and color[neighbor] == top_color){
                return false;
            }
        }
    }
    return true;
}

int main(){
    int N = 4, M = 3;
    vector<vector<int> > graph(N+1);
    int edges[][2] = {{1, 2}, {2, 3}, {3, 4}};
    int max_edges = 0;
    for(int i = 0; i < M; i++){
        int u = edges[i][0], v = edges[i][1];
        graph[u].push_back(v);
        graph[v].push_back(u);
        if(is_bipartite(graph)){
            max_edges++;
        }
        else
            break;
    }
    cout<<" Max matches that can be played "<<max_edges<<endl;
    return 0;
}