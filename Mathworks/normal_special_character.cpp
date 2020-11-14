#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

void print(deque<int> d, int n){
    for(int i = 0; i < n; i++){
        cout<<d[i]<<" ";
    }
}

int main(){
    string s = "0100110111011";
    int n = s.size();
    int k = 1;
    int soln = 0, count = 0;
    deque<int> d;
    for(int i = 0; i < n; i++){
        if(s[i]=='1' or count < k){
            d.push_back(s[i]-'0');
            count += (s[i]=='0');
        }
        else{
            while(d.size() > 0 and d[0]==1){
                d.pop_front();
            }
            d.pop_front();
            d.push_back(0);
        }
        soln = max(soln, (int)d.size());
        print(d, (int)d.size());
        cout<<" window "<<(int)d.size()<<" soln "<<soln<<endl;
    }
    cout<<"max contiguous zeros with max k zeros "<<soln<<endl;
    return 0;
}