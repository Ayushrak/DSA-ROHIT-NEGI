#include<bits/stdc++.h>
using namespace std;
#include<vector>
#include<queue>


//DFS GRAPH
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool DetectCycle(int node,int parent,vector<int>adj[],vector<bool>&visited){
        visited[node]=1;
        
        for(int i=0;i<adj[node].size();i++){
            if(parent==adj[node][i])
            continue;
            if(visited[adj[node][i]]==1)
            return 1;
            if(DetectCycle(adj[node][i],node,adj,visited))
            return 1;
        }
        return 0;
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<bool>vis(V,0);
        for(int i=0;i<V;i++){
            if(!vis[i] && DetectCycle(i,-1,adj,vis))
            return 1;
        }
        return 0;
    }
};

// BFS GRAPH
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool BFS(vector<int> adj[], vector<bool>& visited, int start) {
        queue<pair<int, int>> q;
        visited[start] = true;
        q.push(make_pair(start, -1));
        
        while (!q.empty()) {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            
            for (int j = 0; j < adj[node].size(); j++) {
                int neighbor = adj[node][j];
                
                if (neighbor == parent)
                    continue;
                
                if (visited[neighbor])
                    return true;
                
                visited[neighbor] = true;
                q.push(make_pair(neighbor, node));
            }
        }
        return false;
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        vector<bool> visited(V, false);
        
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (BFS(adj, visited, i))
                    return true;
            }
        }
        return false;
    }
};