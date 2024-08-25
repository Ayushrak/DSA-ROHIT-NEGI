//1ST METHOD used for dense graph in which no of edged is ddouble of the vertices;
T.C =>O(N2);
S.C => O(1);
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        vector<bool>Explored(V,0);
        vector<int>dist(V,INT_MAX);
        dist[S] = 0;
        
        
        //select a node which is not explored yet  ist value is minimum
        
        int count = V;
        while(count--){
        int node = -1 , value = INT_MAX;
        for(int i=0;i<V;i++)
        {
            if(!Explored[i]&&value>dist[i])
            {
                node = i;
                value = dist[i];
            }
        }
        Explored[node] =1;
        
        //Relax the edges
        for(int j=0;j<adj[node].size();j++)
        {
            int neighbour = adj[node][j][0];
            int weight = adj[node][j][1];
            
            if(!Explored[neighbour] && (dist[node]+weight<dist[neighbour]))
            dist[neighbour] = dist[node] + weight;
        }
        }
        return dist;
    }
};

//2nd method is priority_queue of them

class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        vector<bool>Explored(V,0);
        vector<int>dist(V,INT_MAX);
        dist[S] = 0;
        priority_queue<pair<int,int>,vector<pair<int,int> > , greater<pair<int,int>> >p;
        p.push({0,S});
       
       
       
       while(!p.empty()){
           int node = p.top().second;
           p.pop();
           if(Explored[node]==1)
           continue;
           
          Explored[node] =1;
        //Relax the edges
        for(int j=0;j<adj[node].size();j++)
        {
            int neighbour = adj[node][j][0];
            int weight = adj[node][j][1];
            
            if(!Explored[neighbour] && (dist[node]+weight<dist[neighbour])){
                dist[neighbour] = dist[node] + weight;
                p.push({dist[neighbour],neighbour});
            }
       }
       }    
        return dist;
    }
};