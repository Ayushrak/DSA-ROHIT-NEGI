class Solution {
  public:
    void correctBST( struct Node* root )
    {
        // add code here.
        Node *curr = NULL;
        Node *first = NULL, *second = NULL;
        Node *last = NULL, *persent = NULL;
        
        while(root){
            //left doesn't exists
            if(!root->left)
            {
                last = persent;
                persent = root;
                if(last&&last->data>persent->data){
                    if(!first)
                    first=last;
                    second=persent;
                }
                root=root->right;
            }
            //left exists
            else{
                curr = root->left;
                while(curr->right&&curr->right!=root){
                    curr=curr->right;
                }
                 //Left subtree not traversed yet
                if(!curr->right){
                    curr->right = root;
                    root =root->left;
                }
                
                //Left traversal alredy Traversal
               else{
                   curr->right =NULL;
                   last = persent;
                persent= root;
                if(last&&last->data>persent->data){
                    if(!first)
                    first=last;
                    second=persent;
                }
                   root=root->right;
               }
            }
        }
        int num = first->data;
        first->data = second->data;
        second->data = num;
        
    }
};