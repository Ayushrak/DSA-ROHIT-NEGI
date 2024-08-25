#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution
{
    public:
    priority_queue<int>LeftMaxHeap;  //Max heap
    priority_queue<int,  vector<int>, greater<int>>RightMinHeap; //Min heap
    //Function to insert heap.
    void insertHeap(int &x)
    {
        if(LeftMaxHeap.empty())
        {
            LeftMaxHeap.push(x);
            return;
        }
        
        if(x>LeftMaxHeap.top())
        RightMinHeap.push(x);
        else
        LeftMaxHeap.push(x);
        
        balanceHeaps();
    }
    
    //Function to balance heaps.
    void balanceHeaps()
    {
        //MIN HEAP(right) size should not be greater than Max Heap(left);
        if(RightMinHeap.size()>LeftMaxHeap.size()){
            LeftMaxHeap.push(RightMinHeap.top());
            RightMinHeap.pop();
        }
        else{
            //Difference between left- right  should not greater than 1;
            if(RightMinHeap.size()<LeftMaxHeap.size()-1)
            {
                RightMinHeap.push(LeftMaxHeap.top());
                LeftMaxHeap.pop();
            }
        }
    }
    
    //Function to return Median.
    double getMedian()
    {
        //Left >right
        if(LeftMaxHeap.size()>RightMinHeap.size())
        return LeftMaxHeap.top();
        else{
            double ans = LeftMaxHeap.top() + RightMinHeap.top();
            ans/=2;
            return ans;
        }
    }
};