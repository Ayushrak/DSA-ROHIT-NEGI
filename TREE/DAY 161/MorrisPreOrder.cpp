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


class Solution{
    //ROOT
    //LEFT 
    //RIGHT
    public:
    vector<int> preOrder(Node* root)
    {
       vector<int>ans;
        while(root){
            
            //if left part  doesn't exist;
            if(!root->left){
            ans.push_back(root->data);
            root = root->right;
            }
            
            //left part exists;
            
            else{
                Node *curr = root->left;
                while(curr->right&&curr->right!=root)
                curr=curr->right;
                
                //left subtree NOT traverse
                if(curr->right==NULL)
                {
                    ans.push_back(root->data);
                    curr->right=root;
                    root =root->left;
                }
                //already traverse
                else{
                    curr->right=NULL;
                    root = root->right;
                }
            }
        }
        return ans;
    }
};