#include <map>
#include <vector>
#include <iostream>
#include <limits.h>
#include <stack>

using namespace std;

int main(){
    int q[] = {1, 3, 4};
    int p[] = {1, 2, 3, 4};
    int k = 2;
    int num_queries = sizeof(q) / sizeof(q[0]);
    int num_people = sizeof(p) / sizeof(p[0]);
    for(int i = 0; i < num_queries; i++){
        int filled = 0;
        int last_filled;
        for(int j = 0; j < num_people; j++){
            if(p[j] >= q[i]){
                filled++;
                last_filled = j+1;
            }
            if(filled == k)
                break;
        }
        if(filled == k){
            cout<<last_filled<<endl;
        }
        else 
            cout<<0<<endl;
    }
    return 0;
}