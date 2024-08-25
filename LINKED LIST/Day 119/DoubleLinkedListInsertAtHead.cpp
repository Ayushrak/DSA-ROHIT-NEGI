#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int value){
        data = value;
        next = prev = NULL;
    }
};

int main(){
    Node *head = NULL;

    //insert at start
    

    //LinkedList does'nt exist
    if(head==NULL){
        head = new Node(10);
    }
    else{
        Node *temp = new Node(5);
        temp->next = head;
        head->prev = temp;
        head  = temp;
    }

    Node *trav = head;
    while(trav!=NULL){
        cout<<trav->data<<" ";
        trav = trav->next;
    }
}