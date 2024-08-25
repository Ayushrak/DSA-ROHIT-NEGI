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

class Solution
{
    public:
    //Function to check if two trees are identical.
    bool isIdentical(Node *r1, Node *r2)
    {
        //Your Code here
        // !r1 = r1==NULL;
        if(!r1&&!r2)
        return 1;
        
        
        if((!r1&&r2||r1&&!r2))
        return 0;
        
        if(r1->data!=r2->data)
        return 0;
        
        return isIdentical(r1->left,r2->left)&&isIdentical(r1->right,r2->right);
    }
};