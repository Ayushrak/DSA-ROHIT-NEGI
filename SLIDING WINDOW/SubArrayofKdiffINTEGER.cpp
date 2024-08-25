class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int total=0;
        unordered_map<int,int>freq;
        int start=0,end=0,n=nums.size(),count=0;

        //code of k times
        while(end<n){
            freq[nums[end]]++;

            if(freq[nums[end]]==1) //koi pehli baar aaye
            count++;

            //Increse the window size
            //decresae the window size
            while(count==k){
                total+=n-end;
                freq[nums[start]]--;
                if(freq[nums[start]]==0)
                count--;
                start++;
            }
            end++;
        }

        //code of (K+1) times
        start=0,end=0,count=0;
        freq.clear();
        k++;
         while(end<n){
            freq[nums[end]]++;

            if(freq[nums[end]]==1) //koi pehli baar aaye
            count++;

            //Increse the window size
            //decresae the window size
            while(count==k){
                total-=n-end;
                freq[nums[start]]--;
                if(freq[nums[start]]==0)
                count--;
                start++;
            }
            end++;
        }
    return total;
    }
};