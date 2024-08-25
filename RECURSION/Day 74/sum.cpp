#include<iostream>
using namespace std;

int Sum(int n){
    if(n==1 || n== 0){
        return 1;
    }
    
    return n + Sum(n-1);
}

int main(){
    int n;
    cin>>n;
    int d = Sum(n);
    cout<<d;
}