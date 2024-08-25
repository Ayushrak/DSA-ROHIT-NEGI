#include<iostream>
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

void KSum(Node *root,int &sum,int &k){
    if(!root)
    return;
    
    //Inorder Trraversal
    KSum(root->left,sum,k);
    k--;
    if(k>=0)
    sum +=root->data;
    if(k<=0)
    return;
    KSum(root->right,sum,k);
}


int sum(Node* root, int k) 
{ 
  
    // Your code here
    int sum = 0;
    KSum(root,sum,k);
    return sum;
}