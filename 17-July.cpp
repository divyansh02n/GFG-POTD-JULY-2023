
class Solution {
public:
string FirstNonRepeating(string A){
    // Code here
    string s;
    map<char, int> mp;
    int i = 0, j = 0;
    while(j < A.size())
    {
            mp[A[j]]++;
            while(mp[A[i]] != 1 && i < j) i++;
            if(mp[A[j]] != 1 && i == j) s+='#';
            else s+=A[i];
            j++;
    }
    return s;
}
 
};
