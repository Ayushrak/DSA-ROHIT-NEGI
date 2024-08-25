#include<iostream>
using namespace std;


class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int d){
        data=d;
        left=right=NULL;
    }
};


class Solution {
  public:
    // Function to convert a binary tree into its mirror tree.
    void mirror(Node* root) {
        // code here
        if(!root)
        return;
        
        Node *temp = root->right;
        root->right = root->left;
        root->left  = temp;
        
        //left;
        mirror(root->left);
        //right
        mirror(root->right);
    }
};