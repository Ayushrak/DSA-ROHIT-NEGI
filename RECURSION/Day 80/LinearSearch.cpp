#include<iostream>
using namespace std;


bool linearSearch(int arr[],int index, int n,int X){
    if(index==n){
        return 0;
    }
    if(arr[index]==X){
        return 1;
    }
    return linearSearch(arr,index+1,n,X);
}

int main(){
    int arr[] ={1,2,3,4,5,6};
    cout<<linearSearch(arr,0,5,2);
}