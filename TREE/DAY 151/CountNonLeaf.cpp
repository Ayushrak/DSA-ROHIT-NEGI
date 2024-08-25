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

class Solution {
  public:
    int countNonLeafNodes(Node* root) {
        // Code here
        if(root==NULL)
        return 0;
        
        
        if(root->left==NULL && root->right==NULL)
        return 0;
        
        return 1 + countNonLeafNodes(root->left) + countNonLeafNodes(root->right);
    }
};