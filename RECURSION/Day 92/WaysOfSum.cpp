#include<iostream>
#include<vector>
using namespace std;

class Solution
{
  public:
    // function to count the total  
    // number of ways to sum up to 'N' 
    int ways(int arr[],int m,int sum){
        if(sum==0)
        return 1;
        if(sum<0)
        return 0;
        
        int ans =0;
        for(int i=0;i<m;i++){
            ans += ways(arr,m,sum-arr[i]);
        }
        return ans;
    }
    
    int countWays(int arr[], int m, int N) 
    { 
      //code here.
      return ways(arr,m,N)%1000000007;
    } 
}: