#include<iostream>
using namespace  std;

int sum(int arr[],int index, int n){
    if(arr[index]==n){
        return arr[index];
    }
    return arr[index] + sum(arr,index+1,n);
}

int main(){
    int arr[] ={1,2,3,4,5,6};
    cout<<sum(arr,0,6);
}
