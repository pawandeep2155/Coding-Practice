#include <iostream>
#include <string>
#include <vector>
#include <limits.h>
#include <math.h>

using namespace std;

int main(){
    int a[][2] = {{1, 2}, {2, 1}, {5, 10}, {10, 9}, {19, 20}};
    int n = sizeof(a) / sizeof(a[0]);
    int fall_count = 0;
    vector<pair<int, int> > posn(n+1);
    posn[0] = make_pair(INT_MIN, INT_MIN);

    for(int i = 0; i < n; i++){
        int left_extreme = a[i][0] - a[i][1];
        int right_extreme = a[i][0] + a[i][1];
        if(left_extreme > posn[i].second){
            posn[i+1] = make_pair(left_extreme, a[i][0]);
            fall_count++;
        }
        else if(i==n-1 or right_extreme < a[i+1][0]){
            posn[i+1] = make_pair(a[i][0], right_extreme);
            fall_count++;
        }
        else{
            posn[i+1] = make_pair(a[i][0], a[i][0]);
        }
    }
    cout<<"Max Dominos To Fall "<<fall_count<<endl;
}