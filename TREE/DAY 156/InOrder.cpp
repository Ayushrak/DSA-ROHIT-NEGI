#include<iostream>
#include<vector>
#include<stack>
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


class Solution {
public:
    vector<int> inOrder(Node* root)
    {
        //code here
        stack<Node*>s;
        stack<Node*>visited;
        s.push(root);
        visited.push(0);
        vector<int>ans;
        while(s.empty()){
            Node *temp = s.top();
            s.pop();
            bool flag = visited.top();
            visited.pop();
            //1st time visited
            if(flag==0){
                //right
                if(temp->right){
                s.push(temp->right);
                visited.push(0);
                }     
                //root
                s.push(temp);
                visited.push(1);
                //left
                 if(temp->left)
                s.push(temp->left);
                visited.push(0);
            }
            
            //2nd time visited;
            else{
                ans.push_back(temp->data);
            }
        }
        return ans;
    }
};