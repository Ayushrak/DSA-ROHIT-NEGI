#include<iostream>
#include<vector>
#include<stack>
using namespace std;


stack<int>st1;
stack<int>st2;

void push(int x){
    if(st1.empty()){
    st1.push(x);
    st2.push(x);
    }
    else{
        st1.push(x);
        st2.push(x,st2.top()); 
    }
}

int pop(){
    if(st1.empty()){
        return -1;
    }
    else{
        int x = st1.top();
        st1.pop();
        st2.pop();
        return x;
    }
}

int getMin(){
    if(st2.empty()){
        return -1;
    }
    else{
        return st2.top();
    }
}



//2nd method without stack
 void push(int x){
     if((st1.empty())){
         st1.push(x*101+x);
     }
     else{
         st1.push(x*101+ min(st1.top()%101,x));
     }
 }
        
        int pop(){
            if(st1.empty()){
                return -1;
            }
            else{
                int x = st1.top()/101;
                st1.pop();
                return x;
            }
        }

        int getMin(){
            if(st1.empty()){
                return -1;
            }
            else{
                return st1.top()%101;
            }
        }

