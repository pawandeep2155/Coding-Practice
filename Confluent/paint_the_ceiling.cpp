#include <iostream>
#include <string>
#include <vector>
#include <limits.h>

using namespace std;

int main(){
    int a[] = {2, 4, 6};
    int threshold = 15;
    int n = sizeof(a) / sizeof(a[0]);
    int start = 0, end = n-1;
    int count = 0;
    while(start <= end){
        if(a[start] * a[end]  <= threshold){
            count += 2*(end-start) + 1;
            start++;
        }
        else
            end--;
    }
    cout<<"Count is "<<count<<endl;
    return 0;
}