class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // sort(intervals.begin(), intervals.end(), [](auto a, auto b) -> bool{ return a[0]<b[0];});
        // sorting will take intervals[i][0] as default values being compared.
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        res.push_back(intervals[0]);
        vector<int>* prev = &res.back();
        for(int i=1; i<intervals.size(); i++){
            if(prev->at(1) < intervals[i][0]){
                res.push_back(intervals[i]);
                prev = &res.back();
            }
            else
            {
                prev->at(1) = max(prev->at(1), intervals[i][1]);
            }
        }
        return res;
//         In clearer concepts
//         sort(intervals.begin(), intervals.end(), [](vector<int>a, vector<int>b) -> bool{return a[0]<b[0];});
//         vector<vector<int>> res;
//         res.push_back(intervals[0]);
//         for(int i=1; i<intervals.size(); i++){
//             int& prevpostval = res.back()[1];
//             int currfrontval = intervals[i][0];
//             if(prevpostval < currfrontval){
//                 res.push_back(intervals[i]); // OK, no overlapping
//             }
//             else
//             {
//                 prevpostval = max(prevpostval, intervals[i][1]); // Overlapped, Update previous second value
//             }
//         }
//         return res;
    }
};
