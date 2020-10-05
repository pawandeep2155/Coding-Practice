#include <iostream>
#include <string>
#include <vector>
#include <limits.h>

using namespace std;

const int n = 3;

int pick_cherries(int r1, int c1, int c2, int grid[n][n], int cherry[n][n][n]){
    int r2 = r1 + c1 - c2;
    if(r1 == n or c1 == n or r2 == n or c2 == n or 
            grid[r1][c1] == -1 or grid[r2][c2] == -1)
        return INT_MIN;
    else if(r1 == n-1 and c1 == n-1)
        return grid[r1][c1];
    else if(cherry[r1][c1][c2] != INT_MIN)
        return cherry[r1][c1][c2];
    else{
        int ans = grid[r1][c1];
        if(c1 != c2)
            ans += grid[r2][c2];
        ans += max(pick_cherries(r1+1, c1, c2, grid, cherry), 
                max(pick_cherries(r1+1, c1, c2+1, grid, cherry),
                max(pick_cherries(r1, c1+1, c2, grid, cherry), 
                    pick_cherries(r1, c1+1, c2+1, grid, cherry))));
        cherry[r1][c1][c2] = ans;
        return ans;
    }
}

int main(){
    int grid[n][n] = {{0, 1, -1},
                     {1, 0, -1},
                     {1, 1,  1}};
    int cherry[n][n][n];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++){
                cherry[i][j][k] = INT_MIN;
            }
        }
    }

    int cherry_picked = max(0, pick_cherries(0, 0, 0, grid, cherry));
    cout<<"Cherries Picked up "<<cherry_picked<<endl;
}