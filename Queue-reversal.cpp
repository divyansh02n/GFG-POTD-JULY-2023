//Function to reverse the queue.
class Solution
{
    public:
    queue<int> rev(queue<int> q)
    {
        // add code here.
        vector<int>v;
        while(!q.empty())
        {
            v.push_back(q.front());
            q.pop();
        }
        int n = v.size();
        for(int i = n-1; i >= 0; i--)
        {
            q.push(v[i]);
        }
        return q;
    }    
};