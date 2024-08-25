class Solution{
public:	

	vector<int> bracketNumbers(string S)
	{
	    // Your code goes here
	    int count=0;
	    stack<int>st;
	    vector<int>ans;
	    
	    for(int i=0;i<S.size();i++){
	        //opening bracket
	        if(S[i]=='('){
	            count++;
	            st.push(count);
	            ans.push_back(count);
	        }
	        //closing bracket
	        else if(S[i]==')'){
	            ans.push_back(st.top());
	            st.pop();
	        }
	    }
	    return ans;
	}
};