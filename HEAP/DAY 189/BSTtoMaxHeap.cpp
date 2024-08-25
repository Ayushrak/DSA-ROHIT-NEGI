#include<iostream>
#include<vector>
using namespace std;

class Solution{
  public:
  void inorder(Node *root,vector<int>&ans){
      if(!root)
      return;
      
      inorder(root->left,ans);
      ans.push_back(root->data);
      inorder(root->right,ans);
  }
  
  void postOrder(Node *root,vector<int>&ans,int &index){
      if(!root)
      return;
      //left
      postOrder(root->left,ans,index);
      //right
      postOrder(root->right,ans,index);
      //node
      root->data = ans[index];
      index++;
  }
    void convertToMaxHeapUtil(Node* root)
    {
        // Your code goes here
        //inorder traversal
        vector<int>ans;
        inorder(root,ans);
        //postorder travers
        int index = 0;
        postOrder(root,ans,index);
    }    
};