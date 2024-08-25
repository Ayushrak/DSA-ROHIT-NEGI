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
    //LEFT;
    //Node;
    //RIGHT;
    vector<int> inOrder(Node* root)
        {
        vector<int>ans;
        while(root){
            
        //Left part  doesn't exists
        if(!root->left){
            ans.push_back(root->data);
            root = root->right;
        }
        
        //left part exist
        else{
            Node *curr = root->left;
            
            while(curr->right&&curr->right!=root)
            curr=curr->right;
            
            //Left subtree Not Traverse
            if(curr->right==NULL)
            {
                curr->right = root;
                root = root->left;
            }
            //left part traverse
            //already traverse
            else{
                curr->right = NULL;
                ans.push_back(root->data);
                root = root->right;
            }
        }
        }
        return ans;
    }
};