#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <limits.h>

using namespace std;

struct Node{
    int val;
    Node *left, *right;
    Node(){
        left = NULL;
        right = NULL;
    }
    Node(int node_value){
        val = node_value;
        left = NULL;
        right = NULL;        
    }
};

Node* construct_tree(int in_start, int in_end, int pre_start, int pre_end, int inorder[],
             int preorder[], int height, int &max_height, map<int, int> &m){
    if(pre_start > pre_end)
        return NULL;
    int node_val = preorder[pre_start];
    Node* node = new Node(node_val);
    if(pre_start == pre_end){
        max_height = max(height, max_height);
        return node;
    }
    int node_position = m[node_val];
    node->left = construct_tree(in_start, node_position-1, pre_start+1, pre_start+node_position-in_start, 
                        inorder, preorder, height+1, max_height, m);
    node->right = construct_tree(node_position+1, in_end, pre_start+node_position-in_start+1, pre_end, 
                        inorder, preorder, height+1, max_height, m);
    return node;
}

int main(){
    int inorder[] = {3,3,7,6,8,2,4,9};
    int preorder[] = {2,3,5,6,7,8,4,9};
    int n = sizeof(inorder) / sizeof(inorder[0]);

    map<int, int> m;
    for(int i = 0; i < n; i++)
        m[inorder[i]] = i;

    int height = 0;
    int max_height = 0;
    int in_start = 0, in_end = n-1, pre_start = 0, pre_end = n-1;
    construct_tree(in_start, in_end, pre_start, pre_end, inorder, preorder, height, max_height, m); 
    cout<<"Tree Height "<<max_height<<endl;
}