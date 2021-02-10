// Can be modified from substring problem
// O(n^2) solution that traverse all possibilities starting from index
// i and till the end of s.
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        if(n==0) return 0;
        if(n==1) return 1;
        int counter = 0;
        int res = INT_MIN;
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int i=n-1; i>=0; i--){
            dp[i][i] = 1;
            for(int j=i+1; j<n; j++){
                if(s[i]==s[j]){
                    dp[i][j] = dp[i+1][j-1] + 2;
                }
                else
                {
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
                }
            }
        }
        return dp[0][n-1];
    }
};
