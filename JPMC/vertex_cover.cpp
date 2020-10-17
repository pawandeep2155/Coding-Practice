#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <limits.h>

using namespace std;

struct Node{
    char node;
    Node* left, *right;
    Node(char x){
        node = x;
        left = NULL, right = NULL;
    }
};

int vertex_cover(Node* root, map<Node*, int> &m){
    if(root == NULL or (root->left == NULL and root->right == NULL))
        return 0;
    if(m.find(root) != m.end())
        return m[root];
    int inc = 1 + vertex_cover(root->left, m) + vertex_cover(root->right, m);
    int exc = 0;
    if(root->left)
        exc += 1 + vertex_cover(root->left->left, m) + vertex_cover(root->left->right, m);
    if(root->right)
        exc += 1 + vertex_cover(root->right->left, m) + vertex_cover(root->right->left, m);

    int vc = min(inc, exc);
    m[root] = vc;
    return vc;
}

int main(){

    struct Node *root         = new Node(20); 
    root->left                = new Node(8); 
    root->left->left          = new Node(4); 
    root->left->right         = new Node(12); 
    root->left->right->left   = new Node(10); 
    root->left->right->right  = new Node(14); 
    root->right               = new Node(22); 
    root->right->right        = new Node(25);     

    map<Node*, int> m;
    int vc = vertex_cover(root, m);
    cout<<"vertex cover of tree is "<<vc<<endl;
    return 0;
}