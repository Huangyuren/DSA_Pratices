class Solution {
public:
    // brute force
    // int maxProduct(vector<int>& nums) {
    //     int ans=nums[0];
    //     for(int i=0; i<nums.size(); i++){
    //         int tmp = 1;
    //         for(int j=i; j<nums.size(); j++){
    //             tmp *= nums[j];
    //             ans = max(ans, tmp); // ans will register all-time best
    //         }
    //     }
    //     return ans;
    // }
    
    // DP, in each iteration, the max value depends on both min & max.
    // Since the current element could be either positive or negative integer.
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MIN;
        int maxsofar = 1;
        int minsofar = 1;
        for(int i=0; i<n; i++){
            if(nums[i] < 0){
                swap(maxsofar, minsofar);
            }
            maxsofar = max(nums[i], nums[i] * maxsofar);
            minsofar = min(nums[i], nums[i] * minsofar);
            ans = max(ans, maxsofar);
        }
        return ans;
    }
};
