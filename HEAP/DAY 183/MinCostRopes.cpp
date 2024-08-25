#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
        // Your code here
        priority_queue<long long, vector<long long>, greater<long long>>p;
        
        for(long long i=0;i<n;i++)
        p.push(arr[i]);
        
        long long cost = 0;
        
        while(p.size()>1){
            long long rope = p.top();
            p.pop();
            rope+=p.top();
            p.pop();
            cost+=rope;
            p.push(rope);
        }
        return cost;        
    }
};