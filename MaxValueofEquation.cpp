// yi + yj + xj - xi --> yi-xi + yj+xj
// j index can be fetched in each iteration
// yi-xi can be maintained in a max-deque (monotonic deque) with sliding window sized k
class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        deque<pair<int, int>> mydq; // { y-x, x }
        int res = INT_MIN;
        for(auto& curr : points){
            int xj = curr[0], yj = curr[1];
            while(mydq.size() && mydq.front().second + k < xj){
                mydq.pop_front(); // poping out outside of window size elements
            }
            if(mydq.size()){
                auto tmp = mydq.front();
                res = max(res, tmp.first + xj+yj);
            }
            // conduct monotonic step
            while(mydq.size() && mydq.back().first < yj-xj){
                mydq.pop_back();
            }
            mydq.push_back({yj-xj, xj});
        }
        return res;
    }
};
