#include<iostream>
using namespace std;



 //1st method

class twoStacks
{
    public:
    int *arr;
    int top1,top2;
    int size;
    twoStacks(int n=100)
    {
        arr = new int[n];
        size = n;
        top1 = -1;
        top2 = n;
    }
 
    //Function to push an integer into the stack1.
    void push1(int x)
    {
        if(top1+1==top2)
            return;
        top1++;
        arr[top1]=x;
    }
    
    //Function to push an integer into the stack2.
    void push2(int x)
    {
       
        if(top2-1==top1)
        return;
        top2--;
        arr[top2]=x;
    }
    
    //Function to remove an element from top of the stack1.
    int pop1()
    {
        if(top1==-1)
        return -1;
        int elem = arr[top1];
        top1--;
        return elem;
    }
    
    //Function to remove an element from top of the stack2.
    int pop2()
    {
        if(top2==size)
        return -1;
        int elem = arr[top2];
        top2++;
        return elem;
    }
};



//2nd method
class twoStacks
{
    int *arr;
    int size;
    int top1, top2;
    public:
    
    twoStacks(int n=100)
    {
        size = n; 
        arr = new int[n]; 
        top1 = -1; 
        top2 = size;
    }
 
    //Function to push an integer into the stack1.
    void push1(int x)
    {
        if(top2-top1>1){
            top1++;
            arr[top1]=x;
        }
    }
    
    //Function to push an integer into the stack2.
    void push2(int x)
    {
          if(top2-top1){
              top2--;
              arr[top2]=x;
          }
    }
    
    //Function to remove an element from top of the stack1.
    int pop1()
    {
        if(top1>=0){
            int ans = arr[top1];
            top1--;
            return ans;
        }
        else 
            return -1;
    }
    
    //Function to remove an element from top of the stack2.
    int pop2()
    {
       if(top2<size){
           int ans = arr[top2];
           top2++;
           return ans;
       }
       else
            return -1;
    }
};
