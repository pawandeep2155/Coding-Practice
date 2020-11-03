#include <map>
#include <vector>
#include <iostream>
#include <limits.h>
#include <stack>
#include <string> 

using namespace std;

bool comp(string &a, string &b){
    if(a.size() < b.size()){
        return true;
    }
    return false;
}
    
int longestStrChain(vector<string>& words) {
    int n = words.size();
    vector<int> dp(n,0);
    // custom function used to sort array with respect to length
    sort(words.begin(),words.end(),comp);
    int count[26][n];
    memset(count,0,sizeof count);
    // storing count of every word
    for(int i = 0; i < n; i++){
        for(int j = 0; j < words[i].size();j++){
            count[words[i][j]-'a'][i]++;
        }
    }
    for(int i = 0; i < n; i++){
        dp[i] =1;
        for(int j = 0; j < i; j++){
            int diff = 0;
            for(int k = 0; k< 26; k++){
                diff += abs(count[k][i]-count[k][j]);
            }
            // Using LIS condition
            if(diff == 1){
                dp[i] = max(dp[i],dp[j]+1);
            }
        }
    }
    return *max_element(dp.begin(),dp.end());
}


int main(){
    string s[] = {"a", "b", "ba", "bca", "bda", "bdca"};
    int n = sizeof(s) / sizeof(s[0]);
    vector<string> v(s, s+n);
    int max_depth = longestStrChain(v);
    cout<<"max depth "<<max_depth<<endl;
    return 0;
}