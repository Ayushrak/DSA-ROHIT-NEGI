#include<iostream>
#include<queue>
using namespace std;


//reverse K group
    int main(){
        queue<int>q;
 queue<int> modifyQueue(queue<int> q, int k){
        // add code here.
        stack<int>s;
        while(k--){
            s.push(q.front());
            q.pop();
        }
        int n = q.size();
        while(!s.empty()){
            q.push(s.top());
            s.pop();
        }
        
        while(n--){
            q.push(q.front());
            q.pop();
        }
        return q;
    }
}