#include<bits/stdc++.h>
using namespace std;


//undirected unweighted graph
int main(){
    int vertex,edges;
    cin>>vertex>>edges;

    vector<int> adj[vertex];
   int u,v;
   for(int i=0;i<edges;i++){
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
   }

   for(int i=0;i<vertex;i++){
    cout<<i<<"->";
    for(int j=0;j<adj[i].size();j++){
        cout<<adj[i][j]<<" ";
    }
    cout<<endl;
   }
}

//undirectrd weighted graph


int main(){
    int vertex,edges;
    cin>>vertex>>edges;

    vector<pair<int,int>> adj[vertex];
   int u,v,w;
   for(int i=0;i<edges;i++){
    cin>>u>>v>>w;
   adj[u].push_back(make_pair(v,w));
   adj[v].push_back(make_pair(u,w));
   }

   for(int i=0;i<vertex;i++){
        cout<<i<<" -> ";
        for(int j=0;j<adj[i].size();j++){
            cout<<adj[i][j].first<<" "<<adj[i][j].second<<" ";
        }
        cout<<endl;
   }
}

//directed weighted graph

 int main(){

     int vertex,edges;
     cin>>vertex>>edges;

     vector<pair<int,int>> adj[vertex];
    int u,v,w;
    for(int i=0;i<edges;i++){
     cin>>u>>v>>w;
    adj[u].push_back(make_pair(v,w));
    }

    for(int i=0;i<vertex;i++){
         cout<<i<<" -> ";
         for(int j=0;j<adj[i].size();j++){
             cout<<adj[i][j].first<<" "<<adj[i][j].second<<" ";
         }
         cout<<endl;
    }
 }