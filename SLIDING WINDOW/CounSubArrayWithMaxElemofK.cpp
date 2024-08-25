class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int start=0,end=0,maxElem,count=0;
        long long total=0;
        for(int i=0;i<n;i++)
        maxElem =max(maxElem,nums[i]);

        while(end<n){
            if(nums[end]==maxElem)
                count++;
            
            while(count==k){
                total+=n-end;

                if(nums[start]==maxElem)
                    count--;
                start++;
            }
            end++;
        }
        return total;
    }
};