#include<iostream>
using namespace std;

void Birthday(int n){
   
     if(n==0){
        cout<<"HAPPY BIRTHDAY";
        return;
     }
        cout<< n << " "<<"Days left to birthday"<<endl;
    Birthday(n-1);
}

int main(){
    int n;
    cin>>n;
    Birthday(n);
}