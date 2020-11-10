#include <iostream>
#include <string>
#include <vector>
#include <limits.h>
#include <set>
#include <algorithm>

using namespace std;

/*
    Given array of elements and sum k, find subsequence in the array whose sum is closest to k
*/

int main(){
    int arr[] = {19,23,41,5,40,44};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k= 44;
    int opt=0;
    set<int> sums;
    sums.insert(opt);
    for(int i = 0; i < n; i++){
        int input = arr[i];
        set<int> newSums;
        set<int>::iterator itr;
        for (itr = sums.begin();  itr != sums.end(); ++itr){
            int newSum = *itr + input;
            // ignore too big sums
            if (newSum <= k) {
                newSums.insert(newSum);
                // update optimum                       
                if (newSum > opt) {
                    opt = newSum;
                }            
            }
        }
        for(itr = newSums.begin(); itr != newSums.end(); ++itr){
            sums.insert(*itr);
        }
    }
    cout<<"closest sum "<<opt<<endl;
    return 0;
}