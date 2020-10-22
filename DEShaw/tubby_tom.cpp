#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <limits.h>

using namespace std;

void dfs(int node, int p, int depth, vector<int> adj[], int dist[]){
    dist[node] = depth;
    for(int i:adj[node]){
        if (i == p) continue;
        dfs(i,node,depth+1,adj,dist);
    }
}
 
int min_time(int G_nodes, vector<int> G_from, vector<int> G_to
, int D, int C){
 
    vector<int> adj[G_nodes+1];
    for(int i=0;i<G_nodes-1;i++){
        adj[G_from[i]].push_back(G_to[i]);
        //Edges are undirected
        adj[G_to[i]].push_back(G_from[i]);
    }
 
    int distance_d[G_nodes+1], distance_c[G_nodes+1];
    dfs(D,D,0,adj,distance_d);
    dfs(C,C,0,adj,distance_c);
    int ans = 1;
    for(int i=1;i<=G_nodes;i++){
        if (distance_d[i] > distance_c[i]+1){
            ans = max(ans, distance_d[i]*2 -1);
        }
    }
    return ans;
}
int main(){
    int from[] = {1, 3, 2};
    int to[] = {2, 4, 3};
    int D = 4, C = 2;
    vector<int> g_from(from, from+3);
    vector<int> g_to(to, to+3);
    cout<<min_time(4, g_from, g_to, D, C)<<endl;
    return 0;
}