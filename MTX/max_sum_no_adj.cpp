#include <iostream>
#include <string>
#include <vector>
#include <limits.h>

using namespace std;

int main(){
    int a[] = {1, 2, 3};
    int n = sizeof(a) / sizeof(a[0]);
    vector<int> T(n, 0);
    T[0] =a[0];
    T[1] = max(a[0], a[1]);
    int max_sum = INT_MIN;
    for(int i = 2; i < n; i++){
        T[i] = max(T[i-1], T[i-2] + a[i]);
        max_sum = max(max_sum, T[i]);
    }
    cout<<"max sum is "<<max_sum<<endl;
    return 0;
}
