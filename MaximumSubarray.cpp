// In each iteration, just consider whether current summation is larger than 0
// if yes, then continuing accumulation
// if no, then start over again
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.empty()) return 0;
        int n = nums.size();
        int res = nums[0];
        vector<int> dp(n);
        dp[0] = nums[0];
        for(int i=1; i<n; i++){
            if(dp[i-1] > 0){
                dp[i] = dp[i-1] + nums[i];
            }
            else
            {
                dp[i] = nums[i];
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};
