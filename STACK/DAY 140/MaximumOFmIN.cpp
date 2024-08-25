#include<iostream>
using namespace std;

//brute force approach 
// T.C -> O(n^3)
class Solution
{
    public:
    //Function to find maximum of minimums of every window size.
    vector <int> maxOfMin(int arr[], int n)
    {
        // Your code here
        vector<int>ans(n,0);
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n-i;j++){
                int num = INT_MAX;
                for(int k=j;k<i+j+1;k++){
                    num = min(num,arr[k]);
                }
                ans[i] = max(ans[i],num);
            }
        }
        return ans;
    }
};


class Solution
{
    public:
    //Function to find maximum of minimums of every window size.
    vector <int> maxOfMin(int arr[], int n)
    {
        // Your code here
        vector<int>ans(n,0);
        stack<int>st;
        
        for(int i=0;i<n;i++)
        {
            //value kab tak pop hgi
            //NSR MSL
            while(!st.empty() && arr[st.top()]>arr[i]){
                int index = st.top();
                st.pop();
                //I= NEXT SMALLEST RIGHT
                //stack ke andar jo index ,NSL
                //range={windowSize}
                if(st.empty())
                {
                    int range = i;
                    ans[range-1] = max(ans[range-1],arr[index]);
                }                
                else{
                    int range = i-st.top()-1;
                    ans[range-1] = max(ans[range-1],arr[index]);
                }
            }
            st.push(i);
        }
     
        
        
        //Stack element ko kaali kharo
         while(!st.empty()){
                int index = st.top();
                st.pop();
                //I= NEXT SMALLEST RIGHT
                //stack ke andar jo index ,NSL
                //range={windowSize}
                if(st.empty())
                {
                    int range = n;
                    ans[range-1] = max(ans[range-1],arr[index]);
                }                
                else{
                    int range = n-st.top()-1;
                    ans[range-1] = max(ans[range-1],arr[index]);
                }
            }
        
        
        //ans value ko update kar do
        for(int i=n-2;i>=0;i--)
        ans[i] = max(ans[i],ans[i+1]);
        return ans;
    }
};