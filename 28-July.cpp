//Function to find the lowest common ancestor in a BST.
class Solution{
    public:
        Node* LCA(Node *root, int n1, int n2)
        {
            // code here
        if(!root)
        return NULL;
        while(1){
            if(root->data < n1 && root->data < n2)
                root = root->right;
            else if(root->data > n1 && root->data > n2)
                root = root->left;
            else
                return root;
        }
        return NULL;
        }

};
