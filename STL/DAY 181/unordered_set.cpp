//O(1) complexity

#include<iostream>
#include<unordered_set>
using namespace std;

//not in sorted order
// by hashing

int main()
{
    unordered_set<int>s;
    unordered_multiset<int>m;
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(4);
    s.insert(5);
    s.insert(6);
    s.insert(7);
    s.insert(8);
    s.insert(9);
    s.insert(10);
    s.insert(11);
    s.insert(12);
    s.insert(13);

    for(auto it =s.begin(); it !=s.end();it++)
    {
        cout<<*it<<" ";
    }
}