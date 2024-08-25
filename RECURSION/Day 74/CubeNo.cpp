#include<iostream>
using namespace std;

int cube(int n){
    if(n==1){
        return n;
    }
        return  n*n*n + cube(n-1);        
}

int main(){
    int n;
    cin>>n;
    cout<<cube(n);
}