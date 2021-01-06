class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int sum = 0;
        for(auto a : nums){
            sum += a;
        }
        if(S > sum || (S+sum)%2==1) return 0;
        int target = (sum+S)/2;
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(target+1, 0));
        dp[0][0] = 1;
        for(int i=1; i<dp.size(); i++){
            for(int j=0; j<dp[0].size(); j++){
                dp[i][j] = dp[i-1][j];
                if(nums[i-1] <= j){
                    dp[i][j] += dp[i-1][j-nums[i-1]];
                }
            }
        }
        return dp[n][target];
    }
};
// Or more intuitive thinking
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        return backtrack(nums, S, 0, 0);
    }
    int backtrack(vector<int>& nums, int target, int curr_sum, int curr_index){
        if(curr_index == nums.size()){
            if(curr_sum == target){
                return 1;
            }
            return 0;
        }
        int positive = backtrack(nums, target, curr_sum+nums[curr_index], curr_index+1);
        int negative = backtrack(nums, target, curr_sum-nums[curr_index], curr_index+1);
        return positive + negative;
    }
};
