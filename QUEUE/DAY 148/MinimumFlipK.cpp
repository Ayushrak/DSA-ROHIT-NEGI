#include<iostream>
#include<vector>
#include<queue>
#include<deque>
using namespace std;


//tle code
// Time Limit Exceeded code


class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int flip = 0;
        int  n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==0)
            {
                //last  element
                if(i+k-1>=n)
                return -1;
                
                for(int j=i;j<=i+k-1;j++)
                {
                    nums[j]=!nums[j];
                }
                flip++;
            }
        }
        return flip;
    }
};

//2nd optimized
class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        queue<int>q;
        int flip =0;
        int n = nums.size();

        for(int i=0;i<n;i++){
            if(!q.empty()&& q.front()<i)
            q.pop();

            if(q.size()%2==nums[i])
            {
                if(i+k-1>=n)
                return -1;

                q.push(i+k-1);
                flip++;

            }
        }
        return flip;
        
    }
};

