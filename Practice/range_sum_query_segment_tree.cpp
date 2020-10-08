// Segment Tree is useful only if update queries are frequent otherwise
// prefix sum array will suffice

#include <iostream>
#include <string>
#include <vector>
#include <limits.h>
#include <cmath> 

using namespace std;

void print_array(vector<int> &v){
    for(int i = 0; i < v.size(); i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

int construct_tree(int a[], vector<int> &segment_tree, int index, int left, int right){
    if(left == right){
        segment_tree[index] = a[left];
        return segment_tree[index];
    }
    int mid = (left + right) / 2;
    segment_tree[index] = construct_tree(a, segment_tree, 2*index+1, left, mid)
                            + construct_tree(a, segment_tree, 2*index+2, mid+1, right);
    return segment_tree[index];
}

int find_sum(vector<int> &segment_tree, int index, int tree_left, int tree_right, int query_left, int query_right){
    if(query_left <= tree_left and tree_right <= query_right)   // Total Overlap
        return segment_tree[index];
    else if(tree_right < query_left or query_right < tree_left) // No Overlap
        return 0;
    else{
        int mid = (tree_left + tree_right) / 2;
        return find_sum(segment_tree, 2*index+1, tree_left, mid, query_left, query_right)
                +  find_sum(segment_tree, 2*index+2, mid+1, tree_right, query_left, query_right);
    }
}

void update_tree(vector<int> &segment_tree, int index, int tree_left, int tree_right, int update_index, int diff){
    if(tree_left > update_index or tree_right < update_index)
        return;
    segment_tree[index] += diff;
    if(tree_left != tree_right){
        int mid = (tree_left + tree_right) / 2;
        update_tree(segment_tree, 2*index+1, tree_left, mid, update_index, diff);
        update_tree(segment_tree, 2*index+2, mid+1, tree_right, update_index, diff);
    }
}

int main(){
    int a[] = {1, 2, 5, 6, 7, 9};
    int n = sizeof(a) / sizeof(a[0]);
    int x = (int)(ceil(log2(n)));
    int size = 2*(int)pow(2, x) - 1;
    vector<int> segment_tree(size, 0);
    int left = 0, right = n-1;
    int index = 0;
    // Construct Tree O(N)
    construct_tree(a, segment_tree, index, left, right);
    print_array(segment_tree);
    
    // Query: Find sum between left and right O(LogN)
    int query_left = 2, query_right = 4;
    cout<<find_sum(segment_tree, index, left, right, query_left, query_right)<<endl;

    // Query: Update index O(LogN)
    int update_index = 3, update_value = 14;
    int diff = update_value - a[update_index];
    a[update_index] = update_value;
    update_tree(segment_tree, index, left, right, update_index, diff);
    print_array(segment_tree);
    return 0;
}