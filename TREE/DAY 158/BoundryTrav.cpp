#include<iostream>
#include<vector>
using namespace std;

class Node {
    public:
    int data;
    Node *left;
    Node *right;
    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

class Solution {
public:

    void LeftSub(Node *root,vector<int>&ans){
        //Base case
        if(!root || (!root->left&&!root->right))
        return;
        
        ans.push_back(root->data);
        if(root->left)
        LeftSub(root->left,ans);
        else
        LeftSub(root->right,ans);
    }
    
    void Leaf(Node *root, vector<int>&ans){
        if(!root)
        return;
        
        //leaf node
        if(!root->left&!root->right){
            ans.push_back(root->data);
            return;
        }
        //left part
        Leaf(root->left,ans);
        Leaf(root->right,ans);
    }
    
    
    void RightSub(Node *root,vector<int>&ans){
         if(!root || (!root->left&&!root->right))
        return;
        
        
        
        if(root->right)
        RightSub(root->right,ans);
        else
        RightSub(root->left,ans);
        //root
        ans.push_back(root->data);
    }
    
    
    vector <int> boundary(Node *root)
    {
        //Your code here
        vector<int>ans;
        //Root element;
        ans.push_back(root->data);
        //left Boundary element ko daal do, except leaf;
        LeftSub(root->left,ans);
        //saare leaf node insert kar do
        if(root->left || root->right)
        Leaf(root,ans);
        //right Boundry usko reverse order mein daal do except leaf node
        RightSub(root->right,ans);
        
        return ans;
        
    }
};