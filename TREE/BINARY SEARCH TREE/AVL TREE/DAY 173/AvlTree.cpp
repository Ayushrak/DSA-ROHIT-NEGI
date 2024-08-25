#include<iostream>
using namespace std;

class Node{
    public:
    int data,height;
    Node* left;
    Node* right;
    Node(int val){
        data = val;
        height=1;
        left = NULL;
        right = NULL;
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




    Node* insert(Node *root,int key){
        //Doesn't exixts
        if(!root)
        return new Node(key);

        //exist hai
        if(key<root->data)
        root->left = insert(root->left,key);
        else if(key>root->data)
        root->right = insert(root->right,key);
        else
        return root; //duplicate element are not allowed


        //Update height
        root->height = 1+max(height(root->left),height(root->right));
   
        //Balance check
        int balance = getBalance(root);

        // left left case;
        if(balance>1&&key<root->left->data)
      return rightRotation(root);

       //right right case
      else if(balance<-1&&key>root->right->data)
       return leftRotation(root);
       //left right case
      else if(balance>1&&key>root->left->data)
      {
         root->left= leftRotation(root->left);
          return rightRotation(root);
      }

       //right left case
      else if(balance<-1&&key<root->right->data){
        root->right = rightRotation(root->right);
          return  leftRotation(root);
      }
    }
void inorder(Node *root){
    if(root==NULL)
    return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}


int main(){
    Node *root = NULL;

    root = insert(root,10);
    root=insert(root,20);
    root = insert(root,30);
    root=insert(root,40);
    root=insert(root,50);
    root=insert(root,25);
    root=insert(root,35);
    inorder(root);
    return 0;
}