#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <limits.h>

using namespace std;

int minSize(int arr[], int n, int k){
    int p = n-1,q = n-1,count = 0,l,s=0;
    if (q <= 1) 
        return (q+1);
    for (int i=q; i>=0; i--){
        if ((arr[i-1] == arr[i] - k) && (arr[i-2] == arr[i] - 2*k)){
            count += 3;
            p = p-2;
            l = p;
            for (int z = i-2; z <= l; z++)
                arr[z] = arr[z+3];
        }
    }
    s = n-count;
    return s;
}

int main()

{

    int arr[] = {1, 2, 3, 10};
    int N = sizeof(arr) / sizeof(arr[0]);
    int k = 1,res;

    res = minSize(arr, N, k);
    cout<<"Min size array "<<res<<endl;
    return 0;
}
