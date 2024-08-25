#include<iostream>
#include<vector>
#include<stack>
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
    vector<int> postOrder(Node* root) {
        // code here
        stack<int>s;
        while(root){
        //right part doesn't exists
        if(!root->right){
           s.push(root->data);
            root = root->left;
        }
        //right  part exists
        else{
            Node *prev = root->right;
            
            while(prev->left && prev->left!=root){
                prev = prev->left;
            }
            
            //right subtree not traverse
            if(!prev->left){
                prev->left = root;
                s.push(root->data);
                root = root->right;
            }
            
            //right subtree traverse
            else{
                root = root->left;
                prev->left = NULL;
            }
        }
    }
      vector<int>ans;
      while(!s.empty()){
          ans.push_back(s.top());
          s.pop();
      }
      return ans;
    }
};
