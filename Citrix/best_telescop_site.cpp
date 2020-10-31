#include <iostream>
#include <map>
#include <vector>
#include <limits.h>
#include <stack>

using namespace std;    
    
int findTheCity(int n, vector<vector<int> >& edges, int dT) {
    
    vector<vector<int> > adj(n, vector<int>(n, INT_MAX/2));
    for(auto e : edges){ // Building Graphs
        adj[e[0]][e[1]] = adj[e[1]][e[0]] = e[2]; 
    }
    
    for(int i = 0 ; i< n ;i++){ // making self loop as 0
        adj[i][i] = 0;
    }
    
    for(int k = 0 ; k < n; k++){ // Floyd -Warshall
        for(int i = 0; i< n ; i++){
            for(int j =0 ; j< n ; j++){
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
                adj[j][i] = min(adj[i][j], adj[i][k] + adj[k][j]);
            }
        }
    }
    
    int count = INT_MAX;
    int ans = -1;
    for(int i = 0 ; i< n ;i++){
        int c = 0;
        for(int j =0 ; j< n ; j++){
            if(adj[i][j] <= dT) c++;
        }
        
        if(c<count || (c==count&&i>ans)){
            count = c;
            ans = i ;
        }
    }
    
    return ans;
}

int main(){
    int n = 4, distance_threshold = 4;
    int edges[][3] = {{0, 1, 3},
                        {1, 2, 1},
                        {1, 3, 4},
                        {2, 3, 1}};
    int e = sizeof(edges) / sizeof(edges[0]);
    vector<vector<int> > v(e, vector<int>(3, 0));
    for(int i = 0; i < 3; i++){
        v[i][0] = edges[i][0], v[i][1] = edges[i][1], v[i][2] = edges[i][2];
    }
    cout<<findTheCity(n, v, distance_threshold);
    return 0;
}