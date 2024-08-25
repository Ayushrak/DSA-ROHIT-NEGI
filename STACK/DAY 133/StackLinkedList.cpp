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

class Stack{
    Node *top;
    int size;
public:
    Stack(){
        top=NULL;
        size=0;
    }

    void push(int value){
        Node *temp = new Node(value);
        if(temp==NULL){
            cout<<"STACK OVERFLOW"<<endl;
            return;
        }
        temp->next = top;
         cout<<"Pushed"<<value<< " from the stack\n";
        top = temp;
        size++;
    }

    void pop(){
        if(top==NULL){
            cout<<"stack undeflow\n";
            return;
        }
      else{  
        Node *temp = top;
        top = top->next;
         cout<<"Popped"<<top->data<< " from the stack\n";
        delete temp;  
        size--;    
    }
    }
    int peek(){
        if(top==NULL){
        cout<<"stack is empty"<<endl;
            return -1;
    }
        else{
            return top->data;
        }
    }

    bool isEmpty(){
        return top==NULL;
    }

    bool isSize(){
        return size;
    }
};

int main(){
    Stack s;
    s.push(6);
    s.push(3);
    s.push(1);
    s.push(8);
    s.pop();
    cout<<s.isSize()<<endl;
    cout<<s.peek();
}