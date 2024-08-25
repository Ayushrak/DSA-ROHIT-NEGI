#include<iostream>
#include<stack>
#include<vector>
#include<queue>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int d){
        data=d;
        left=right=NULL;
    }
};

class Solution{
    public:
    vector<int> preOrder(Node* root)
    {
        //code here
        stack<Node*>s1;
        s1.push(root);
        vector<int>ans;
        while(!s1.empty()){
            Node * temp = s1.top();
            s1.pop();
            ans.push_back(temp->data);
            if(temp->right)
            s1.push(temp->right);
            if(temp->left)
            s1.push(temp->left);
        }
        return ans;
    }
};