#include <iostream>
#include <string>
#include <vector>
#include <limits.h>

using namespace std;

int main(){
    int savings = 250;
    int current_value[] = {175, 133, 109, 210, 97};
    int future_value[] = {200, 125, 128, 228, 133};

    int n = sizeof(current_value) / sizeof(current_value[0]);
    vector<int> profit(n, 0);
    for(int i = 0; i < n; i++){
        profit[i] = future_value[i] - current_value[i];
    }
    vector<vector<int> >knapsack (n+1, vector<int>(savings+1, 0));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= savings; j++){
            if(current_value[i-1] <= j)
                knapsack[i][j] = max(knapsack[i-1][j], knapsack[i-1][j-current_value[i-1]] + profit[i-1]);
            else
                knapsack[i][j] = knapsack[i-1][j];
        }
    }    
    cout<<"Max profit "<<knapsack[n][savings]<<endl;
    return 0;
}