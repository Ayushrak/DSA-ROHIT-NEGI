#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int d){
        data=d;
        left=NULL;
        right=NULL;
    }
};

class Solution{
    public:
    //Function to find the height of a binary tree.
    int height(struct Node* root){
        // code here
        if(root==NULL)
        return 0;
        
        return 1 + max(height(root->left),height(root->right));
    }
};