#include <iostream>
#include <string>
#include <vector>
#include <limits.h>

using namespace std;

int grid_sum(int grid[3][3], int k){
    int dp[3][3];
    // Fill vertical strips
    for(int j = 0; j < 3; j++){
        // Sum first k 
        int sum = 0;
        for(int i = 0; i < k; i++){
            sum += grid[i][j];
        }
        dp[0][j] = sum;
        // Sum remaining k
        for(int i = 1; i <= 3-k; i++){
            sum += grid[i+k-1][j] - grid[i-1][j];
            dp[i][j] = sum;
        }
    }
    int max_sum = INT_MIN;
    for(int i = 0; i <= 3-k; i++){
        int sum = 0;
        // Sum first k 
        for(int j = 0; j < k; j++){
            sum += dp[i][j];
        }
        max_sum = max(sum, max_sum);
        // Sum remaining k
        for(int j = 1; j <= 3-k; j++){
            sum += dp[i][j+k-1] - dp[i][j-1];
            max_sum = max(sum, max_sum);
        }
    }
    return max_sum;
}

int main(){
    const int n = 3;
    int grid[n][n] = {{2, 2, 2}, 
                      {3, 3, 3}, 
                      {4, 4, 4}};
    int max_sum = 26;
    int low = 1, high = n;
    int soln = 0;
    while(low <= high){
        int mid = (low+high)/2;
        int max_grid_sum = grid_sum(grid, mid);
        if(max_grid_sum > max_sum){
            high = mid - 1;
        }
        else if(max_grid_sum < max_sum){
            soln = max(soln, mid);
            low = mid + 1;
        }
        else{
            soln = mid;
            break;
        }
    }
    cout<<"Soln is "<<soln<<endl;
    return 0;
}