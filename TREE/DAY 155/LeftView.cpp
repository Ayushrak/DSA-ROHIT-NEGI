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
//method 1
vector<int> leftView(Node *root)
{
   // Your code here
   vector<int>ans;
    queue<Node*>q;
    if(!root)
    return ans;
    q.push(root);
   
    
    while(!q.empty()){
        ans.push_back(q.front()->data);
        int n = q.size();
        
        while(n--){
            Node *temp = q.front();
            q.pop();
            
            //left
            if(temp->left)
            q.push(temp->left);
            //right
            if(temp->right)
            q.push(temp->right);
        }
    }
    return ans;
};


//method 2 by rec

  void Lview(Node *root,int level,vector<int>&ans)
    {
        if(!root)
        return;
        
        if(level==ans.size())
        ans.push_back(root->data);
        Lview(root->left,level+1,ans);
         Lview(root->right,level+1,ans);
    }

vector<int> leftView(Node *root)
{
   // Your code here
   vector<int>ans;
   if(!root)
   return ans;
   
   Lview(root,0,ans);
   return ans;
}