//it store like doubly linked list


#include<iostream>
#include<list>
#include<bits/stdc++.h>
using namespace std;

int main(){
    list<int> l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    l.push_back(4);
    l.push_back(5);
    l.push_front(0);
    l.pop_front();
    l.push_front(9);
    l.pop_back();
    // cout<<l.front()<<endl;
    // cout<<l.back()<<endl;
    // cout<<l.size()<<endl;

    //iterattor
    for(auto it=l.begin();it!=l.end();it++){
        cout<<*it<<endl;
    }

     for(list<int>::iterator it=l.begin();it!=l.end();it++){
        cout<<*it<<endl;
    }

    //reverse
    for(auto it=l.rbegin();it!=l.rend();it++){
        cout<<*it<<endl;
     }
}
