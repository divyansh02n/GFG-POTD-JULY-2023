/*
Structure of the binary Search Tree is as
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
// your task is to complete the Function
// Function should return median of the BST

void inorder(Node* root,vector<int>&in){
    if(root==NULL)return;
    inorder(root->left,in);
    in.push_back(root->data);
    inorder(root->right,in);
}

float findMedian(struct Node *root)
{
      //Code here
      vector<int>in;
      inorder(root,in);
      int n=in.size();
      if(n%2) return (float)in[(n)/2];
      else return (float)(in[(n)/2]+in[((n)/2)-1])/2;
}
