#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    int height;
    Node(int d){
        data = d;
        left = NULL;
        right = NULL;
        height = 1;
    }
};

int height(Node* root){
        if(!root)
        return 0;
        return root->height;
    }

     int getBalance(Node* root){
        if(!root)
        return 0;
        return height(root->left)-height(root->right);
    }

    Node* rightRotation(Node* root){
        Node* child = root->left;
        Node* childRight = child->right;

        child->right = root;
        root->left = childRight;
        //update the height
        root->height = 1+ max(height(root->left),height(root->right));
        child->height = 1+max(height(child->left),height(child->right));
        return child;
    }

    Node *leftRotation(Node *root){
        Node* child = root->right;
        Node* childLeft = child->left;
        child->left = root;
        root->right = childLeft;
        root->height = 1+max(height(root->left),height(root->right));
        child->height = 1+max(height(child->left),height(child->right));
        return child;
    }


Node* deleteNode(Node* root, int key)
{
    //add code here,
    if(!root)
    return NULL;
    
    //left side
    if(key<root->data)
    root->left = deleteNode(root->left,key);
    //right side
    else if(key>root->data)
    root->right = deleteNode(root->right,key);
    else{
        //Leaf Node exits
        if(!root->left&&!root->right){
        delete root;
        return NULL;
        }
        
        //Only one child exists 
       else if(root->left&&!root->right){    //left child
        Node *temp = root->left;
        delete root;
        return temp;
       }
       
       else if(!root->left&&root->right){
            Node *temp = root->right;
        delete root;
        return temp;
       }
       
        //both child exists
        else{
            //Right side smallest element 
            Node *curr = root->right;
            while(curr->left){
                curr=curr->left;
            }
            root->data = curr->data;
           root->right = deleteNode(root->right,curr->data);
        }
    }
    
    //Update the height
    root->height = 1 + max(height(root->left),height(root->right));
    
    //check the balance;
    int balance = getBalance(root);
    if(balance>1){
        //LL
        if(getBalance(root->left)>=0)
        return rightRotation(root);
        
        //LR
        else{
            root->left = leftRotation(root->left);
            return rightRotation(root);
        }
        
    }
    else if(balance<-1){
        //RR
        if(getBalance(root->right)<=0)
        return leftRotation(root);
        //RL
        else{
            root->right = rightRotation(root->right);
            return leftRotation(root);
        }
    }
    else 
    return root;
}