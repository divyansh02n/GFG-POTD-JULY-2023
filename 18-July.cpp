
	class Solution {
	public:
		int LongestRepeatingSubsequence(string str){
		    // Code here
		    int n = str.size(), i, j;
		    vector<vector<int>> t(n+1, vector<int>(n+1, 0));
		    for(i=1;i<n+1;i++){
		        for(j=1;j<n+1;j++){

		            if(str[i-1]==str[j-1] and i!=j)
		                t[i][j] = 1 + t[i-1][j-1];
		            else
		                t[i][j] = max(t[i][j-1], t[i-1][j]);
		        }
		    }
		    return t[n][n];
		}



};
