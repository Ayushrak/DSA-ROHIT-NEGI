class Solution{
public:
    //Function to count subarrays with sum equal to 0.
    long long int findSubarray(vector<long long int> &arr, int n ) {
        //code here
        long long total = 0;
        //map
        unordered_map<long long int, long long int>m;
        long long int PrefixSum = 0;
        //initalise 0 with 1
        m[0] = 1;
        for(int i=0;i<n;i++){
            PrefixSum += arr[i];
            if(m.count(PrefixSum)){
                total+=m[PrefixSum]; //count of PrefixSum 
                m[PrefixSum]++; //PrefixSum increses
            }
            else{
                m[PrefixSum] = 1;
            }
        }
        return total;
    }
};