#include<iostream>
#include<queue>
using namespace std;


class Dequeue{
    int *arr;
    int front;
    int rear;
    int size;
    public:
    Dequeue(int n){
        arr = new int[n];
        front = -1;
        rear = -1;
        size =n;
    }

    bool isEmpty(){
       return front == -1;
    }

    bool isFull(){
        return (rear+1)%size == front;
    }

    void push_Front(int x){
       if(isEmpty()){
        front = 0;
        rear = 0;
        cout<<"Pushed "<<x<<" in front of dequeue"<<endl;
        arr[rear] = x;
        return;
       }
        else if(isFull()){
            cout<<"Dequeue is full"<<endl;
        }
        else{
            front = (front-1+size)%size;
            arr[front] = x;
            cout<<"Pushed "<<x<<" in front of dequeue"<<endl;
            return;
        }
       }

       void push_Rear(int x){
           if(isEmpty()){
               front = 0;
               rear = 0;
               cout<<"Pushed "<<x<<" in rear of dequeue"<<endl;
               arr[rear] = x;
               return;
           }
           else if(isFull()){
               cout<<"Dequeue is full"<<endl;
           }
           else{
               rear = (rear+1)%size;
               arr[rear] = x;
               cout<<"Pushed "<<x<<" in rear of dequeue"<<endl;
               return;
           }
       }

       void pop_front(){
           if(isEmpty()){
               cout<<"Dequeue is empty"<<endl;
           }
           else {
            //single element
                if(front==rear){
                    front = -1;
                    rear = -1;
                }
            //greater than 1 element
            else{
                front = (front+1)%size;
            }
           }
       }

       void pop_back(){
           if(isEmpty()){
               cout<<"Dequeue is empty"<<endl;
           }
           else {
            //single element
                if(front==rear){
                    front = -1;
                    rear = -1;
                }
            //greater than 1 element
            else{
                rear = (rear-1+size)%size;
            }
           }     
    }

    int start(){
        if(isEmpty()){
            return -1;
        }
        else{
            return arr[front];
        }
    }

    int end(){
        if(isEmpty()){
            return -1;
        }
        else{
            return arr[rear];
        }
    }
};


int  main(){

    Dequeue d(5);
    d.push_Front(1);
    d.push_Front(2);
    d.push_Front(3);
    d.pop_back();
    d.push_Rear(4);
    d.pop_front();
    cout<<d.start()<<endl;
    cout<<d.end()<<endl;
}