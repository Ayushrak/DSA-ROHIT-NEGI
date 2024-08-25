class Solution {
  public:
    /*  Function to implement Bellman Ford
    *   edges: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        // Code here
        vector<int>dist(V,1e8);
        dist[S] = 0;
        int e = edges.size();
        
        
        //relax all the edges V-1 TIMES
        for(int i=0;i<V-1;i++){
            bool flag = 0;
            for(int j=0;j<e;j++){
                
               int u = edges[j][0];
               int v = edges[j][1];
               int w = edges[j][2];
               
               if(dist[u]==1e8)
               continue;
               
               if(dist[u] + w < dist[v]){
               flag=1;
               dist[v] = dist[u] + w;
               }
            }
            if(!flag)
            return dist;
        }
        
        // negative edge cycle;
        for(int i=0;i<V-1;i++){
            for(int j=0;j<e;j++){
                
                
               int u = edges[j][0];
               int v = edges[j][1];
               int w = edges[j][2];
               
               if(dist[u]==1e8)
               continue;
               
                if(dist[u] + w < dist[v]){
                    vector<int>ans;
                    ans.push_back(-1);
                    return ans;
                }
            }
        }
        return dist;
    }
};