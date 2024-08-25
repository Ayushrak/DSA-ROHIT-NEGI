#include<bits/stdc++.h>
using namespace std;
#include<vector>
#include<queue>

class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	
	void DFS(int node,vector<int>adj[],vector<bool>&visited,stack<int>&s){
	    visited[node]=1;
	    //look st neightbour one by one
	    for(int i=0;i<adj[node].size();i++){
	        if(!visited[adj[node][i]])
	        DFS(adj[node][i],adj,visited,s);
	    }
	    s.push(node);
	}
	
	
	
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<bool>visited(V,0);
	    stack<int>s;
	    for(int i=0;i<V;i++){
	        if(!visited[i])
	        DFS(i,adj,visited,s);
	    }
	    vector<int>ans;
	    while(!s.empty()){
	        ans.push_back(s.top());
	        s.pop();
	    }
	    return ans;
	}
};