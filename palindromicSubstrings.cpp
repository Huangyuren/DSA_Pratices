// Please compare with other palindrome problems and see different tracking goals
class Solution {
public:
    int countSubstrings(string s) {
        if(s.empty()) return 0;
        int n = s.size();
        int res = n; // diagonal elements are palindromes
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int i=n-1; i>=0; i--){
            dp[i][i] = 1;
            for(int j=i+1; j<n; j++){
                if(s[i] == s[j] && (j-i < 2 || dp[i+1][j-1] > 0)){
                    dp[i][j] = dp[i+1][j-1]+2;
                    res++;
                }
            }
        }
        
        return res;
    }
};
