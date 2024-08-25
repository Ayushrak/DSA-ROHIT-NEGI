#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    pair<string,int>p;
     p = make_pair("rohit",30);

    // p.first = "Rohit";
    // p.second = 30;

    cout<<p.first<<" "<<p.second<<endl;

    //three values in pair
    //name ,age ,weiught
    pair<string,pair<int,int>>p1;
    p1 = make_pair("ayush",make_pair(20,30));

    // p1.first = "ayush";
    // p1.second.first = 20;
    // p1.second.second = 30;
    cout<<p1.first<<" "<<p1.second.first<<" "<<p1.second.second<<endl;

   pair<pair<string,int>,int>p3;
    p3 = make_pair(make_pair("rohit",30),80);

    cout<<p3.first.first<<" "<<p3.first.second<<" "<<p3.second<<endl;
}