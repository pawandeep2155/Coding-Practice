#include <iostream>
#include <string>
#include <vector>
#include <limits.h>
#include <math.h>

using namespace std;

int main(){
    int a[] = {2, 4, 5};
    int threshold = 10;
    int n = sizeof(a) / sizeof(a[0]);
    int max_element = INT_MIN;
    for(int i = 0; i < n; i++){
        max_element = max(max_element, a[i]);
    }
    int start = 1, end = max_element, mid, min_divisor = max_element;
    while(start <= end){
        mid = (end - start)/2 + start;
        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += ceil(a[i]/mid);
        }
        cout<<start<<mid<<end<<sum<<" ";
        if(sum > threshold){
            start = mid + 1;
        }
        else{
            min_divisor = min(min_divisor, mid);
            end = mid - 1;
        }
    }
    cout<<"Minimum divisor is "<<min_divisor<<endl;
    return 0;
}