// Nice and neat dp solution
class Solution {
public:
    int numDecodings(string s) {
        if(s[0] == '0') return 0;
        int n = s.size();
        vector<int> dp(n+1, -1); // We will always visite s[n] no matter recursive or dp, special part
        dp[n] = 1; // initialization
        for(int i=n-1; i>=0; i--){
            if(s[i] == '0'){
                dp[i] = 0;
                continue;
            }
            dp[i] = dp[i+1]; // previous case, regards as s[pos+1], basecase
            if(i < n-1 && (s[i]=='1' || (s[i]=='2'&&s[i+1]<'7'))){
                dp[i] += dp[i+2];
            }
        }
        return dp[0];
    }
};
