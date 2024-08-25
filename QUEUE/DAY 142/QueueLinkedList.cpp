#include<iostream>
using namespace std;


//queue using linkedlist
class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data=data;
        this->next=NULL;
    }
};


class Queue{
    public:
    Node* front;
    Node* rear;
    Queue(){
        front=NULL;
        rear=NULL;
    }

    //empty
    bool isEmpty(){
        return front==NULL;
    }

    bool isFull(){
        return rear->next==NULL;
    }

    void push(int data){
        //empty
        if(isEmpty()){
            front=rear=new Node(data);
            cout<<"Pushed"<<data<<"into in Queue"<<endl;
            return;
        }
        else if(isFull()){
            cout<<"Queue Overflow"<<endl;
        }
        else{

            rear->next=new Node(data);
            rear=rear->next;
            cout<<"Pushed"<<data<<"into in Queue"<<endl;
        }
    }

    void pop(){
        if(isEmpty()){
            cout<<"Queue Underflow"<<endl;
        }
        else{
            cout<<"Popped"<<front->data<<"from Queue"<<endl;
            Node* temp=front;
            front=front->next;
            delete temp;
        }
    }

    int start(){
        if(isEmpty()){
            cout<<"Queue Underflow"<<endl;
        }
        else{
            return front->data;
        }
    }
};

    int main(){
        Queue q;
        q.push(1);
        q.push(2);
        q.push(3);
        q.push(4);
        q.push(5);
        q.pop();
        cout<<q.isEmpty()<<endl;
        cout<<q.isFull()<<endl;
        cout<<q.start()<<endl;
        return 0;
    }

