class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        if(candidates.size()==0) return {};
        sort(candidates.begin(), candidates.end());
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
            // Consider each element only once, 
            // Take [10,1,2,7,6,1,5] for example, after sorted: [1,1,2,5,6,7,10].
            // Here, i>start means that we have already considered [1,1,6], whose second [1] 
            // happens at start = 1, and i = 1 also. Without i>start comparison, we will get another
            // [1,1,6] when start=0, i=1, and that is abolished.
            if(i > 0 && i > start && candidates[i]==candidates[i-1]){
                continue;
            }
            if(target >= candidates[i]){
                currcombination.push_back(candidates[i]);
                solver(candidates, currcombination, res, target-candidates[i], i+1); // move i further in each turn.
                currcombination.pop_back();
            }
        }
        return;
    }
};
