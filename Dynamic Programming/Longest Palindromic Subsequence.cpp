class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        int dp[n][n];
        memset(dp,0,sizeof(dp));
        
        for(int i = 0; i < n; i++) dp[i][i] = 1;
        
        for(int i = 1; i < n; i++){
            for(int j = 0, k = 0; j < n-i; j++){
                k = j+i;
                if( s[j] == s[k] )
                    dp[j][k] = dp[j+1][k-1]+2;
                else
                    dp[j][k] = max(dp[j][k-1],dp[j+1][k]);
            }
        }
        
        return dp[0][n-1];
    }
};
