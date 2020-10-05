#include <iostream>
#include <string>
#include <vector>
#include <limits.h>
#include <math.h>

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

int travelling_salesman(Node* node){
    if(node == NULL)
        return 0;
    int max_sales = 0;
    int left_sale = 0, right_sale = 0;
    if(node->left)
        left_sale = travelling_salesman(node->left->left) + travelling_salesman(node->left->right);
    if(node->right)
        right_sale = travelling_salesman(node->right->left) + travelling_salesman(node->right->right);
    
    max_sales = max(node->val + left_sale + right_sale, travelling_salesman(node->left) + travelling_salesman(node->right));

    return max_sales;
}

int main(){
    Node* root = new Node(7);
    Node* node1 = new Node(6);
    Node* node2 = new Node(9);
    Node* node3 = new Node(8);
    Node* node4 = new Node(2);
    Node* node5 = new Node(3);
    Node* node6 = new Node(1);
    Node* node7 = new Node(1);
    Node* node8 = new Node(3);
    Node* node9 = new Node(1);

    root->left = node1;
    root->right = node2;
    node1->left = node3;
    node1->right = node4;
    node2->left = node5;
    node2->right = node6;   
    node3->left = node7;
    node3->right = node8;
    node6->right = node9;

    int max_profit = travelling_salesman(root);
    cout<<"Max Profit "<<max_profit;
    return 0;
}