// Review, backtracking algorithm. Push then pop for restoring status!
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        if(candidates.size()==0) return {};
        vector<vector<int>> res;
        vector<int> currcombination;
        solver(candidates, currcombination, res, target, 0);
        return res;
    }
    void solver(vector<int>& candidates, vector<int>& currcombination, vector<vector<int>>& res, int target, int start){
        if(target == 0){
            res.push_back(currcombination);
            return;
        }
        for(int i=start; i<candidates.size(); i++){
            if(target >= candidates[i]){
                currcombination.push_back(candidates[i]);
                solver(candidates, currcombination, res, target-candidates[i], i);
                currcombination.pop_back();
            }
        }
        return;
    }
};
