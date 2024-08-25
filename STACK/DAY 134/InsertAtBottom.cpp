#include<iostream>
#include<stack>
using namespace std;

class Solution{
public:
    stack<int> insertAtBottom(stack<int> St,int X){
        stack<int>temp;
        while(!St.empty()){
            temp.push(St.top());
            St.pop();
        };
        
        St.push(X);
        
        while(!temp.empty()){
            St.push(temp.top());
            temp.pop();
        };
        return St;
    }
};