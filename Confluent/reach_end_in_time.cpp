#include <iostream>
#include <string>
#include <vector>
#include <limits.h>

using namespace std;

bool is_valid(pair<int, int> p, int m, int n){
    if(p.first >= 0 and p.first < m and p.second >= 0 and p.second < n)
        return true;
    return false;
}

int dfs(pair<int, int> start, pair<int, int> end, int time, 
        vector<vector<char> > &grid, vector<vector<bool> > &visited, int m, int n){
    visited[start.first][start.second] = true;
    if(grid[start.first][start.second] == '#')
        return INT_MAX;
    if(start == end)
        return time;
    int max_time = INT_MAX;
    int neighx[] = {-1, 0, 0, 1};
    int neighy[] = {0, -1, 1, 0};
    for(int i = 0; i < 4; i++){
        pair<int, int> neigh = make_pair(start.first + neighx[i], start.second + neighy[i]);
        if(is_valid(neigh, m, n) and !visited[neigh.first][neigh.second])
            max_time = min(max_time, dfs(neigh, end, time+1, grid, visited, m, n));
    }
    return max_time;
}

int main(){
    int m = 3, n = 4;
    vector<vector<char> > grid(m, vector<char>(n, '.'));
    grid[0][2] = '#';
    grid[0][3] = '#'; 
    grid[1][0] = '#'; 
    grid[1][2] = '#';  
    grid[1][3] = '#'; 
    grid[2][0] = '#'; 
    /*
    . . # #
    # . # #
    # . . .
    */
    int max_time = 5;

    vector<vector<bool> > visited(m , vector<bool>(n, false));
    pair<int, int> start, end;
    start = make_pair(0, 0);
    end = make_pair(m-1, n-1);

    int start_time = 0;
    int time_taken = dfs(start, end, start_time, grid, visited, m, n);
    if(time_taken <= max_time)
        cout<<"Yes";
    else
        cout<<"No";

    return 0;
}