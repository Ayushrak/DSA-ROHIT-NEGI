#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *left;
    Node *right;
    Node(int d){
        data = d;
        left = right = NULL;
    }
};
class Solution
{
    public:
    void flatten(Node *root)
    {
        //code here
        while(root)
        {
            //left part doesn't exist
            if(!root->left)
            root = root->right;
            
            //exist
            else{
                Node *curr = root->left;
                while(curr->right)
                curr = curr->right;
                
                curr->right = root->right;
                root->right = root->left;
                root->left =NULL;
                root = root->right;
            }
        }
    }
};