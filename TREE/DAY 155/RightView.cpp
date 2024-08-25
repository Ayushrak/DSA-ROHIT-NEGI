#include<iostream>
#include<vector>
#include<queue>
using namespace std;


class Node{
    public:
    int data;
    Node *left;
    Node *right;
    Node(int data){
        data = data;
        left=right=NULL;
    }
};

class Solution
{
    public:
    //Function to return list containing elements of right view of binary tree.
    vector<int> rightView(Node *root)
    {
       // Your Code here
       vector<int>ans;
       queue<Node*>q;
       if(!root)
       return ans;
       q.push(root);
       
       
       while(!q.empty()){
         ans.push_back(q.front()->data);
         int n = q.size();
         
         
         while(n--){
           Node *temp = q.front();
           q.pop();
            
           
            //right
            if(temp->right)
            q.push(temp->right);
            
             if(temp->left)
            q.push(temp->left);
       }
       }
       return ans;
    }
};


class Solution
{
    public:
    //Function to return list containing elements of right view of binary tree.
    
    void Rview(Node *root,int level,vector<int>&ans){
        if(!root)
        return;
        
        if(level==ans.size())
        ans.push_back(root->data);
        Rview(root->right,level+1,ans);
        Rview(root->left,level+1,ans);
    }
    vector<int> rightView(Node *root)
    {
       // Your Code here
       vector<int>ans;
       if(!root);
       return ans;
       
       Rview(root,0,ans);
       return ans;
    }
};