// #define pi pair<int, int>
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        unordered_map<int, int> mymap; // key & index of last appearance
        int target=0;
        for(int i=0; i<nums.size(); i++){
            mymap[nums[i]] = i;
        }
        for(int i=0; i<nums.size(); i++){
            if(i>0 && nums[i] == nums[i-1])
                continue;
            int sum2 = target - nums[i];
            for(int j=i+1; j<nums.size(); j++){
                if(j>i+1 && nums[j]==nums[j-1])
                    continue;
                int sum3 = sum2 - nums[j];
                unordered_map<int, int>::const_iterator got = mymap.find(sum3);
                if(got != mymap.end() && got->second > j){
                    ans.push_back({nums[i], nums[j], nums[got->second]});
                }
            }
        }
        return ans;
    }
};
