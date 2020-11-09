#include <iostream>
#include <string>
#include <vector>
#include <limits.h>

using namespace std;

class BIT{
    public:
    int size;
    vector<int> v;
    BIT(int s){
        int size = s;
        v.resize(s, 0);
    }
    void update(int i, int delta){
        while(i < size){
            v[i]+= delta;
            i += i & (-i);
        }
    }
    int sum(int i){
        int s = 0;
        while(i > 0){
            s += v[i];
            i -= i & (-i);
        }
        return s;
    }
};


int main(){
    int a[] = {10, 6, 2, 3, 7, 1, 2};
    int n = sizeof(a) / sizeof(a[0]);
    int val = 1e5;
    BIT * t = new BIT(val+1);
    long result = 0;
    for(int i = 0; i < n; i++){
        t->update(a[i], 1);
        int large = i + 1 - t->sum(a[i]);
        int small = t->sum(a[i]-1);
        cout<<small<<" "<<large<<endl;
        result += 2 * 1ll * min(large, small) + 1;
    }

    cout<<"Minimum operations "<<result;
    return 0;
}