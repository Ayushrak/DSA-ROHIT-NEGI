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

class Solution{
    public:
    //Function to check whether a binary tree is balanced or not.
    
    int height(Node *root,bool &valid){
        if(!root)
        return 0;
        
        int l = height(root->left,valid);
        int r = height(root->right,valid);
        
        if(abs(l-r)>1)
        valid = 0;
        
        return 1 + max(l,r);
    }
    
    bool isBalanced(Node *root)
    {
        //  Your Code here
        bool valid = 1;
        height(root,valid);
        return valid;
    }
};