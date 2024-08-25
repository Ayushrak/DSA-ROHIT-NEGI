#include<iostream>
using namespace std;

class Node{
    public:
    int key;
    Node *left;
    Node *right;
    Node(int k){
        key=k;
        left=NULL;
        right=NULL;
    }
};


//1st method
void Total(Node *root,long int &sum){
    if(root==NULL)
    return;
    
    sum+=root->key;
    Total(root->left,sum);
    Total(root->right,sum);
}


long int sumBT(Node* root)
{
    // Code here
    long int sum = 0;
    Total(root,sum);
    return sum;
    
}

//2n d method
long int sumBT(Node* root)
{
    // Code here
    if(root==NULL)
    return 0;
    
    return (root->key + sumBT(root->left) + sumBT(root->right));
}