#include<iostream>
#include<deque>
using namespace std;


int main(){
    deque<int>d;
    d.push_back(1);
    d.push_back(2);
    d.push_front(3);
    d.push_front(4);
    d.pop_back();
    d.pop_front();
    cout<<d.front()<<endl;
    cout<<d.back()<<endl;
    return 0;
}