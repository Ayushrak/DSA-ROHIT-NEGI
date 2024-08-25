 root->height = 1+max(height(root->left),height(root->right));
        child->height = 1+max(height(child->left),height(child->right));