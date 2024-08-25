#include<iostream>
using namespace  std;

void print(int arr[],int index,int n){
    //Base case
    if(arr[index]==n){
        return;
    }

   cout<<arr[index]<<" ";
   print(arr,index+1,n);
}

int main(){
    int arr[] ={1,2,3,4,5,6};
    print(arr,0,6);
}