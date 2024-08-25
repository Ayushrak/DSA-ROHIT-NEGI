#include<bits/stdc++.h>
using namespace std;
#include<vector>
#include<queue>


class Solution{
    public:
    string findOrder(string dict[], int N, int K) {
        //code here
        vector<int>adj[K];
        vector<int>InDeg(K,0);
        for(int i=0;i<N-1;i++)
        {
            string str1 = dict[i] ,str2 =  dict[i+1];
            int j=0 , k=0;
            
            while(j<str1.size()&&k<str2.size() && str1[j]==str2[k])
                j++ ,k++; // means both string element sane
                
                if(j==str1.size()) //cdc cddc
                continue;
                
                adj[str1[j]-'a'].push_back(str2[k]-'a'); // convert also into strking which is different
                InDeg[str2[k]-'a']++;
        }
        
        queue<int>q;
        for(int i=0;i<K;i++)
        if(!InDeg[i])
        q.push(i);
       string ans;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
           char c = 'a' + node;
           ans+=c;
            
            //Look at the neighbour
            for(int i=0;i<adj[node].size();i++){
                InDeg[adj[node][i]]--;
                if(!InDeg[adj[node][i]])
                q.push(adj[node][i]);
            }
        }
        return ans;
    }
};

int main(){

}