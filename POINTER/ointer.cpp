#include<iostream>
using namespace std;

int main(){
    int a= 10;
    cout<<&a<<endl;
    int *ptr = &a;
   // ptr = &a;
    cout<<*ptr<<endl;
    cout<<sizeof(ptr)<<endl;
}