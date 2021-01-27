/* 
    * All we need to consider is that,
    * when deciding rob this house or not, 2 options: rob(then we can't rob previous), don't rob
    * So the recursive relation is really simple!
    * The rest things are indexing management, why we place dp[0] = 0, not dp[0] = nums[0]?
    * Try some testcases and will see.
*/
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==0) return 0;
        if(nums.size()==1) return nums[0];
        vector<int> dp(nums.size()+1, -1);
        dp[0] = 0;
        dp[1] = nums[0];
        // Decision starts from nums[1]!
        for(int i=1; i<nums.size(); i++){
            dp[i+1] = max(dp[i-1]+nums[i], dp[i]);
        }
        return dp[nums.size()];
    }
};
