class Solution
{
  public:
    vector<int> findOrder(int N, int P, vector<vector<int>> prerequisites) 
    {
        //code here
        vector<int>adj[N];
        vector<int>InDeg(N,0);
        
        for(int i=0;i<P;i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            InDeg[prerequisites[i][0]]++;
        }
        
        //Kahn Algorithm
        //Indegree find karna
        
        queue<int>q;
        for(int i=0;i<N;i++)
        if(!InDeg[i])
        q.push(i);
        vector<int>ans;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
            
            //Look at the neighbour
            for(int i=0;i<adj[node].size();i++){
                InDeg[adj[node][i]]--;
                if(!InDeg[adj[node][i]])
                q.push(adj[node][i]);
            }
        }
        vector<int>temp;
        return ans.size()==N ? ans : temp;
    }
};