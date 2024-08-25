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

class Solution
{
    public:
    //Function to check whether a Binary Tree is BST or not.
    void inorder(Node *root,vector<int>&ans){
        if(!root)
        return;
        
        inorder(root->left,ans);
        ans.push_back(root->data);
        inorder(root->right,ans);
    }
    
    bool isBST(Node* root) 
    {
        // Your code here
        vector<int>ans;
        inorder(root,ans);
        
        for(int i=1;i<ans.size();i++){
            if(ans[i]<=ans[i-1])
            return 0;
        } 
            return 1;
    }
};


//optimized solution
class Solution
{
    public:
    //Function to check whether a Binary Tree is BST or not.
    bool BST(Node *root,int &prev){
        if(!root)
        return 1;
        
        if(!BST(root->left,prev)){
            return 0;
        }
        
        if(root->data<=prev){
            return 0;
        }
        
        prev = root->data;
        return BST(root->right,prev);
    }
    bool isBST(Node* root) 
    {
        // Your code here
        int prev = INT_MIN;
      return   BST(root,prev);
        
    }
};