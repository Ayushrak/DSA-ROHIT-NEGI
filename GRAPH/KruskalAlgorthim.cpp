int FindParent(int u ,vector<int>&parent){
	    if(u==parent[u])
	    return u;
	    
	    return parent[u] = FindParent(parent[u],parent); //path compression
	}
	
	void UnionByRank(int u ,int v, vector<int>&parent,vector<int>&rank){
	    int pu = FindParent(u,parent);
	    int pv = FindParent(v,parent);
	    
	    if(rank[pu] > rank[pv]){
	        parent[pv] = pu;
	    }
	    else if(rank[pu] < rank[pv])
	    {
	        parent[pu] = pv;
	    }
	    else{
	        parent[pv] = pu;
	        rank[pu]++;
	    }
	}
	
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        vector<int>parent(V); //ultimate parent will help to determine set
        vector<int>rank(V,0);
        for(int i=0;i<V;i++)
        parent[i]=i;
        
        //Priority Queue
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        for(int i=0;i<V;i++){
            for(int j=0;j<adj[i].size();j++)
            {
                pq.push({adj[i][j][1],{i,adj[i][j][0]}});
            }
        }
        
        int cost=0;
        int edges=0;
        while(!pq.empty()){
            int wt = pq.top().first;
            int u = pq.top().second.first;
            int v = pq.top().second.second;
            pq.pop();
            
            //check id they are in different set;
            if(FindParent(u,parent)!=FindParent(v,parent))
            {
                cost+=wt;
                UnionByRank(u,v,parent,rank);
                edges++;
            }
            
            if(edges==V-1)
            break;
        }
        return cost;
    }