#include <iostream>
#include <string>
#include <vector>
#include <limits.h>
#include <math.h>
#include <algorithm>

using namespace std;

int main(){
    int a[] = {2,4,5,5,6,6,6,6,6,9,10,10000};
    int n = sizeof(a) / sizeof(a[0]);
    int chocolate = 6;
    int lower = lower_bound(a, a+n, chocolate) - a;
    int upper = upper_bound(a, a+n, chocolate) - a;
    int num_chocolates = upper - lower;
    cout<<"Num of chocolates "<<num_chocolates<<endl;
    return 0;
}