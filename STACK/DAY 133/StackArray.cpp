#include<iostream>
using namespace std;

class Stack{
    int *arr;
    int size;
    int top;
public:
    bool flag;
    Stack(int s){
        size = s;
        top = -1;
        arr = new int[s];
        flag =1;
    }


    //push
    void push(int item){
        if(top==size-1){
            cout<<"STACK OVERFLOW"<<endl;
            return;
        }
        else{
            top++;
            arr[top] = item;
            cout<<"pushed "<<item<<" into the stack\n";
            flag=0;
        }
    }


    //pop
    void pop(){
        if(top==-1){
            cout<<"Stack Underflow\n"<<endl;
        }
        else{
             cout<<"Popped "<<arr[top]<<" from the stack\n";
            top--;
            flag=1;     
    }
    }

    //peek
    int peek()
    {
        if(top==-1){
            cout<<"Stack is empty\n";
            return -1;
        }
        else{
            return arr[top];
        }
    }

    //isEmpty
    bool isEmpty(){
        return  top == -1;
    }

    //IsSize
    bool isSize(){
        return top+1;
    }
};

int main(){
    Stack s(5);
    // s.push(5);
    // s.push(6);
    // s.push(8);
    // cout<<s.peek()<<endl;
    // s.pop();
    // cout<<s.peek()<<endl;
    // cout<<s.isEmpty()<<endl;
    // cout<<s.isSize()<<endl;
    // //   s.push(6);
    // // s.push(8);
    // //   s.push(6);
    // // s.push(8);

   
    int value = s.peek();
    if(s.flag==0)
        cout<<value<<endl;

 }