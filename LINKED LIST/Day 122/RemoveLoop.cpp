#include<iostream>
using namespace std;


class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};


class Solution
{
    public:
    //Function to remove a loop in the linked list.
    void removeLoop(Node* head)
    {
        // code here
        // just remove the loop without losing any nodes
        Node *slow = head;
        Node *fast = head;
        
        
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            
            if(slow==fast)
            break;
        }
        
        if(fast==NULL || fast->next==NULL)
        return;
        
        slow =head;
        
        while(slow!=fast){
            slow=slow->next;
            fast=fast->next;
        }
        
        while(slow->next!=fast){
            slow = slow->next;
        }
        slow->next = NULL;
    }
};

//2nd method

class Slution
{
    public:
    //Function to remove a loop in the linked list.
    void RemoveLoop(Node* head)
    {
        // code here
        // just remove the loop without losing any nodes
        Node *slow = head;
        Node *fast = head;
        
        
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            
            if(slow==fast)
            break;
        }
        
        if(fast==NULL || fast->next==NULL)
        return;
        
        //Find the length of loop
        slow = fast->next;
        int count =1;
        while(slow!=fast){
            count++;
            slow = slow->next;
        }
        
        
        slow = head , fast = head;
        while(count--){
            fast =fast->next;
        }
        
        while(slow!=fast){
            slow=slow->next;
            fast=fast->next;
        }
        
        while(slow->next!=fast){
            slow = slow->next;
        }
        slow->next = NULL;
    }
};