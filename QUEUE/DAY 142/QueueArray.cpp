#include<iostream>
using namespace std;

class Queue{
    int front;
    int rear;
    int  *arr;
    int size;
public:
    Queue( int n){
        arr = new int[n];
        front = -1; 
        rear = -1;  
        size = n;
    }

    bool isEmpty(){
       return front == -1;
    }

    bool isFull(){
        return rear == size - 1;
    }

    //push element
    void push(int data){
        //empty
        if(isEmpty()){
            cout<<"Pushed"<<data<<"into in Queue"<<endl;
            front=rear=0;
            arr[0]=data;
        }
       else if(isFull()){
            cout<<"Queue Overflow"<<endl;
            return;
        }
    else {rear++;
        arr[rear] = data;
        cout<<"Pushed"<<data<<"into in Queue"<<endl;
    }
    }
    //pop elemrnt
    void pop(){
        if(isEmpty()){

            cout<<"Queue Underflow"<<endl;
            return;
        }
        else{
         if(front == rear)
         {
         cout<<"Popped "<<arr[front]<<" from Queue"<<endl;
            front = rear = -1;
         }
         else{
         cout<<"Popped "<<arr[front]<<" from Queue"<<endl;
         front++;
        }
        }   
    }

    //start main kunsa element rkha hai
    int peek(){
        if(isEmpty()){
            cout<<"Queue Underflow"<<endl;
            return -1;
        }
        else{
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