class Solution {
public:
	bool isPossible(int N,int P, vector<pair<int, int> >& prerequisites) {
	    // Code here
	    //Adjacency list create karo
	    vector<int>adj[N];
	    vector<int>InDeg(N,0);
	    for(int i=0;i<P;i++){
	        adj[prerequisites[i].second].push_back(prerequisites[i].first);
	        InDeg[prerequisites[i].first]++;
	    }
	    
	    //kahn Algorithm
	    //Indegree find karna
	    
	    queue<int>q;
	    for(int i=0;i<N;i++)
	    if(!InDeg[i])
	    q.push(i);
	   
	   int count=0;
	    while(!q.empty()){
	        int node = q.front();
	        q.pop();
	        count++;
	        
	        
	        //Look at the neighbour
	        for(int i=0;i<adj[node].size();i++){
	            InDeg[adj[node][i]]--;
	            if(!InDeg[adj[node][i]])
	            q.push(adj[node][i]);
	        }
	    }
	    
	   return count==N; 
	}
};