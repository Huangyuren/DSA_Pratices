// Tricky practice, just interpret absent / present information as
// negative / positive sign on original vector~
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;
        for(int i=0; i<nums.size(); i++){
            int index_map = abs(nums[i]) - 1;
            // avoid negative & negative --> positive case.
            if(nums[index_map] > 0){
                nums[index_map] *= -1;
            }
        }
        for(int i=0; i<nums.size(); i++){
            if(nums[i] > 0) ans.push_back(i+1);
        }
        return ans;
    }
};
