class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.empty()) return 0;
        int maxsofar = 1; // For positive value, and should be careful, initialized by 1
        int minsofar = 1; // For negative value, and should be careful, initialized by 1
        int res = INT_MIN; // Need additional res for return, not returning maxsofar
        for(int i=0; i<nums.size(); i++){
            if(nums[i] < 0){
                swap(maxsofar, minsofar);
            }
            maxsofar = max(nums[i], maxsofar * nums[i]); // should take current value into consideration, in case of 0
            minsofar = min(nums[i], minsofar * nums[i]); // should take current value into consideration, in case of 0
            res = max(res, maxsofar);
        }
        return res;
    }
};
