#include<iostream>
#include<vector>
using namespace std;


class Solution {
  public:
  int count(Node *root){
      
      if(!root)
      return 0;
      
     return 1 + count(root->left) + count(root->right);
  }
  
  bool CBT(Node *root,int index , int total_nodes){
      
      if(!root)
      return 1;
      
      if(index>=total_nodes)
      return 0;
      
     return  CBT(root->left,2*index+1,total_nodes) && CBT(root->right,2*index+2,total_nodes);
      
  }
  
      bool MaxHeap(Node *root){
         
          //One node exists atleast;
          if(root->left){
              
            if(root->data < root->left->data)
            return 0;
            
            if(!MaxHeap(root->left))
            return 0;
          }
          
           if(root->right){
              
            if(root->data < root->right->data)
            return 0;
            
            return MaxHeap(root->right);
          }
          
          return 1;
      }   
  
  bool isHeap(struct Node* tree) {
        // code here
        //Count nodes in the tree
        int num = count(tree);
        //CBT HAI YA NAHI
        if(!CBT(tree,0,num));
        return 0;
        //every parent>=child
        MaxHeap(tree);
    }