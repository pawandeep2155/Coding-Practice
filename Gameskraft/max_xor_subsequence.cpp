#include <iostream>
#include <string>
#include <vector>
#include <limits.h>

using namespace std;

int main(){
    int a[] = {3, 1, 2, 1, 3, 1};
    int n = sizeof(a) / sizeof(a[0]);
    int k = 2;
    int start = -1, end, max_len = 0;
    for(int i = 1; i < n; i++){
        if((a[i] ^ a[i-1]) == k){
            if(start == -1){
                start = i-1, end = i, max_len = 2;
            }
            else if(end == i-1){
                end = i;
                max_len++;
            }
            else{
                start = i-1, end = i;
            }
        }
    }
    cout<<"Max length "<<max_len<<endl;
    return 0;
}