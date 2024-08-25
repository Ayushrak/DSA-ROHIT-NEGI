#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int d){
        data=d;
        next=NULL;
    }
};

class NStack{
public:
    stack<int>st;
    int *arr;
    Node **top;


    NStack(int N, int S){
        arr=new int[S];
        top=new Node*[S];
        for(int i=0;i<N;i++){
            top[i]=NULL;
        }
        for(int i=0;i<S;i++){
            st.push(i);
        }
    }

    bool push(int x,int m){
        if(st.empty())
        return 0;
        arr[st.top()] = x;
        Node *temp = new Node(st.top());
        temp->next = top[m-1];
        top[m-1] = temp;
        st.pop();
        return 1;
    }

    int pop(int m){
        if(top[m-1]==NULL){
            return -1;
        }
        int element = arr[Top[m-1]->index];
        st.push(top[m-1]->index);
        top[m-1] = top[m-1]->next;
        return element;
};