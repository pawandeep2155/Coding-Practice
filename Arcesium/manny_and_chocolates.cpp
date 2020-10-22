// Note :- Code is not fully implemented yet. Some logical error exists

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <limits.h>
#include <queue>

using namespace std;

void print_array(vector<vector<int> > &v){
    for(int i = 0; i < v.size(); i++){
        for(int j = 0; j < v[0].size(); j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    int n = 3, k = 2;
    vector<vector<int> > dp(n+1, vector<int>(k+1, 0));
    dp[1][0] = 1, dp[1][1] = 2, dp[1][2] = 1;
    for(int i = 2; i <= n; i++){
        for(int j = 0; j <= k; j++){
            if(j == 0)
                dp[i][j] = 1;
            else
                dp[i][j] = dp[i-1][max(j-2, 0)] * dp[1][j] + dp[i-1][j] * dp[1][0] + dp[i-2][j-1] * dp[1][1];
        }
    }
    print_array(dp);
    cout<<"Number of chocolates "<<dp[n][k]<<endl;
    return 0;
}