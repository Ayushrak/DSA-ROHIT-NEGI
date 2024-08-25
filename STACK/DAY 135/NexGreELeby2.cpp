#include<iostream>
using namespace std;

class Solution {
  public:
    vector<long long> nextLargerElement(vector<long long> &arr, int n){
        // Your code here
        vector<long long>ans(n,-1);
        stack<int>st;
        
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]<arr[i%n]){
                ans[st.top()] = arr[i%n];
                st.pop();
            }
            st.push(i);
        }
        return  ans;
    }
};