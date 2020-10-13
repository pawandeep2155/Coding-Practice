#include <iostream>
#include <string>
#include <vector>
#include <limits.h>

using namespace std;

int main(){
    int A[] = {1, 3, 4, 5};
    int n = sizeof(A) / sizeof(A[0]);
    int target = 10;
    int soln = INT_MAX;
    vector<vector<long long int> > dp(n+1, vector<long long int>(target+1, INT_MAX));

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= target; j++){
            if(A[i-1] > j)
                dp[i][j] = dp[i-1][j];
            else if(A[i-1] == j){
                dp[i][j] = 1;
            }
            else{
                dp[i][j] = min(dp[i-1][j], min(1+dp[i][j-A[i-1]], 1+dp[i-1][j-A[i-1]]));
            }
            if(j == target)
                soln = min(soln, (int)dp[i][j]);
        }
    }
    if(soln == INT_MAX)
        cout<<"No solution found"<<endl;
    else
        cout<<"Minimum umbrellas required "<<soln<<endl;
    return 0;
}