#include<iostream>
using namespace std;

void GCD(int A ,int B){
    if(B==0){
        cout<<A ;
        return;
    }
    GCD(B,A%B);
}

int main(){
    int A;
    int B;
    cin>>A>>B;
    GCD(A,B);
}
/*
EX-> (18,48)
(48,18);
(18,12);
(12,6);
(6,0);
*/