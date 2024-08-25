#include<bits/stdc++.h>
using namespace std;
#include<vector>
#include<queue>

class Solution
{
	public:
	//KAHN ALGORITHIM
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<int>ans;
	    vector<int>InDeg(V,0);
	    
	    //store the indegree
	    for(int i=0;i<V;i++)
	        for(int j=0;j<adj[i].size();j++)
	            InDeg[adj[i][j]]++;
	   
	   //push all zero Indegree
	   queue<int>q;
	   for(int i=0;i<V;i++)
	   if(InDeg[i]==0)
	   q.push(i);
	   
	   int node;
	   while(!q.empty()){
	       node = q.front();
	       q.pop();
	       ans.push_back(node);
	       
	       //neighbour unki indegree kam karne ke liye
	       for(int j=0;j<adj[node].size();j++){
	           InDeg[adj[node][j]]--;
	           if(InDeg[adj[node][j]]==0)
	           q.push(adj[node][j]);
	       }
	   }
	   return ans;
	}
};
