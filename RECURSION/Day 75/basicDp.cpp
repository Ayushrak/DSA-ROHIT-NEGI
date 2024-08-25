class Solution{
    public:
    long long countWays(int n){
        int mod = 1000000007;
        long long dp[n+1];
        dp[0] = 1;
        
        for(int i=1;i<n+1;i++) 
            dp[i] = 0;
            
        for(int i=1;i<n+1;i++){
            dp[i] += dp[i-1]%mod;
            
            if(i>1)
                dp[i] += dp[i-2]%mod;
            if(i>2)
                dp[i] += dp[i-3]%mod;
        }
        return dp[n]%mod;
    }
};