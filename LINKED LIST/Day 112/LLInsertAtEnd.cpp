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

    //insertion at end;
   Node *tail = NULL;
   for(int i=0;i<4;i++){
    if(head==NULL){
        head =  new Node(arr[i]);
        tail = head;
    }
    else{

         // Node *tail;
            // tail=head;
            // while(tail->next !=NULL)
            // {
            //   tail=tail->next;
            // }
            // Node * temp;
            // temp= new Node(arr[i]);
            // tail->next=temp;

                    tail->next = new Node(arr[i]);
        tail = tail ->next;
    }
   }

        Node *temp ;
        temp = head ;
        for(int i=0;i<4;i++){
            cout<<temp->data<<" ";
            temp= temp->next;
        }
}

