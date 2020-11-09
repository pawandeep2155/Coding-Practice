/*
    Given tree with N vertices and N-1 edges. Each vertex has stones piled. Alex and bob
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void dfs(int u, int v, vector<bool> &visited, int parent, vector<vector<int> > &graph, int stones[], int &xor_value){
    if(parent == -1)
        parent = stones[u];
    else 
        parent = parent ^ stones[u];
    if(u == v){
        xor_value = parent;
        return;
    }
    visited[u] = true;
    for(int i = 0; i < (int)graph[u].size(); i++){
        int neigh = graph[u][i];
        if(!visited[neigh])
            dfs(neigh, v, visited, parent, graph, stones, xor_value);
    }
}
 
int main(){
    int n = 8;
    int stones[] = {0, 2, 3, 4, 4, 2, 3, 2, 1};
    int edges[][2] = {{1, 2}, {1, 3}, {2, 4}, {2, 5}, {5, 6}, {6, 7}, {4, 8}};
    int q1 = 3, q2 = 6;
    int e = n-1;
    vector<vector<int> > graph(n+1);
    for(int i = 0; i < e; i++){
        int u = edges[i][0], v = edges[i][1];
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    vector<bool> visited(n+1, false);
    int xor_value;
    dfs(q1, q2, visited, -1, graph, stones, xor_value);
    if(xor_value != 0){
        cout<<"Bob"<<endl;
    }
    else{
        cout<<"Alex"<<endl;
    }
    return 0;
}