#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <limits.h>
#include <stack>

using namespace std;

int main(){
    stack<char> s;
    string t = "|**|*|*";
    int queryx = 1, queryy = 5;
    int count = 0;
    for(int i = queryx-1; i < queryy; i++){
        if(t[i]=='*' and !s.empty()){
            s.push('*');
        }
        if(t[i]=='|'){
            if(s.empty()){
                s.push('|');
            }
            else{
                while(s.top() == '*'){
                    count++;
                    s.pop();
                }
            }
        }
    }
    cout<<"Stars between bars "<<count<<endl;
    return 0;
}