/*
Given is an array of size 2*N, we have to do N operations on that array, 
each array operation is removal of any 2 array elements, 
the score of each operation is equal to the GCD of the two chosen numbers
 multiplied by the operation number. We have to maximise this score. 
 For example N=2, arr={3,4,9,5};
*/
#include <iostream>
#include <string>
#include <vector>
#include <limits.h>

using namespace std;

int gcd(int a, int b)
{
    // Everything divides 0 
    if (a == 0)
       return b;
    if (b == 0)
       return a;
  
    // base case
    if (a == b)
        return a;
  
    // a is greater
    if (a > b)
        return gcd(a-b, b);
    return gcd(a, b-a);
}

int main(){
    int a[] = {3, 4, 9, 5};
    int n = sizeof(a) / sizeof(a[0]);
    vector<int> v;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            v.push_back(gcd(a[i], a[j]));
        }
    }
    sort(v.begin(), v.end(), greater<int>());
    int soln = 0;
    int count = 1;
    for(int i = (n/2)-1; i >= 0; i--){
        soln += (count++) * v[i];
    }
    cout<<"Max score is "<<soln<<endl;
    return 0;
}