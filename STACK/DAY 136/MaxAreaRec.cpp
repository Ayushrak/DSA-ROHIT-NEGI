#include<iostream>
#include<vector>
#include<stack>
using namespace std;

//problem no [->84 leetcode<--]
class Solution1 {
public:
    int largestRectangleArea(vector<int>& heights) {
        //Next smallest left
        //Next smallest right
        int n = heights.size();
        vector<int>right(n);
        vector<int>left(n);
        stack<int>st;
        //Next small right find karo
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()]>heights[i]){
                right[st.top()] =i;
                st.pop();
            }
            st.push(i); 
        }
        //remaning stack element 
        while(!st.empty()){
            right[st.top()]=n;
            st.pop();
        }

        //Next small left find karo
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && heights[st.top()]>heights[i]){
                left[st.top()]=i;
                st.pop();
            }
            st.push(i);
        }
        //remaining stack element
        while(!st.empty()){
            left[st.top()]=-1;
            st.pop();
        }

       //area ko calcuate karo
       int ans=0;
       for(int i=0;i<n;i++){
           ans = max(ans,heights[i]*(right[i]-left[i]-1));
       } 
        return ans;
    }
};


//without using extra memory
class Solution2 {
public:
    int largestRectangleArea(vector<int>& heights) {
        int ans=0;
        int index;
        stack<int>st;
        int n = heights.size();

        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()]>heights[i]){
                index = st.top();
                st.pop();
                if(!st.empty())
                ans = max(ans,heights[index]*(i-st.top()-1));
                else
                ans = max(ans,heights[index]*i);
            }
            st.push(i);
        }
        while(!st.empty()){
            index = st.top();
            st.pop();
            if(!st.empty())
            ans = max(ans,heights[index]*(n-st.top()-1));
            else
            ans = max(ans,heights[index]*n);
        }
        return ans;
    }
};