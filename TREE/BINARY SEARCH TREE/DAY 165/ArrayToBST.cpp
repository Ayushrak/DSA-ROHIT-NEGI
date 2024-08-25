#include<iostream>
#include<vector>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int d){
        data=d;
        left=NULL;
        right=NULL;
    }
};

//preorder
class Solution {
public:
    void ArrayToBST(vector<int>&arr,int start,int end,vector<int>&ans){
        if(start>end)
        return;
        
        int mid = start +(end-start)/2;
        ans.push_back(arr[mid]);
        //left side
        ArrayToBST(arr,start,mid-1,ans);
        //right side
        ArrayToBST(arr,mid+1,end,ans);
    }
    
    vector<int> sortedArrayToBST(vector<int>& nums) {
        // Code here
        vector<int>ans;
        ArrayToBST(nums,0,nums.size()-1,ans);
        return ans;
    }
};