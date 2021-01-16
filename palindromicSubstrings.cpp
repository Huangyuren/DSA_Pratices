class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        bool dp[n][n];
        int ans=n;
        memset(dp, 0, sizeof(dp[0][0]) * n * n);
        // Self equals self.
        for(int i=0; i<n; i++){
            dp[i][i] = 1;
        }
        // Adjacent elements are the same.
        for(int i=1; i<n; i++){
            if(s[i-1] == s[i]){
                dp[i-1][i] = 1;
                ans++;
            }
        }
        // Palindromes length starting at 3 and so on.
        for(int i=3; i<=n; i++){
            for(int j=0; j <= n-i; j++){
                if(s[j] == s[j+i-1] && dp[j+1][j+i-2]){
                    ans++;
                    dp[j][j+i-1] = 1;
                }
            }
        }
        return ans;
    }
};
