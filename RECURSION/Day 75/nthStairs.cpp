#include<iostream>
using namespace std;

int nthStairs(int n){
    if(n<=1){
        return 1;
    }

    return nthStairs(n-1) +  nthStairs(n-2);
}

int  main(){
    int n;
    cin>>n;
   cout<<nthStairs(n);
    return 0;
}