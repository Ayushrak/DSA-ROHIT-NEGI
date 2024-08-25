#include<bits/stdc++.h>
using namespace std;
#include<vector>
#include<queue>


class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    
    void DFS(int node,vector<int>adj[],vector<int>&ans,vector<bool>&visited){
        visited[node]=1;
        ans.push_back(node);
        
        for(int i=0;i<adj[node].size();i++){
            if(!visited[adj[node][i]])
            DFS(adj[node][i],adj,ans,visited);
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<bool>visited(V,0);
        vector<int>ans;
        DFS(0,adj,ans,visited);
        return ans;
    }
};