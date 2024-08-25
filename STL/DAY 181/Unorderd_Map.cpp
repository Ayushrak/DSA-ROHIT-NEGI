#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;
//npt in sotred order
int main()
{
    unordered_map<int,int>m;
    unordered_multimap<int,int>n; //duplicate element allowed
    m.insert(make_pair(1,1));
    m.insert(make_pair(2,2));
    m.insert(make_pair(3,3));
    m.insert(make_pair(4,4));
    m.insert(make_pair(5,5));
    m.insert(make_pair(6,6));
    m.insert(make_pair(7,7));
    m[100] = 60; //insert
    m[2]  = 50; //update
    for(auto it =m.begin(); it !=m.end();it++)
    {
        cout<<it->first<<" "<<it->second<<endl;
    }
}