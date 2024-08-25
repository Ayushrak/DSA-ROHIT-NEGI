#include<iostream>
using namespace std;

void func(int n){
    //Base Case
    if(n==0){
        return;
    }
    
    cout<<"CODER ARMY"<<endl;
    func(n-1);
}

int main(){
    int n;
    cin>>n;
    func(n);
    return 0;
}
