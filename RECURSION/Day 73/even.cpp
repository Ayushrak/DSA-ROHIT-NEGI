#include<iostream>
using namespace std;

void even(int n){
    if(n==2){
        cout<<"2"<<endl;
        return;
    }
    even(n-2);
    cout<<n<<endl;
}

int main(){
    int N;
    cin>>N;
    if(N%2==1)
    N--;
    even(N);
}