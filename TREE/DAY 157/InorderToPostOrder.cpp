#include<iostream>
#include<vector>
#include<queue>
using namespace std;


class Node{
    public:
    int data;
    Node *left;
    Node *right;
    Node(int data){
        data = data;
        left=right=NULL;
    }
};


int find(int in[],int target,int start,int end){
    for(int i=start;i<=end;i++){
        if(in[i]==target)
        return i;
    }
    return -1;
}

Node *Tree(int in[],int post[],int Instart,int Inend,int index){
    
    if(Instart>Inend)
    return NULL;
    
    Node *root = new  Node(post[index]);
    int pos = find(in,post[index],Instart,Inend);
    
    //right
    root->right = Tree(in,post,pos+1,Inend,index-1);
    //left
    root->left = Tree(in ,post,Instart,pos-1,index-(Inend-pos)-1);
    return root;
}
Node *buildTree(int in[], int post[], int n) {
    // Your code here
   return  Tree(in,post,0,n-1,n-1);
}