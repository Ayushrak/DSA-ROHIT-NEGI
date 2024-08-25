#include<iostream>
#include<queue>
using namespace std;

class Node{
public:
    int data;
    Node *left;
    Node *right;
    Node(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
};

int main(){
    int x;
    cout << "Enter the root node" << ":";
    cin >> x;
    if (x == -1) {
        cout << "Invalid input for root node." << endl;
        return 1;
    }
    int first, second;
    queue<Node*> q;
    Node *root = new Node(x);
    q.push(root);

    // Build binary tree
    while(!q.empty()){
        Node *temp = q.front();
        q.pop();
        cout << "Enter the left child of " << temp->data << ":";
        cin >> first; // left side
        if (first != -1) {
            temp->left = new Node(first);
            q.push(temp->left);
        }
        cout << "Enter the right child of " << temp->data << ":";
        cin >> second; // right side
        if (second != -1) {
            temp->right = new Node(second);
            q.push(temp->right);
        }
    } 
 }

