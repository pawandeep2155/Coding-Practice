#include <map>
#include <vector>
#include <iostream>
#include <limits.h>
#include <stack>
#include <string> 

using namespace std;

int perfect_substring(string s, int n, int k){
    int ans = 0;
    for(int i = 0; i < n; i++){
        int x[26] = {0};
        for(int j = i; j < n; j++){
            int val = s[j] - 'a';
            x[val]++;
            int is_perfect = 1;
            for(int l = 0; l < 26; l++){
                if(x[l]%k!=0){
                    is_perfect = 0;
                    break;
                }
            }
            if(is_perfect){
                cout<<" i "<<i<<" j "<<j<<endl;
                ans++;
            }
        }
    }
    return ans;
}

int main(){
    string s= "aabccc";
    int k = 2;
    int n = s.size();
    cout<<perfect_substring(s, n, k)<<endl;
    return 0;
}