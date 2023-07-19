class Solution{
  public:
    int longestPalinSubseq(string S) {
        //code here
        string R = S;
    reverse(R.begin(), R.end());
    int dp[S.length() + 1][R.length() + 1];

    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= S.length(); i++) {
        for (int j = 1; j <= R.length(); j++) {
            if (S[i - 1] == R[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
        }
    }
    return dp[S.length()][R.length()];
    }
};
