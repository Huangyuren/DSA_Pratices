// straight forward backtracking method
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res;
        vector<int> tmp;
        solver(nums, res, tmp, n, 0);
        return res;
    }
    void solver(vector<int>& nums, vector<vector<int>>& res, vector<int>& tmp, const int n, int pos){
        if(pos >= n){
            res.push_back(tmp);
            return;
        }
        tmp.push_back(nums[pos]);
        solver(nums, res, tmp, n, pos+1);
        tmp.pop_back();
        // pos + 1 for jump over some positions
        solver(nums, res, tmp, n, pos+1);
        return;
    }
};
