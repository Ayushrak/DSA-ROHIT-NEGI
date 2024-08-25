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

class Solution{
    public:
    
    int find(int in[],int target,int start,int end){
        for(int i=start;i<=end;i++){
            if(in[i]==target)
            return i;
        }
        return -1;
    }
    Node* Tree(int in[],int pre[],int Instart,int Inend,int index){
     
        if(Instart>Inend)
        return NULL;
        
        Node *root = new Node(pre[index]);
        
        int pos = find(in,pre[index],Instart,Inend);
        
        root->left = Tree(in,pre,Instart,pos-1,index+1);
        root->right = Tree(in,pre,pos+1,Inend,index+(pos-Instart)+1);
        return root;
    }
    
    
    Node* buildTree(int in[],int pre[], int n)
    {
        // Code here
        return  Tree(in,pre,0,n-1,0);
    }
};