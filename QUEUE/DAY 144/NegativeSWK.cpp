#include<iostream>
#include<queue>
#include<vector>
using namespace std;

//this code exceed time limit
  long long display(queue<long long>p){
                while(!p.empty()){
                    if(p.front()<0){
                        return p.front();
                    }
                    p.pop();
                }
                return 0;
            }


vector<long long> PrintFirstNegativeInteger(long long int A[],
                                             long long int N, long long int K) {
            vector<long long>ans;                                
            queue<long long>q;
            
            //push k-1 element in queue;
            for(long long int i=0;i<K-1;i++){
                q.push(A[i]);
            }
            
            for(long long i=K-1;i<N;i++){
                q.push(A[i]);
                ans.push_back(display(q));
                q.pop();
            }
            return ans;
 }


 //O(n)
 vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int K) {
                
                vector<long long>ans;
                queue<long long int>q;
                
                //k-1 elements hai ko push kar d
                for(long long int i=0;i<K-1;i++){
                    if(A[i]<0)
                    q.push(i);
                }
                
                for(long long int i=K-1;i<N;i++){
                    
                    //push negative
                    if(A[i]<0)
                    q.push(i);
                    //empty
                    if(q.empty())
                    ans.push_back(0);
                    else{
                        //check the first index of queue lies inside the window
                        if(q.front()<=i-K)
                        q.pop();
                        
                        if(q.empty())
                        ans.push_back(0);
                        
                        else
                        ans.push_back(A[q.front()]);
                    }
                }
               return ans; 
 }