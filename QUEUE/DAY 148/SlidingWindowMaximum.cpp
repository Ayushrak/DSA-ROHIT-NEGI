#include<iostream>
#include<vector>
#include<deque>
using namespace std;
# define INT_MIN 1;


//get time limit eceed 
//t.c->o(n*k)
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>ans;
        int n = nums.size();
        for(int i=0;i<=n-k;i++){
            int total = INT_MIN;
            for(int j=i;j<i+k;j++){
                total = max(total,nums[j]);
            }
            ans.push_back(total);
        }
          return ans;
    }
};

//optimized
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>d;
        vector<int>ans;
        int n  = nums.size();
        //k-1 elements ko traverse karo
        for(int i=0;i<k-1;i++){
            if(d.empty())
            d.push_back(i);
            else
            {
                while(!d.empty()&&nums[i]>nums[d.back()])
                d.pop_back();

                d.push_back(i);
            }
        };

        for(int i=k-1;i<n;i++){
            //Remove smaller element from back
            while(!d.empty() && nums[i]>nums[d.back()])
            d.pop_back();
            d.push_back(i);
            //if front element is outside the window ,pop them
            if(d.front()<=i-k)
            d.pop_front();
            //find ans 
            ans.push_back(nums[d.front()]);
        }
        return ans;
    }
};