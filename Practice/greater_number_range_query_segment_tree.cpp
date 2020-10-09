#include <iostream>
#include <string>
#include <vector>
#include <limits.h>
#include <cmath> 

using namespace std;

void print_array(vector<int> &v){
    for(int i = 0; i < v.size(); i++)
        cout<<v[i]<<" ";
    cout<<endl;
}

int construct_tree(vector<int> &segment_tree, int index, int left, int right, int a[]){
    if(left == right){
        segment_tree[index] = a[left];
        return segment_tree[index];
    }
    int mid = (left + right) / 2;
    segment_tree[index] = max(construct_tree(segment_tree, 2*index+1, left, mid, a),
                             construct_tree(segment_tree, 2*index+2, mid+1, right, a));
    return segment_tree[index];
}

int greater_count(vector<int> &segment_tree, int index, int left, int right, int query_val, int query_m, int a[]){
    if(query_val > segment_tree[index])
        return 0;
    segment_tree[index]--;
    if(left == right){
        a[left]--;
        return 1;
    }
    int mid = (left + right) / 2;
    return greater_count(segment_tree, 2*index+1, left, mid, query_val, query_m, a) + 
            greater_count(segment_tree, 2*index+2, mid+1, right, query_val, query_m, a);
}

int main(){
    int a[] = {2, 4, 1, 3, 5, 6, 3};
    int n = sizeof(a) / sizeof(a[0]);
    sort(a, a+n);
    int x = (int)(ceil(log2(n)));
    int tree_size = 2 * pow(2, x) - 1;
    vector<int> segment_tree(tree_size, INT_MIN);
    int index = 0, left = 0, right = n - 1;
    // Construct Segment Tree
    construct_tree(segment_tree, index, left, right, a);

    int query_val = 4, query_m = 1;
    // Query Segment Tree
    cout<<"Greater count "<<greater_count(segment_tree, index, left, right, query_val, query_m, a)<<endl;
    return 0;
}