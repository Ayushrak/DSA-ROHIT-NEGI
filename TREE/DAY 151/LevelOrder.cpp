#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class Node{
    public:
    int data;
    Node *left;
    Node *right;
    Node(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
};

class Solution
{
    public:
    //Function to return the level order traversal of a tree.
    vector<int> levelOrder(Node* root)
    {
      //Your code here
      vector<int> ans;
      queue<Node*> q;
      q.push(root);
      while(!q.empty())
      {
    
              Node* root=q.front();
              q.pop();
              ans.push_back(root->data);
              if(root->left!=NULL)
              q.push(root->left);
              if(root->right!=NULL)
              q.push(root->right);

      }   
      return ans;
    }
};
