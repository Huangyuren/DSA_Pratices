// Solved by dp
// 1D linear dp, building block in range(0, amount)!
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount==0) return 0;
        vector<int> dp(amount+1, INT_MAX-2);
        dp[0] = 0;
        for(int i=0; i<=amount; i++){
            for(int j=0; j<coins.size(); j++){
                if(coins[j] <= i){
                    dp[i] = min(dp[i], dp[i-coins[j]] + 1);
                }
            }
        }
        return dp[amount] <= amount ? dp[amount] : -1;
    }
};
