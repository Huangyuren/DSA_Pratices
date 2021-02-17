class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        unordered_map<int, int> mymap; // {index_1, index_2}
        for(int i=0; i<nums.size(); i++){
            int tmp = target - nums[i];
            if(mymap.count(tmp)){
                return {i, mymap[tmp]};
            }
            mymap.insert({nums[i], i});
        }
        return res;
    }
};
