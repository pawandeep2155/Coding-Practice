#include <iostream>
#include <string>
#include <vector>
#include <limits.h>

using namespace std;

bool is_palindromic(vector<int> &path){
    vector<int> counts(27, 0);
    for(int i = 0; i < path.size(); i++){
        counts[path[i]]++;
    }
    int odd_counts = 0;
    for(int i  = 1; i <= 26; i++){
        if(counts[i] % 2 == 1){
            if(path.size() %2 == 0)
                return false;
            else if(odd_counts == 0)
                odd_counts++;
            else 
                return false;
        }
    }
    return true;
}

void dfs(int node, vector<vector<int> > & graph, vector<int> path, int parent, vector<int> &visited, int &path_count, int v){
    if(visited[node])
        return;
    visited[node] = true;
    if(path.size() == 1 or (path.size() > 1 and is_palindromic(path)))
        path_count++;
    for(int i = 1; i <= v; i++){
        int neighbor = i;
        if(!graph[node][neighbor] or visited[neighbor])
            continue;
        path.push_back(graph[node][neighbor]);
        dfs(i, graph, path, node, visited, path_count, v);        
    }
}

int palindromic_path(vector<vector<int> > &graph, int v){
    int path_count = 0;
    int parent = -1;
    for(int i = 1; i <= v; i++){
        vector<int> path;
        vector<int> visited(v+1, false);
        dfs(i, graph, path, parent, visited, path_count, v);
    }
    return path_count;
}

int main(){
    int edges[][3] = {{1, 2, 1}, {1, 3, 3}, {2, 4, 2}, {2, 5, 1}, {3, 6, 3}, {3, 7, 4}};
    int e = sizeof(edges) / sizeof(edges[0]); 
    int v = e + 1;
    vector<vector<int> > graph(v+1, vector<int>(v+1, 0));
    for(int i = 0; i < e; i++){
        int u = edges[i][0], v = edges[i][1], weight = edges[i][2];
        graph[u][v] = weight;
        graph[v][u] = weight;
    }
    cout<<" Number of palindromic paths "<<palindromic_path(graph, v) / 2<<endl;
    return 0;
}