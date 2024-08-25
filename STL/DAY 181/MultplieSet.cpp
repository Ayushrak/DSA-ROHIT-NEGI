#include<iostream>
#include<bits/stdc++.h>
using namespace std;
//duplicate set allowed
int main()
{
    multiset<int>s;
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(4);
    s.insert(1);
    s.insert(8);
    s.insert(9);
    s.insert(2);
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(4);
    s.erase(4);
    for(auto it =s.begin(); it !=s.end();it++)
    {
        cout<<*it<<" ";
    }
}