#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int val){
        data = val;
        next = NULL;
        prev = NULL;
    }
};

Node * CreateDLL(int arr[],int index, int size, Node* back){
    if(index ==size)
    return NULL;

    Node *temp = new Node(arr[index]);
    temp->prev =back;
    temp->next = CreateDLL(arr,index+1,size,temp);
    return temp;
}

int main(){
    Node *head = NULL;

    int pos=2;

    //insert at start;
     int arr[] ={1,2,3,4,5};
    head = CreateDLL(arr,0,5,head);

    if(pos==0){
        if(head==NULL){
        head = new Node(5);
    }
        else{
            Node *temp = new Node(5);
            temp->next = head;
            head->prev=temp;
        }
    }
    
    Node *curr = head ;
    while(--pos){
        curr= curr->next;
    }

    //insert at end;
    if(curr->next ==NULL){
        Node *temp = new Node(5);
        temp->prev = curr;
        curr->next = temp;
    }
    //insert at middle
    else{
    Node *temp = new Node(5);
    temp->next = curr->next;
    temp->prev =  curr;
    curr->next = temp;
    temp->next->prev= temp;
    }


     Node *trav = head;
    while(trav!=NULL){
        cout<<trav->data<<" ";
        trav = trav->next;
    }
}