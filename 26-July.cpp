//User function Template for C++
/*
Structure of the node of the binary tree is as
struct Node
{
	int data;
	struct Node *left, *right;
};
*/
// your task is to complete this function
int kthAncestor(Node *root, int k, int node)
{
    // Code here
    map <int,int> m;
    queue <Node*> q;
    q.push(root);
    int find,ans;
    
    while(q.front()->data != node){
        if(q.front()->left){
            q.push(q.front()->left);
            m[q.front()->left->data] = q.front()->data;
        }
        if(q.front()->right){
            q.push(q.front()->right);
            m[q.front()->right->data] = q.front()->data;
        }
        q.pop();
    }
    
    find = q.front()->data;
    for(int i = 0; i<k; i++){
        if(m.find(find) == m.end()) return -1;
        ans = m[find];
        find = ans;
    }
    return ans;
}
