class Solution
{
    public:
    //Function to return list containing elements of right view of binary tree.
    vector<int> rightView(Node *root)
    {
       // Your Code here
       vector<int> v;
       queue<Node *> q;
       q.push(root);
       while(!q.empty()){
           int count=q.size();
           for(int i=0;i<count;i++){
               Node *cur=q.front();
               q.pop();
               if(i==count-1){
                   v.push_back(cur->data);
                   }
                   if(cur->left!=NULL){
                       q.push(cur->left);
                   }
                   
                   if(cur->right!=NULL){
                       q.push(cur->right);
                   }
           }
       }
       return v;
    }
};
