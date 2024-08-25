#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

class Solution{
  public:
  
  class Compare
  {
      public:
      bool operator()(Node *a,Node *b){
          //heap mhe ulta hota hai
          return a->data > b->data;
      }
  };
    //Function to merge K sorted linked list.
    Node * mergeKLists(Node *arr[], int K)
    {
           // Your code here
           priority_queue<Node *, vector<Node * >, Compare>p;
           
            for (int i = 0; i < K; ++i) {
                if (arr[i])
                    p.push(arr[i]);
            }
           Node *root = new Node(0);
           Node *tail = root;
           
           Node *temp;
           
           while(!p.empty()){
               temp = p.top();
               p.pop();
               tail->next = temp;
               tail = tail->next;
               if(temp->next)
               p.push(temp->next);
           }
           return root->next;
    }
};