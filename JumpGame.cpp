class Solution {
public:
    // DP solution, not as fast as expected.
    // bool canJump(vector<int>& nums) {
    //     int n = nums.size();
    //     if(n==0) return false;
    //     if(nums[0]==0 && n==1) return true;
    //     vector<bool> dp(n, false);
    //     dp[n-1] = true;
    //     for(int i=n-2; i>=0; i--){
    //         for(int j=0; j<=nums[i]; j++){
    //             if(dp[i+j]){
    //                 dp[i] = true;
    //                 break;
    //             }
    //         }
    //     }
    //     return dp[0];
    // }
    // Too slow, we can greedly choose farthest distance at each "valid" iteration.
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int farthest = 0;
        for(int i=0; i<n; i++){
            if(farthest < i) return false; // Have to at least be able to reach this point.
            farthest = max(farthest, i + nums[i]); // farthest point capability.
        }
        return true;
    }
};
