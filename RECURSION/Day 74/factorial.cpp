#include<iostream>
using namespace std;

int Factorial(int n){
    if(n==1 || n== 0){
        return 1;
    }
    else if(n<0){
        cout<<"not eligible";
        return 0;
    }
    return n * Factorial(n-1);
}

int main(){
    int n;
    cin>>n;
    int d = Factorial(n);
    cout<<d;
}