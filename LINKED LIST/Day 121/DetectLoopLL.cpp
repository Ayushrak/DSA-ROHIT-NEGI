#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

        // for O(n2) time complexity
 bool check(vector<Node*>&visited,Node *curr)
    {
        for(int i=0;i<visited.size();i++){
            
            if(visited[i]==curr)
            return 1;
        }
        return 0;
    }
    bool detectLoop(Node* head)
    {
        // your code here
        Node *curr = head;
        vector<Node*>visited;
        
        while(curr!=NULL){
            
            if(check(visited,curr))
            return 1;
            
            
            visited.push_back(curr);
            curr = curr->next;
        };
    }


    //for O(n) time complexity
    //O(n) -> space complexity
    bool detectLoop(Node* head)
    {
        // your code here
        Node *curr = head;
        
        unordered_map<Node*,bool>visited;
        
        while(curr!=NULL){
            
            if(visited[curr]==1)
            return 1;
            
            
            visited[curr]=1;
            curr = curr->next;
        };
        return 0;
    }

    // for time complexity -> O(n);
    // for space complexity -> O(1);
//use slow and fast pointer


    bool detectLoop(Node* head)
    {
        // your code here
        Node *slow = head;
        Node *fast = head;
        
        
        while(fast !=NULL && fast->next !=NULL){
            
            slow = slow->next;
            fast = fast->next->next;
            
            
            if(slow == fast)
            return 1;
        }
        return 0;
    }

