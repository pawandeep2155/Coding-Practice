#include <iostream>
#include <string>
#include <vector>
#include <limits.h>

using namespace std;

int main(){
    string s = "10011";
    int n = s.size();
    int x = 2;
    int ans = 0;
    for(int i = 0; i < n; i++){
        int count = 0;
        for(int j = i; j < n; j++){
            if(s[j] == '1')
                count++;
            if(count > x or (count == x and s[i]!='0')){
                ans++;
            }
        }
    }
    cout<<"answer is "<<ans<<endl;
    return 0;
}