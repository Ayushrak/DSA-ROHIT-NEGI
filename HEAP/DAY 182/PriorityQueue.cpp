#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
//     priority_queue<int> p;
//    p.push(10);
//    p.push(3);
//    p.push(9);
//    p.push(8);
//    p.push(5);
//    p.push(13);
//    p.push(18);
//    p.push(14);
//    p.push(11);
//    p.push(70);

//    cout<<p.top()<<endl;

//    //delete
//    p.pop();

//    //size
//    cout<<p.size()<<endl;

//    //check if empty
//    cout<<p.empty()<<endl;

//    while(!p.empty()){
//        cout<<p.top()<<" ";
//        p.pop();
//    }
// }


//Min heap
    priority_queue<int, vector<int> ,greater<int> >p2;
    p2.push(10);
    p2.push(3);
    p2.push(9);
    p2.push(8);
    p2.push(5);
    p2.push(13);
    p2.push(18);
    p2.push(14);
    p2.push(11);
    p2.push(70);

    while(!p2.empty()){
        cout<<p2.top()<<" ";
        p2.pop();
    }
}
   

