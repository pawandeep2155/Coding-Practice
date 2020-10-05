#include <iostream>
#include <string>
#include <vector>
#include <limits.h>
#include <math.h>

using namespace std;

void print_solution(vector<string> &super_parent){
    for(int i = 0; i < super_parent.size(); i++)
        cout<<super_parent[i]<<" ";
}

int main(){
    string parent[] = {"hiroshima", "hitler", "honolulu", "hismanic"};
    string child[] = {"hii", "mah", "his"};

    int m = sizeof(parent) / sizeof(parent[0]);
    int n = sizeof(child) / sizeof(child[0]);

    vector<string> parent_vec, child_vec;

    for(int i = 0; i < m; i++){
        string t = parent[i];
        sort(t.begin(), t.end());
        parent_vec.push_back(t);
    }
    for(int i = 0; i < n; i++){
        string t = child[i];
        sort(t.begin(), t.end());
        child_vec.push_back(t);
    }

    vector<string> super_parent;
    for(int i = 0; i < m; i++){
        bool is_super = true;
        for(int j = 0; j < n; j++){
            if(parent_vec[i].find(child_vec[i]) == string::npos){
                is_super = false;
                break;
            }
        }
        if(is_super)
            super_parent.push_back(parent[i]);
    }
    print_solution(super_parent);
    return 0;
}