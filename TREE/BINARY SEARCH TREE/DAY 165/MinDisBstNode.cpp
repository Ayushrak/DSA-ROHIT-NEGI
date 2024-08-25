#include<iostream>
#include<vector>
using namespace std;
#define INT_MIN 100;
#define INT_MAX -100;

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

//1st method
class Solution {
public:
    void inorder(Node *root,vector<int>&v){
        if(root==NULL)
        return;

        inorder(root->left,v);
        v.push_back(root->data);
        inorder(root->right,v);
    }

    int minDiffInBST(Node* root) {
        vector<int>v;
        inorder(root,v);
        int mini;
        int prev = INT_MAX;
        for(int i=0;i<v.size()-1;i++){
            mini = min(mini,v[i+1]-v[i]);
        }
        return mini;
    }
};

//2nd
class Solution {
public:
    void minDist(Node *root ,int &prev,int &ans){
        if(!root)
        return;

        minDist(root->left,prev,ans);
        if(prev!= INT_MIN)
        ans = min(ans,root->data-prev);
        prev = root->data;
        minDist(root->right,prev,ans);
    }

    int minDiffInBST(Node* root) {
        int prev = INT_MIN;
        int ans = INT_MAX;

        minDist(root,prev,ans);
        return ans;
    }
};