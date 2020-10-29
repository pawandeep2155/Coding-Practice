#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <limits.h>

using namespace std;

int find_cost(vector<int> &v, int size){
    int mid = size/2;
    int median;
    if(size %2 == 0){
        median = (v[mid-1] + v[mid])/2;
    }
    else 
        median = v[mid];
    int cost = 0;
    for(int i = 0; i < size; i++){
        cost += abs(median - v[i]);
    }
    return cost;
}

int main(){
    string s[] = {"chakshu", "pekka", "punk", "golem", "tyagi"};
    int n = 5;
    string min_string, max_string;
    int min_cost = INT_MAX, max_cost = INT_MIN;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        string t = s[i];
        int cost = 0;
        for(int j = 0; j < t.size(); j++){
            cost += (t[j]-'a') + 1;
        }
        v[i] = cost;
        if(cost > max_cost){
            max_cost = cost;
            max_string = t;
        }
        if(cost < min_cost){
            min_cost = cost;
            min_string = t;
        }
    }
    sort(v.begin(), v.end());
    vector<int> b(v.begin(), v.end()-1);
    vector<int> c(v.begin()+1, v.end());
    int cost1 = find_cost(b, n-1);
    int cost2 = find_cost(c, n-1);
    if(cost1 < cost2)
        cout<<max_string<<endl;
    else 
        cout<<min_string<<endl;

    return 0;
}