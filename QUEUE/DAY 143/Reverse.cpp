#include<iostream>
#include<stack>
#include<queue>
using namespace std;

int main(){
    //plese reverse this queue
    
    // 1 2 3 4 5
    queue<int>q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    stack<int>s;
    while(!q.empty()){
        s.push(q.front());
    }
    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }

    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
}
