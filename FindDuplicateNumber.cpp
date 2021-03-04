class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        for(int i=0; i<nums.size(); i++){
            int indextrue = abs(nums[i]) - 1; // if with same nums value, will have same currindex
            // Negative sign means that this element
            // has already been traversed, so ans is it.
            if(nums[indextrue] < 0){ // So by checking sign can determine visited or not
                return abs(nums[i]);
            }
            else
            {
                nums[indextrue] *= -1;
            }
        }
        return 0; // if no duplicates
    }
};
