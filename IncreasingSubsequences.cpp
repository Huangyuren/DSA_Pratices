// A little tricky, we can remember its principle.
// Important, hash is declared every funtion call.
class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return {};
        vector<vector<int>> res;
        vector<int> currsequence;
        dfs(res, currsequence, nums, 0);
        return res;
    }
    void dfs(vector<vector<int>>& res, vector<int>& curr, vector<int>& nums, int pos){
        if(curr.size() >= 2) res.push_back(curr);
        unordered_set<int> myset; // For preventing [4,6,7(1)] then [4,6,7(2)], repeated 7
        for(int i=pos; i<nums.size(); i++){
            if(myset.count(nums[i])==0 && (curr.empty() || nums[i] >= curr.back())){ //if empty, won't do second comp
                curr.push_back(nums[i]); // backtracking algo
                dfs(res, curr, nums, i+1);
                curr.pop_back();
                myset.insert(nums[i]);
            }
        }
        return;
    }
};
