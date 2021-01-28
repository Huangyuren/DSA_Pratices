class Solution {
public:
    int numSquares(int n) {
        if(n==0) return 0;
        vector<int> dp(n+1, INT_MAX);
        dp[0] = 0;
        dp[1] = 1;
        for(int i=2; i<dp.size(); i++){
            int tmp = sqrt(i);
            if(pow(tmp, 2) == i){
                dp[i] = 1;
            }
            else
            {
                for(int j=1; j<=tmp; j++){
                    // dp[i] = min(dp[i], dp[pow(j, 2)] + dp[i-pow(j, 2)]);
                    // since dp[pow(j, 2)] must be 1
                    dp[i] = min(dp[i], 1 + dp[i-pow(j, 2)]);
                }
            }
        }
        return dp[n];
    }
};
