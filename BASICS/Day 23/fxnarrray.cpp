#include<iostream>
using namespace std;

void func(int a[],int n){
    cout<<sizeof(a); // pointer ->8
    for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
}

int main(){
    int arr[5] ={3,2,4,5,6}; 
    cout<<sizeof(arr)<<endl;// 20
    func(arr,5);
}