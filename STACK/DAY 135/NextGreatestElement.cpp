#include<iostream>
#include<stack>
#include<vector>
using namespace std;


class Solution {
  public:
    vector<long long> nextLargerElement(vector<long long> &arr, int n){
        // Your code here
        vector<long long>ans(n,-1);
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(arr[j]>arr[i]){
                    ans[i] = arr[j];
                    break;
            }
            }
        }
        return ans;
    }
};

//using stack
class Solution {
  public:
    vector<long long> nextLargerElement(vector<long long> &arr, int n){
        // Your code here
        vector<long long>ans(n,-1);
        stack<int>st;
        
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]<arr[i]){
                ans[st.top()] = arr[i];
                st.pop();
            }
            st.push(i);
        }
        return  ans;
    }
};


//3rd solution
class Solution {
  public:
    vector<long long> nextLargerElement(vector<long long> &arr, int n){
        // Your code here
        vector<long long>ans(n,-1);
        stack<int>st;
        
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]<arr[i])
                st.pop();
            if(!st.empty())
            ans[i] = arr[st.top()];
            
            st.push(i);
        };
        return ans;
    }
};