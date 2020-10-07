#include <iostream>
#include <string>
#include <vector>
#include <limits.h>

using namespace std;

void print_grid(int grid[3][3]){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    const int n = 3;
    int grid[n][n] = {{2, 2, 2}, 
                      {3, 3, 3}, 
                      {4, 4, 4}};
    int max_sum = 16;
    int dp[n][n][n] = {0};
    int soln = 0;
    for(int i = 0; i < n; i++){
        int sum;
        for(int j = 0; j < n-i; j++){
            for(int k = 0; k < n-i; k++){
                sum = 0;
                if(i==0)
                    dp[i][j][k] = grid[j][k];
                else{
                    dp[i][j][k] = dp[i-1][j][k];
                    for(int p = j; p <= j+i; p++){
                        dp[i][j][k] += grid[p][k+i];
                    }
                    for(int p = k; p < k+i; p++){
                        dp[i][j][k] += grid[j+i][p];
                    }
                }
                sum += dp[i][j][k];
            }
        }         
        if(sum < max_sum)
            soln = i+1;
        else
            break;
    }
    cout<<"Max size grid "<<soln<<endl;
    return 0;
}