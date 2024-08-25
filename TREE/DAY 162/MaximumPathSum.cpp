#include<iostream>
#include<vector>
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
    
    int PathSum(Node *root,int &sum){
        if(!root)
        return 0;
        
        //leaf node
        if(!root->left&&!root->right)
        return root->data;
        
        int left = PathSum(root->left,sum);
        int right = PathSum(root->right,sum);
        
        //left and right both exists
        if(root->left&&root->right){
            sum = max(sum,root->data+left+right);
            return root->data + max(left,right);
        }
        //only left exits
        if(root->left){
            return root->data+left;
        }
        //only right exists
        if(root->right){
            return root->data+right;
        }
    }
    
    int maxPathSum(Node* root)
    {
        // code here
        int sum = INT_MIN;
       int val = PathSum(root,sum);
       
       if(root->left&&root->right)
       return sum;
       
       return max(sum,val);
    }
};