#include <iostream>
#include <string>
#include <vector>
#include <limits.h>

using namespace std;

int is_prime(int n){
    if(n < 2)
        return 0;
    for(int i = 2; i <= sqrt(n); i++){
        if(n%i == 0)
            return 0;
    }
    return 1;
}

int main(){
    string s = "####*###";
    int n = s.size();
    int r1 = 1, r2 = 2;
    vector<int> T(n+1, INT_MAX);
    T[1] = 0;
    int prime = 0;
    for(int i = 1; i <= n; i++){
        if(s[i-1] == '*')
            continue;
        if(i+1 <= n){
            T[i+1] = min(T[i+1], T[i] + 1);
        }
        if(i+2 <= n){
            T[i+2] = min(T[i+2], T[i] + 1);
        }
        if(is_prime(i))
            prime++;
        if(prime*r2 >= i*r1 and i+prime <= n){
            T[i+prime] = min(T[i+prime], T[i]+1);
        }
    }
    if(T[n] == INT_MAX)
        cout<<"No way!"<<endl;
    else 
        cout<<"Min jumps "<<T[n]<<endl;
    return 0;
}