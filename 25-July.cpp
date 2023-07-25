//Function to return a list containing the level order traversal in spiral form.
vector<int> findSpiral(Node *root)
{
    //Your code here
      bool flag=true;
    queue<Node*> q;
    vector<int> v;
    q.push(root);
    while(!q.empty()){
        int n=q.size();
        vector<int> v1;
        for(int i=0;i<n;i++){
            Node *temp=q.front();
            q.pop();
            v1.push_back(temp->data);
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
        if(!flag){
            for(int i=0;i<v1.size();i++){
                v.push_back(v1[i]);
            }
            flag=true;
        }
        else{
            for(int i=v1.size()-1;i>=0;i--){
                v.push_back(v1[i]);
            }
            flag=false;
        }
    }
    return v;
}
