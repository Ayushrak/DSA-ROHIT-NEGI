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
    vector<int> postOrder(Node* root) {
        // code hereclass Solution{
   
        //code here
        stack<Node*>s1;
        s1.push(root);
        vector<int>ans;
        while(!s1.empty()){
            Node * temp = s1.top();
            s1.pop();
            ans.push_back(temp->data);
            if(temp->left)
            s1.push(temp->left);
              if(temp->right)
            s1.push(temp->right);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};