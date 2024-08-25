#include<iostream>
using namespace std;

int  minElement(int arr[],int index,int n){
    if(arr[index]==n){
        return  arr[index];
    }
    return  min(arr[index],minElement(arr,index+1,n));
}

int main(){
    int arr[]={1,2,3,4,5,6};
    cout<<minElement(arr,0,5);
}