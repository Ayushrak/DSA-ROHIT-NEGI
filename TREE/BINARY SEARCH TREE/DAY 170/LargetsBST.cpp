#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

class Solution{
    public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    
    class Box{
        public:
        bool BST;
        int size;
        int min,max;
        
        Box(int data){
            BST =1;
            size = 1;
            min  = data;
            max = data; 
        }
    };
    
    Box *find(Node *root, int &TotalSize){
        
        //leaf node
        if(!root->left&&!root->right)
        {
            TotalSize = max(TotalSize,1);
            return  new Box(root->data);
            
        }
        //only right side exists
        else if(!root->left&&root->right){
            Box *head = find(root->right,TotalSize);
            //BST YES
            if(head->BST&&head->min>root->data){
                head->size++;
                head->min = root->data;
                TotalSize = max(TotalSize,head->size);
                return head;
            }
            else{
                head->BST =0;
                return head;
            }
        }
        //only left side exists
        else if(!root->right&&root->left){
            Box *head = find(root->left,TotalSize);
            //BST YES
            if(head->BST&&head->max<root->data){
                head->size++;
                head->max = root->data;
                TotalSize = max(TotalSize,head->size);
                return head;
            }
            else{
                head->BST =0;
                return head;
            }
        }
        //Both side exists
        else{
            Box *LeftHead = find(root->left,TotalSize);
            Box *RightHead = find(root->right,TotalSize);
            
            if(LeftHead->BST && RightHead->BST && LeftHead->max < root->data && RightHead->min>root->data){
                Box *head = new Box(root->data);
                head->size += LeftHead->size + RightHead->size;
                head->min = LeftHead->min;
                head->max = RightHead->max;
                TotalSize = max(TotalSize,head->size);
                return head;
            }
            else{
                LeftHead->BST = 0;
                return LeftHead;
            }
        }
    }
    
    int largestBst(Node *root)
    {
    	//Your code here
    	int TotalSize = 0;
    	find(root,TotalSize);
    	return TotalSize;
    }
};

//2ND METHOD
class Box{
    public:
    bool BST;
    int size;
    int min,max;
    
    Box(){
       BST =1;
       size = 0;
       min = INT_MAX;
       max = INT_MIN;
    }
};
class Solution{
    public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    
    Box *find(Node *root,int &TotalSize){
        //root doesn't exists
        if(!root)
        {
            return new Box();
        }
        
        //root exists
        Box *LeftHead = find(root->left,TotalSize);
        Box *RightHead = find(root->right,TotalSize);
        
        if(LeftHead->BST&&RightHead->BST&&LeftHead->max<root->data&&RightHead->min>root->data){
            Box *head = new Box();
            head->size = 1 + LeftHead->size + RightHead->size;
            head->min = min(root->data,LeftHead->min);
            head->max = max(root->data,RightHead->max);
            TotalSize = max(TotalSize,head->size);
            return head;
        }
        else{
            LeftHead->BST = 0;
            return LeftHead;
        }
    }
    
    int largestBst(Node *root)
    {
    	//Your code here
    	int TotalSize = 0;
    	find(root,TotalSize);
    	return TotalSize;
    }
};