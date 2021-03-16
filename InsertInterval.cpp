// Strictly find newInterval's closest left & right neightbor, which dont need to be modified
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if(intervals.empty()) return {newInterval};
        vector<vector<int>> res, backpart;
        for(auto& x : intervals){
            if(x[1] < newInterval[0]){ // closest left part
                res.push_back(x);
            }
            if(x[0] > newInterval[1]){ // closest right part
                backpart.push_back(x);
            }
        }
        // middle part
        int compareleft = res.size();
        int compareright = intervals.size() - backpart.size() - 1;
        int resleft, resright;
        // Two if case for edge cases
        if(compareleft == intervals.size()){
            res.push_back(newInterval); return res;
        }
        if(compareright == -1){
            res.push_back(newInterval);
        }
        // normal case, handle merged parts
        else{
            int resleft = min(intervals[compareleft][0], newInterval[0]);
            int resright = max(intervals[compareright][1], newInterval[1]);
            res.push_back({resleft, resright});
        }
        // eventually merging backpart with previous res
        for(auto& x : backpart){
            res.push_back(x);
        }
        return res;
    }
};
