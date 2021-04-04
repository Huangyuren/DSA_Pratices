// O(nlogn) method, can remember
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> resLength;
        for(int i=0; i<nums.size(); i++){
            auto x = lower_bound(resLength.begin(), resLength.end(), nums[i]);
            if(x == resLength.end()){
                // nums[i] is currently the largest element in res
                // The largest element apparently be indispensable for LIS, so push back
                resLength.push_back(nums[i]);
            }else{
                // nums[i] will <= x, so lets update x for more LIS-friendly
                *x = nums[i];
            }
        }
        return resLength.size(); // res size is the only valuable thing
    }
};

// O(n^2) dp classic solution
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        for(int i=1; i<n; i++){
            for(int j=0; j<i; j++){
                if(nums[j] < nums[i]){
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};
