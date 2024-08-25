#include<iostream>
using namespace std;

void func(int n){
    //Base Case
    if(n==1){
        cout<<"1"<<endl;
        return;
    }
    if(n%2!=0){
        cout<<n<<endl;
        func(n-2);
    }
    else{
        func(n-1);
    }
}

int main(){
    int n;
    cin>>n;
    func(n);
    return 0;
}