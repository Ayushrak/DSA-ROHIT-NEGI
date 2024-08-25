#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

Node*  Reverse(Node *curr, Node *prev){
        if(curr == NULL)
        return prev;
        
        Node *front = curr->next;
        curr->next = prev;
       return Reverse(front,curr);
    }
     Node* addTwoLists( Node* first, struct Node* second)
    {
        // code here
        first = Reverse(first, NULL);
        second = Reverse(second,NULL);
        
        Node *curr1 = first;
        Node *curr2 = second;
        
        Node *head = new Node(0);
        Node *tail = head;
        int sum, carry = 0;
        
        while(curr1 && curr2){
            sum  = curr1->data + curr2->data +carry;
            tail->next = new Node(sum%10);
            curr1 = curr1->next;
            curr2 = curr2->next;
            tail  = tail->next;
            carry = sum/10;
        }
        
        while(curr1){
             sum  = curr1->data  +carry;
            tail->next = new Node(sum%10);
            curr1 = curr1->next;
            tail  = tail->next;
            carry = sum/10;
        }
        
        while(curr2){
             sum  = curr2->data  +carry;
            tail->next = new Node(sum%10);
            curr2 = curr2->next;
            tail  = tail->next;
            carry = sum/10;
        }
        
        while(carry){
            tail->next = new Node(carry%10);
            tail = tail->next;
            carry = carry/10;
        }
        
        head = Reverse(head->next, NULL);
        return head;
    }

     Node* addTwoNumbers(Node* l1, Node* l2) {
        Node* dummy=new Node(0);
        Node* temp=dummy;
        int carry=0;
        while(l1!=NULL || l2!=NULL || carry){
            int sum=0;
            if(l1!=NULL){
                sum+=l1->data;
                l1=l1->next;
            }
            if(l2!=NULL){
                sum+=l2->data;
                l2=l2->next;
            }
            sum+=carry;
            carry=sum/10;
            Node* newnode=new Node(sum%10);
            temp->next=newnode;
            temp=temp->next;
        }
        return dummy->next; 
    }