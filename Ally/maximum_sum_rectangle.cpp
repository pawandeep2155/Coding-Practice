#include <iostream>
#include <string>
#include <vector>
#include <limits.h>

using namespace std;

vector<int> max_contig_sum(vector<int> &arr, int n){
    int sum = 0, max_sum = INT_MIN;
    int current_start = 0, start, end;
    for(int i = 0; i < n; i++){
        sum += arr[i];
        if(sum > max_sum){
            max_sum = sum;
            start = current_start;
            end = i;
        }
        if(sum < 0){
            sum = 0;
            current_start = i + 1;
        }
    }
    vector<int> soln;
    soln.push_back(max_sum);
    soln.push_back(start);
    soln.push_back(end);
    return soln;
}

int max_sum_rectangle(vector<vector<int> > &v, int m, int n){
    int curr_sum, max_sum = INT_MIN, max_left = 0, max_right = 0, max_up = 0, max_down = 0;
    for(int l = 0; l < n; l++){
        vector<int> dp(m, 0);
        for(int r = l; r < n; r++){
            for(int i = 0; i < m; i++)
                dp[i] += v[i][r];    
            vector<int> soln = max_contig_sum(dp, m);
            curr_sum = soln[0];
            if(curr_sum > max_sum){
                max_left = l;
                max_right = r;
                max_sum = curr_sum;
                max_up = soln[1];
                max_down = soln[2];
            }
        }
    }
    cout<<max_left<<" "<<max_up<<" "<<max_right<<" "<<max_down;
    return max_sum;
}

int main(){
    int a[][5] = {{1, 2, -1, -4, -20},  
                  {-8, -3, 4, 2, 1},  
                  {3, 8, 10, 1, 3},  
                  {-4, -1, 1, 7, -6}}; 
    int m = 4, n = 5;
    vector<vector<int> > grid(m, vector<int>(n, 0));
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            grid[i][j] = a[i][j];
        }
    }
    int max_sum = max_sum_rectangle(grid, m, n);
    cout<<"Max sum Rectangle "<<max_sum<<endl;
}