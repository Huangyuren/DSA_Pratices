// Try to use indexes as reference for optimal efficiency
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        if(nums.empty()) return 1;
        int n = nums.size();
        for(int i=0; i<n; i++){
            // Using while loop to swap until valid / unable
            while(nums[i]>0 && nums[i] <= n && nums[nums[i]-1] != nums[i]){
                //Conditions: in valid range and with different values
                swap(nums[i], nums[nums[i]-1]);
            }
        }
        for(int i=0; i<n; i++){
            if(nums[i]-1 != i){
                return i+1;
            }
        }
        return n+1;
    }
};
