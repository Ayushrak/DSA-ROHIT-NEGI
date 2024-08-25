#include<iostream>
using namespace std;

int Square(int n){
    if(n==1 ){
        return 1;
    }
    else if(n<= 0){
        cout<<"not eligible";
        return 0;
    }
    return n*n + Square(n-1);
}

int main(){
    int n;
    cin>>n;
    int d = Square(n);
    cout<<d;
}