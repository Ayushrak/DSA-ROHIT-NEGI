#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *left;
    Node *right;
    Node(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
};

Node  *BinaryTree()
{
    int x;
    cin>>x;
    if(x==-1)
    return NULL;

    Node *temp = new Node(x);
    //left side create
    cout<<"Enter the left child of "<<x<<":";
    temp->left = BinaryTree();
    //right side create
    cout<<"Enter the right child of "<<x<<":";
    temp->right = BinaryTree();
    return temp;
}

void PreOrder(Node *root){
    if(root==NULL)
    return;

    //Node
    cout<<root->data<<" ";
    //left side
    PreOrder(root->left);
    //right side
    PreOrder(root->right);
}

void InOrder(Node *root){
    if(root==NULL)
    return;

    //left side
    InOrder(root->left);
    //Node
    cout<<root->data<<" ";
    //right side
    InOrder(root->right);
}

void PostOrder(Node *root){
    if(root==NULL)
    return;

    //left side
    PostOrder(root->left);
    //right side
    PostOrder(root->right);
    //Node
    cout<<root->data<<" ";
}

int main(){
    cout<<"Enter root node:";
    Node *root = BinaryTree();

    cout<<"PreOrder : ";
    PreOrder(root);
    cout<<endl;
    cout<<"InOrder : ";
    InOrder(root);
    cout<<endl;
    cout<<"PostOrder : ";
    PostOrder(root);

}