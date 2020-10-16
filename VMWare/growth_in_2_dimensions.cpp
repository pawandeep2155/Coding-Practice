#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <limits.h>

using namespace std;

int main(){
    int A[][2] = {{5, 6}, {3, 4}, {7, 3}};
    int n = 3;
    int min_x = INT_MAX, min_y = INT_MAX;
    for(int i = 0; i < n; i++){
        min_x = min(min_x, A[i][0]);
        min_y = min(min_y, A[i][1]);
    }
    cout<<"Max value elements are "<<min_x*min_y<<endl;
    return 0;
}