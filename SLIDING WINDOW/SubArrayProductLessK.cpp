class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int position = 1, start = 0,end=0,  n = nums.size() , count =0;

        while(end<n){
            position *= nums[end];

            while(position >= k && start <=end){
                position /= nums[start];
                start++;
            }

            count += end - start +1;
            end++;
        }
        return count;
    }
};