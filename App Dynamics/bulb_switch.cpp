#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <limits.h>

using namespace std;

void print_array(int a[], int n){
    for(int i = 0; i < n; i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

void bulb_switch(int a[], int numbers[], int n, int num){
    map<int,int> m;
    for(int i = 0; i < num; i++){
        for(int j = 2; j <= numbers[i]; j++){
            if(numbers[i] % j == 0){
                bool is_prime = true;
                for(int k = 2; k <= j/2; k++){
                    if(j%k == 0){
                        is_prime = false;
                        break;
                    }
                }
                if(is_prime){
                    m[j]+=1;
                }
            }
        }
    }
    map<int, int>::iterator itr;
    for(int i = 1; i <= n; i++){
        int count = 0;
        for(itr = m.begin(); itr!=m.end(); itr++){
            if(i%(itr->first) == 0)
                count += itr->second;
        }
        if(count % 2 == 1)
            a[i-1] = 1 - a[i-1];
    }
}

int main(){
    int a[] = {0, 1, 1, 0, 1, 1, 0, 1, 1, 1};
    int n = sizeof(a) / sizeof(a[0]);
    int numbers[] = {3, 8, 6};
    int num = sizeof(numbers) / sizeof(numbers[0]);
    bulb_switch(a, numbers, n, num);
    print_array(a, n);
}