// NOT COMPLETED

#include <iostream>
#include <string>
#include <vector>
#include <limits.h>

using namespace std;


int main(){
    int a = 12, b = 102;
    vector<string> A, B;
    while(a){
        int rem = a %10;
        string s = to_string(rem);
        A.push_back(s);
        a = a / 10;
    }
    while(b){
        int rem = b % 10;
        string s = to_string(rem);
        B.push_back(s);
        b = b / 10;
    }
    return 0;
}