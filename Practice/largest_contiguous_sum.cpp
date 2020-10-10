#include <iostream>
#include <string>
#include <vector>
#include <limits.h>

using namespace std;

int main(){
    int arr[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int sum = 0, max_sum = INT_MIN;
    for(int i = 0; i < n; i++){
        sum += arr[i];
        max_sum = max(sum, max_sum);
        sum = max(sum, 0);
    }
    cout<<"Max contiguous sum "<<max_sum<<endl;
    return 0;
}