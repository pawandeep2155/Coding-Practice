#include <iostream>
#include <string>
#include <vector>
#include <limits.h>

using namespace std;

int main(){
    int arr[] = {-2, -3, -1, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int sum = 0, max_sum = INT_MIN;
    int current_start = 0, start, end;
    for(int i = 0; i < n; i++){
        sum += arr[i];
        if(sum > max_sum){
            max_sum = sum;
            start = current_start;
            end = i;
        }
        if(sum < 0){
            sum = 0;
            current_start = i + 1;
        }
    }
    cout<<"Max contiguous sum "<<max_sum<<" Start "<<start<<" End "<<end<<endl;
    return 0;
}