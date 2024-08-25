#include<iostream>
using namespace std;

//circular queue

class Queue
{
    int *arr;
    int front;
    int rear;
    int size;
 public:
    Queue(int n)
    {
        arr = new int[n];
        front = -1;
        rear = -1;
        size = n;
    }   
    bool isEmpty()
    {
        if(front == -1 && rear == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool isFull()
    {
        if((rear+1)%size == front)
        {
            return true;
        }
        else
        {  
            return false;   
        }

    }

    void push(int data)
    {

        if(isFull())    
        {
            cout<<"Queue Overflow"<<endl;

        } 
        else    
        {
            if(isEmpty())   
            {
                front = 0;
                rear = 0;
                arr[rear] = data;
                rear = (rear+1)%size;
                cout<<"Pushed"<<data<<"into in Queue"<<endl;
            }
            else
            {
                rear = (rear+1)%size;
                arr[rear] = data;
                cout<<"Pushed"<<data<<"into in Queue"<<endl;
            }
        }
    } 


    void pop(){
        if(isEmpty())
        {
            cout<<"Queue Underflow"<<endl;
        }
        else
        {
            if(front == rear)
            {
                front = -1;
                rear = -1;
                cout<<"Popped"<<arr[front]<<"from Queue"<<endl;
            }
            else
            {
                front = (front+1)%size;
                cout<<"Popped"<<arr[front]<<"from Queue"<<endl;
            }
        }
    } 

    int peek(){
        if(isEmpty())
        {
            cout<<"Queue Underflow"<<endl;
            return -1;
        }
        else    
        {
            return arr[front];
        }
    }
};

    int main(){
        
        Queue q(5);
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.pop();
    q.pop();     
    q.pop();
    cout<<q.peek()<<endl;
    cout<<q.isEmpty()<<endl;
    cout<<q.isFull()<<endl;
    q.push(1);
    q.pop();
    cout<<q.peek();
    }