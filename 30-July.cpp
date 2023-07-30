/*The structure of Node

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

class Solution{
  public:
    // returns the inorder successor of the Node x in BST (rooted at 'root')
    Node * inOrderSuccessor(Node *root, Node *x)
    {
        Node *ans = nullptr;
        bool flag = false;
        trav(root, x, flag, ans);
        return ans;
    }
    
    void trav(Node *node, Node *k, bool &next, Node* &ans) {
        if(node->left) trav(node->left, k, next, ans);
        if(next) ans = node, next = false;
        if(node->data == k->data) next = true;
        if(node->right) trav(node->right, k, next, ans);
    }
};
