int spanningTree(int V, vector<vector<int>> adj[]) {
    // Min-heap priority queue
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    vector<bool> IsMST(V, false);
    vector<int> parent(V, -1);
    
    int cost = 0;
    pq.push({0, {0, -1}});
    
    while (!pq.empty()) {
        int wt = pq.top().first;
        int node = pq.top().second.first;
        int par = pq.top().second.second;
        pq.pop();
        
        // If the node is not yet included in the MST
        if (!IsMST[node]) {
            // Include the node in MST
            IsMST[node] = true;
            cost += wt;
            parent[node] = par;
            
            // Check all adjacent nodes
            for (int i = 0; i < adj[node].size(); ++i) {
                int adjNode = adj[node][i][0];
                int adjWt = adj[node][i][1];
                if (!IsMST[adjNode]) {
                    // Push the adjacent node with its weight to the priority queue
                    pq.push({adjWt, {adjNode, node}});
                }
            }
        }
    }
    return cost;
}