#include<iostream>
using namespace std;

class Node {
    public:
    int data;   
    Node *next; 
    Node(int x) {
        data = x;
        next = NULL;
    }
};

//Brute force approach
class Solution
{
    public:
    
    Node *find(Node *curr1,Node *curr2,Node *X){
        if(X==NULL)
        return NULL;
        while(curr1!=X){
            curr1=curr1->next;
            curr2 = curr2->next;
        }
        return curr2;
    }
    Node *copyList(Node *head)
    {
        //Write your code here
        Node *headCopy = new Node(0);
        Node *tailCopy = headCopy;
        Node *temp = head;
        
        while(temp){
            tailCopy->next = new Node(temp->data);
            tailCopy = tailCopy->next;
            temp = temp->next;
        }
        
        tailCopy = headCopy;
        headCopy = headCopy->next;
        delete tailCopy;
        tailCopy = headCopy;
        temp = head;
    
    
    while(temp)
    {   
        tailCopy->arb = find(head,headCopy,temp->arb);
        tailCopy = tailCopy->next;
        temp = temp->next;
    }
    return headCopy;
    }
};

//optimisied
   class Solution
{
    public:
    
   
    Node *copyList(Node *head)
    {
        //Write your code here
        Node *headCopy = new Node(0);
        Node *tailCopy = headCopy;
        Node *temp = head;
        
        while(temp){
            tailCopy->next = new Node(temp->data);
            tailCopy = tailCopy->next;
            temp = temp->next;
        }
        
        tailCopy = headCopy;
        headCopy = headCopy->next;
        delete tailCopy;
        tailCopy = headCopy;
        temp = head;
    
    
    unordered_map<Node *,Node *>m;
     while(temp){
            m[temp]= tailCopy;
            tailCopy = tailCopy->next;
            temp=temp->next;
     }
           
            tailCopy = headCopy;
            temp =head;
        
    while(temp){
        tailCopy->arb = m[temp->arb];
        tailCopy = tailCopy->next;
        temp=temp->next;
    }
    return headCopy;
    } 
};