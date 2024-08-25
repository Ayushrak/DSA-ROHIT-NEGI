 #include<iostream>
 #include<queue>
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

 //1st method
  void Total(Node *root,int &count)
   {
       if(root==NULL)
       return;
       
       if(root->left==NULL&&root->right==NULL){
           count++;
           return;
       }
       
       Total(root->left,count);
       Total(root->right,count);
   }
   
   
int countLeaves(Node* root)
{
  // Your code here
  int count =0;
  Total(root,count);
  return count;
}

//2nd method
int countLeaves(Node* root)
{
  // Your code here

  if(root==NULL)
  return 0;
  
  //leaf node
  if(root->left==NULL && root->right==NULL)
  return 1;
  
  
  //Non Leaf code
  return (countLeaves(root->left)+countLeaves(root->right));
}