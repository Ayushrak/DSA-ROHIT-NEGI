#include<iostream>
#include<vector>
using namespace std;

class TNode{
    public:
    int data;
    TNode *left;
    TNode *right;
    TNode(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
};

class LNode{
    public:
    int data;
    LNode *next;
    LNode(int d){
        data = d;
        next = NULL;
    }
};

class Solution{
  public:
    TNode* BuildBST(vector<int>&Tree,int start,int end){
        if(start>end)
        return NULL;
        
        int mid = start + (end-start+1)/2;
        TNode *root = new TNode(Tree[mid]);
        root->left = BuildBST(Tree,start,mid-1);
        root->right = BuildBST(Tree,mid+1,end);
        return root;
    }
  
    TNode* sortedListToBST(LNode *head) {
        //code here
        vector<int>Tree;
        while(head){
            Tree.push_back(head->data);
            head = head->next;
        }
        return BuildBST(Tree,0,Tree.size()-1);
    }
};