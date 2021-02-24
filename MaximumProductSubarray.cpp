class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.empty()) return 0;
        int maxsofar = 1; // For positive value
        int minsofar = 1; // For negative value
        int res = INT_MIN;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] < 0){
                swap(maxsofar, minsofar);
            }
            maxsofar = max(nums[i], maxsofar * nums[i]); // should take current into consideration, in case of 0
            minsofar = min(nums[i], minsofar * nums[i]); // should take current into consideration, in case of 0
            res = max(res, maxsofar);
        }
        return res;
    }
};
