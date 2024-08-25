 void DFS(int node,vector<int>adj[],vector<bool>&visited){
            visited[node]=1;
        for(int j=0;j<adj[node].size();j++){
            if(!visited[adj[node][j]])
            DFS(adj[node][j],adj,visited);
        }
    }
    
	int isEulerCircuit(int V, vector<int>adj[]){
	    // Code here
	     
	    // Euler Circuit : 2
	    //Calculate  the Degree of each node
	    // All node should have even degree
	    // All non-zero degree node should be converted;
	    
	    
	    //Euler path : 1
	    // calcuate the degree of each node;
	    //zero or two  node can hqave odd degree and remaining node should have even degree
	    // ALl non zero degree node should be connected;
	    
	    vector<int>Deg(V,0);
	    int Odd_Deg = 0; // no of nodes of odd degree
	    for(int i=0;i<V;i++){
	        Deg[i] = adj[i].size(); n
	        Odd_Deg++;
	    }
	    
	    if(Odd_Deg!=2 && Odd_Deg!=0)
	    return 0;
	    
	    vector<bool>visited(V,0);
	    
	    for(int i=0;i<V;i++){
	        if(Deg[i])
	        {
	            DFS(i,adj,visited);
	            break;
	        }
	    }
	    
	    // If non zero degree is still not visited, retrun 0;
	    //Degree zero hai, usko ignore (Koi edge nahi hai)
	    
	    for(int i=0;i<V;i++){
	        if(Deg[i]&&!visited[i])
	        return 0;
	    }
	    
	    //Eulerian circuit: 2
	    //Eulerian path : 1
	    
	    if(Odd_Deg==0)
	    return 2;
	    else
	    return 1;
	}