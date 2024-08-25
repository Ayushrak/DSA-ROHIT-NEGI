#include<iostream>
using namespace std;


class Node{
    public:
    int data;
    Node *left;
    Node *right;
    Node(int d){
        data=d;
        left=NULL;
        right=NULL;
    }
};


//1st method
void Total(Node *root,int &count){
    
    if(root==NULL)
    return;
    
    count++;
    Total(root->left,count);
    Total(root->right,count);
}
/* Computes the number of nodes in a tree. */
int getSize(Node* node)
{
   // Your code here
   int count =0;
   Total(node,count);
   return count;
}


//2nd method

int getSize(Node* root)
{
    if(root==NULL)
    return 0;
    
   return(1+ getSize(root->left) + getSize(root->right));
   
}