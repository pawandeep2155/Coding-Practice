#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <limits.h>

using namespace std;

int gcd(int a, int b){
    if(a == 0)
        return b;
    if(b == 0)
        return a;
    if(a == b)
        return a;
    if(a > b)
        return gcd(a-b, b);
    return gcd(a, b-a);
}

int main(){
    int a[] = {2, 3, 5, 4, 6};
    int n = sizeof(a) / sizeof(a[0]);
    int count = 0;
    for(int i = 0; i < n; i++){
        int j;
        for(j = n-1; j >= i; j--){
            if(gcd(a[i], a[j]) > 1)
                break;
        }
        count++;
        i = j;
    }
    cout<<"Number of good sub array "<<count<<endl;
    return 0;
}