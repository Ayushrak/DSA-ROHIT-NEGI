#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int value){
        data = value;
        next = NULL;
        prev = NULL;
    }
};

int main(){
    Node *head,*tail;
    tail=  head = NULL;
    for(int i=0;i<5;i++){
    if(head==NULL){
        head = new Node(5);
        tail = head;
    }
    else{
        Node *temp = new Node(10);
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }

    
 }
    
    Node *trav = head;
    while(trav!=NULL){
        cout<<trav->data<<" ";
        trav = trav->next;
    }

}
