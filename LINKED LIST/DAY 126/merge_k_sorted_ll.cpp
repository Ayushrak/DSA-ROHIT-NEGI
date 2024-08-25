//{ Driver Code Starts
// C++ program to merge k sorted arrays of size n each
#include <bits/stdc++.h>
using namespace std;

// A Linked List node
struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};

/* Function to print nodes in a given linked list */
void printList(Node* node)
{
	while (node != NULL)
	{
		printf("%d ", node->data);
		node = node->next;
	}
	cout<<endl;
}

// } Driver Code Ends
/*Linked list Node structure

struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};
*/ 

class Solution{
  public:
  
     Node * merge(Node *head1, Node* head2)
{
    Node *head = new Node(0);
    Node * tail = head;
    
    
    while(head1&&head2)
    {
       if(head1->data <= head2->data)
       {
           tail->next = head1;
           head1=head1->next;
           tail=tail->next;
           tail->next=NULL; 
       }
       else{
           
           tail->next = head2;
           head2=head2->next;
           tail=tail->next;
           tail->next=NULL;
       }
    }
    
    if(head1)
    tail->next=head1;
    else
    tail->next = head2;
    return head->next;
}
    //Function to merge K sorted linked list.
    Node * mergeKLists(Node *arr[], int K)
    {
           // Your code here
           Node *head=arr[0];
           for(int i=0;i<K;i++)
           {
               head = merge(head,arr[i]);
               
           };
           
           return head;
    }
};



//{ Driver Code Starts.
// Driver program to test above functions
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
	   int N;
	   cin>>N;
       struct Node *arr[N];
       for(int j=0;j<N;j++)
        {
           int n;
           cin>>n;

           int x;
           cin>>x;
           arr[j]=new Node(x);
           Node *curr = arr[j];
           n--;

           for(int i=0;i<n;i++)
           {
               cin>>x;
               Node *temp = new Node(x);
               curr->next =temp;
               curr=temp;
           }
   		}
   		Solution obj;
   		Node *res = obj.mergeKLists(arr,N);
		printList(res);

   }

	return 0;
}

// } Driver Code Ends



class Solution
{
    public:
    
   
    Node *copyList(Node *head)
    {
        //Write your code here
        Node *headCopy = new Node(0);
        Node *tailCopy = headCopy;
        Node *temp = head;
        
        while(temp){
            tailCopy->next = new Node(temp->data);
            tailCopy = tailCopy->next;
            temp = temp->next;
        }
        
        tailCopy = headCopy;
        headCopy = headCopy->next;
        delete tailCopy;
        tailCopy = headCopy;
        temp = head;
    
    Node *curr1 = head,*curr2 = headCopy;
    Node *front1, *front2;
    
    while(curr1){
        front1 = curr1->next;
        front2 = curr2->next;
        curr1->next = curr2;
        curr2->next = front1;
        curr1 = front1;
        curr2 = front2;
    }
    
    //Assign random pointer to clone it
    curr1 = head;
    while(curr1)
    {
        curr2 = curr1->next;
        if(curr1->arb)
        curr2->arb = curr1->arb->next;
        curr1 = curr2->next;
    }
    
    //Break the ll
    curr1 = head;
    while(curr1->next){
        front1=curr1->next;
        curr1->next = front1->next;
        curr1 = front1;
    }
    return headCopy;
    }
};