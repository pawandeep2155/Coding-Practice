#include <iostream>
#include <string>
#include <vector>
#include <limits.h>

using namespace std;

void update(int bit[], int n, int index, int delta){
    for(int i = index; i <=n; i+= i&-i){
        bit[i]+= delta;
    }
}

int query(int bit[], int index){
    int sum = 0;
    for(int i = index; i > 0; i-= i&-i){
        sum += bit[i];
    }
    return sum;
}

int main(){
    int a[] = {2, 3, 1, 4, 5, 6};
    int n = sizeof(a) / sizeof(a[0]);
    int bit[100] = {0};
    for(int i = 1; i <= n; i++){
        update(bit, n, i, a[i-1]);
    }

    int small = query(bit, 5);
    cout<<"Query sum "<<query(bit, 5)<<endl;
    return 0;
}