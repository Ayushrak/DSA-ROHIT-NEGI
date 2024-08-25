class Solution {
  public:
    int canRepresentBST(int arr[], int N) {
        // code here
        stack<int>lower,upper;
        lower.push(INT_MIN);
        upper.push(INT_MAX);
        int left,right;
        
        for(int i=0;i<N;i++){
            //1
            if(arr[i]<lower.top())
            return 0;
            
            //2
            while(arr[i]>upper.top()){
                upper.pop();
                lower.pop();
            }
            
            //3
            left = lower.top();
            right = upper.top();
            lower.pop();
            upper.pop();
            //right side
            lower.push(arr[i]);
            upper.push(right);
            
            //left side
            lower.push(left);
            upper.push(arr[i]);
        }
        return 1;
    }
};