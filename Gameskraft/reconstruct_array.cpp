#include <iostream>
#include <string>
#include <vector>
#include <limits.h>

using namespace std;


int cost(vector<int> &arr, int n){
    int max = arr[0];
    int count = 0;
    for(int i = 1; i < n; i++){
        if(max < arr[i]){
            count++;
            max = arr[i];
        }
    }
    return count;
}


void total_arrays(int index, vector<int> arr, int &total, int m, int n, int c){
    if(index == n){
        if(cost(arr, n) == c)
            total++;
        return;
    }
    for(int i = 1; i <= m; i++){
        arr[index] = i;
        total_arrays(index+1, arr, total, m, n, c);
    }
}

int main(){
    int m = 4, n = 4, c = 2;
    int total = 0;
    vector<int> v(n, 0);
    total_arrays(0, v, total, m, n, c);
    cout<<"total arrays possible "<<total<<endl;
    return 0;
}