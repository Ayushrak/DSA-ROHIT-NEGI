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
Node* insert(Node* root,int target){
    if(!root)
    {
        Node *temp = new Node(target);
        return temp;
    }
    //left side
    if(target<root->data)
    {
        root->left=insert(root->left,target);
    }
    //right side
    else
    {
        root->right=insert(root->right,target);
    }
    return root;
}

void inorder(Node* root){
    if(!root)
    return;

    //left side
    inorder(root->left);
    cout<<root->data<<" ";
    //right side
    inorder(root->right);
}

bool Search(Node* root,int target){
    if(!root)
    return false;

    if(root->data==target)
    return true;
    //left side
    if(target<root->data){
    return Search(root->left,target);
    }
    //right side
    else 
    return Search(root->right,target);
}

Node *deleteNode(Node *root, int target){
    if(!root)
    return NULL;
    
    if(root->data>target){
    root->left=deleteNode(root->left,target);
    return root;
    }
    if(root->data<target){
    root->right=deleteNode(root->right,target);
    return root;
    } 
    else{
        //leaf node
        if(!root->left && !root->right)
        {
            delete root;
            return NULL;
        }
        //1 child exist
        if(!root->left){ //right child exist
            Node *temp = root->right;
            delete root;
            return temp;
        }
        if(!root->right){ //left child exist
            Node *temp = root->left;
            delete root;
            return temp;
        }

        //2 child exist
        else{
            //find the greatest value from left;
            Node *child = root->left;
            Node *parent = root;

            while(child->right){
                parent=child;
                child=child->right;
            }

            if(root!=parent){
                parent->right = child->left;
                child->left = root->left;
                child->right = root->right;
                return child;
            }
            else{
               child->right = root->right;
               delete root;
               return child;
            }
        }
    }


}


int main(){
    int arr[] ={3,7,4,1,6,8};
    Node *root = NULL;
    for(int i=0;i<6;i++)
    {
        root=insert(root,arr[i]);
    }
    //Search
    cout<<Search(root,4)<<endl;

    //Traverse
    inorder(root); //1 3 4 6 7 8

    //Delete
    
    return 0;
}