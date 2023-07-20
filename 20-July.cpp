char nonrepeatingCharacter(string S)
    {
       //Your code here
       unordered_map<char,int> mpp;
       for(int i=0;i<S.size();i++){
           mpp[S[i]]++;
       }
       
       
       for(auto it : S){
           if(mpp[it]==1) return it;
       }
       return '$';
    }
