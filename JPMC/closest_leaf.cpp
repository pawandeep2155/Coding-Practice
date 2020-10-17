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

void preorder(Node* root, char node, vector<Node*> ancestor_nodes, vector<Node*> &ancestor){
    if(root->node == node){
        ancestor = ancestor_nodes;
        ancestor.push_back(root);
        return;
    }
    ancestor_nodes.push_back(root);
    if(root->left)
        preorder(root->left, node, ancestor_nodes, ancestor);
    if(root->right)
        preorder(root->right, node, ancestor_nodes, ancestor);
}

int closest_leaf(Node* root, int height=0){
    if(root->left == NULL and root->right == NULL)
        return height;
    int min_height;
    if(root ->left)
        min_height = closest_leaf(root->left, height+1);
    if(root->right)
        min_height = min(min_height, closest_leaf(root->right, height+1));
    return min_height;
}

int find_closest(Node* root, char node){
    vector<Node*> ancestor;
    preorder(root, node, ancestor, ancestor);
    int closest = INT_MAX;
    for(int i = 0; i < ancestor.size(); i++){
        int distance_to_node = ancestor.size() - (i+1);
        closest = min(closest, distance_to_node + closest_leaf(ancestor[i]));

    }
    return closest;
}

int main(){

    struct Node *root        = new Node('A'); 
    root->left               = new Node('B'); 
    root->right              = new Node('C'); 
    root->right->left        = new Node('E'); 
    root->right->right       = new Node('F'); 
    root->right->left->left  = new Node('G'); 
    root->right->left->left->left  = new Node('I'); 
    root->right->left->left->right = new Node('J'); 
    root->right->right->right      = new Node('H'); 
    root->right->right->right->left = new Node('K');

    char node = 'I';
    int closest = find_closest(root, node);
    cout<<"Closest Leaf Node to "<<node<<" is at distance "<<closest<<endl;;
    return 0;
}