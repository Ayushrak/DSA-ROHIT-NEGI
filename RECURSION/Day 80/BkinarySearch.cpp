#include<iostream>
using namespace std;

bool BinarySearch(int arr[],int start,int end,int X,int n){
    int mid = start + (end-start/2);
    
    if(start>end){
        return 0;}

    if(arr[mid]==X){
        return 1;
    }
    if(arr[mid]>X){
        BinarySearch(arr,start,mid-1,X,n);
    }
    else{
        BinarySearch(arr,mid+1,end,X,n);
    }

}

int main(){
    int arr[] ={1,2,3,4,5,6};
    cout<<BinarySearch(arr,0,5,8,5);

}