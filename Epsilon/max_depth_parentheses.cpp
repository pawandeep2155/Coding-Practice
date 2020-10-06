#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <stack>
#include <limits.h>

using namespace std;

int main(){
    string s = "{}{}{{}}";

    stack<char>st;
    int max_depth = 0;
    int index = 0;
    while(index < s.length()){
        if(s[index]=='{'){
            st.push('{');
            max_depth = max(max_depth, (int)st.size());
        }
        else
            st.pop();
        index++;
    }
    cout<<"Max depth "<<max_depth<<endl;
    return 0;
}
