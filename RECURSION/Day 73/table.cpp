#include<iostream>
using namespace std;

void Table(int num,int n){
    if(num>n){
        return;
    }
    cout<<num<<endl;
    Table(num+3,n);
}

int main(){
    int n;
    cin>>n;
    Table(3,n);
}