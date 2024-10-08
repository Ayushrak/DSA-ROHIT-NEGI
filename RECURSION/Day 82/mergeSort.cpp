#include<iostream>
#include<vector>
using namespace std;

void merge(int arr[],int start,int mid,int end){
    vector<int>temp(end-start+1);
    int left = start,right = mid+1,index=0;
    while(left<=mid && right<=end){

        if(arr[left]<=arr[right]){
            temp[index]=arr[left];
            index++, left++;
        }
        else{
            temp[index]= arr[right];
            index++,right++;
        }
    }


    //left array is not empty
    while(left<=mid){
        temp[index]= arr[left];
        index++,left++;
    }
    //right array is not empty
    while(right<=end){
        temp[index]=arr[right];
        index++,right++;
    }

    //put these value in array
    index=0;
    while(start<=end){
        arr[start] = temp[index];
        start++,index++;
    }
}

void mergeSort(int arr[],int start,int end){
    int mid = start + (end-start)/2;

    if(start==end)
        return;

    //left side
    mergeSort(arr,start,mid);
    //right side
    mergeSort(arr,mid+1,end);
   // merge both sides

    merge(arr,start,mid,end);
}


int main(){
    int arr[] = {6,3,1,2,8,9,10,7,3,10};
    mergeSort(arr,0,9);
    for(int i=0;i<10;i++){
        cout<<arr[i]<<" ";
    }
}