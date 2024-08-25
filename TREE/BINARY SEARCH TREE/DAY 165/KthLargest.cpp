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
    void KLargest(Node *root,int &ans,int &K){
        if(!root)
        return;
        
        //Right
        KLargest(root->right,ans,K);
        K--;
        if(K==0)
        ans = root->data;
        //Node
        if(K<=0)
        return;
        //left
        KLargest(root->left,ans,K);
    }
    
    int kthLargest(Node *root, int K)
    {
        int ans;
        KLargest(root,ans,K);
        return ans;
    }
};