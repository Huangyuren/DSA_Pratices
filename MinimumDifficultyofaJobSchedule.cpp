class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        if(n < d) return -1;
        vector<int> dp(n+1, 1e9);
        dp[n] = 0;
        for(int i=1; i<=d; i++){ // day increasing
            for(int j=0; j<=n-i; j++){ // Repeatedly update dp[0...n-curr_day]
                int currmax = 0;
                dp[j] = 1e9;
                for(int k=j; k<=n-i; k++){
                    currmax = max(currmax, jobDifficulty[k]); // Finding max difficulty in in days after today
                    dp[j] = min(dp[j], currmax + dp[k+1]); // Still not figure out dp[k+1] part
                }
            }
        }
        return dp[0];
    }
};
