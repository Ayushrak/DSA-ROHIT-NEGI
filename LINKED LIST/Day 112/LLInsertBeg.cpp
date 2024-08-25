#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node *next;
    Node(int value){
        data = value;
        next = NULL;
    }
};

int main(){
    Node *head;
    head = new Node(4);
    cout<<head->data<<endl;
    cout<<head->next<<endl;
    int  arr[] ={1,2,3,4};
    //insertion at beigining
    
    for(int i=0;i<4;i++){
        //if linkedlist doesn't exist
        if(head==NULL)
        head = new Node(arr[i]);

        else{
        Node *temp;
        temp = new Node(arr[i]);
        temp->next = head;
        head = temp;
        }
    }

    Node *temp;
    temp = head;
    while(temp)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}