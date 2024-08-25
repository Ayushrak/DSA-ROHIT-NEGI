#include<iostream>
#include<stack>
using namespace std;

class Queue{
public:
    stack<int>st1;
    stack<int>st2;

    Queue(){

    }

    bool empty(){
        return st1.empty() && st2.empty();
    }

    void push(int data){
        st1.push(data);
    }

    int pop(){
        if(st1.empty() && st2.empty()){
            cout<<"Queue is empty";
        }
        else if(!st2.empty()){
            int element = st2.top();
            st2.pop();
            return element;
        }
        else{
            while(!st1.empty()){
                st2.push(st1.top());
                st1.pop();
            }
        }
    }

    int front(){
        if(st1.empty() && st2.empty()){
            cout<<"Queue is empty";
        }
        else if(!st2.empty()){
            return st2.top();
        }
        else{
            while(!st1.empty()){
                st2.push(st1.top());
                st1.pop();
            }
            return st2.top();
        }
    }
};