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

int intersectPoint(Node* head1, Node* head2)
{
    // Your Code Here
    Node *curr1 = head1;
    
    while(curr1->next!=NULL){
        curr1 = curr1->next;
    }
    
    curr1->next = head1;
    
    
    Node *slow = head2;
    Node *fast = head2;
        
        
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
            
        if(slow==fast)
            break;
        }
        
        //head2 not connect head1 
        if(fast==NULL || fast->next==NULL)
        return -1;
        
        slow =head2;
        
        while(slow!=fast){
            slow=slow->next;
            fast=fast->next;
        }
        
        return slow->data;
}


// 2nd method
int IntersectPoint(Node* head1, Node* head2)
{
    Node *curr1 = head1, *curr2 = head2;
    int count1=0,count2=0;
   
   while(curr1!=NULL){
       count1++;
       curr1=curr1->next;
   }
   
   while(curr2!=NULL){
       count2++;
       curr2 = curr2->next;
   }
   
   curr1 = head1 , curr2 = head2;
   
   while(count1>count2){
       count1--;
       curr1=curr1->next;
   }
   
   while(count2>count1){
       count2--;
       curr2 = curr2->next;
   }
   
   while(curr1!=curr2){
       curr1 = curr1->next;
       curr2 = curr2->next;
   }
   
   if(!curr1)
   return -1    ;
        
   return  curr1->data;
}