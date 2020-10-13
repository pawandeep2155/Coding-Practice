#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <limits.h>

using namespace std;

int main(){
    string name[] = {"ball", "bat", "glove", "glove", "glove"};
    int price[] = {2, 3, 1, 2, 1};
    int tag[] = {2, 5, 1, 1, 1};
    int n = sizeof(name) / sizeof(name[0]);
    map<vector<string>, int> m;
    for(int i = 0; i < n; i++){
        vector<string> t;
        t.push_back(name[i]);
        t.push_back(to_string(price[i]));
        t.push_back(to_string(tag[i]));
        m[t]+=1;
    }
    cout<<"Num of duplicates "<<n-m.size()<<endl;
    return 0;
}