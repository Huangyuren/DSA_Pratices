class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        for(int i=0; i<nums.size(); i++){
            int indextrue = abs(nums[i]) - 1;
            // Negative sign means that this element
            // has already been traversed, so ans is it.
            if(nums[indextrue] < 0){
                return abs(nums[i]);
            }
            else
            {
                nums[indextrue] *= -1;
            }
        }
        return 0;
    }
};
