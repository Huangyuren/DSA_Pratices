// Solved using bucket sort, since distance ranges from 1-2000, while coordinates range from 4e6
// Uniformed distributed, O(n) speeded up a lot
class Solution {
public:
    vector<int> assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        vector<vector<pair<int, int>>> buckets(2001); // distance possibilities < 2001, {workerid, bikeid}
        int n = workers.size(), m = bikes.size();
        for(int i=0; i<n; i++){
            // We compare workerid first
            for(int j=0; j<m; j++){
                // Finally is bikeid
                int dist = abs(workers[i][0] - bikes[j][0]) + abs(workers[i][1] - bikes[j][1]);
                buckets[dist].push_back({i, j});
            }
        }
        vector<int> res(n, -1);
        vector<bool> visitedbike(m, false);
        for(int i=0; i<2001; i++){
            for(int j = 0; j<buckets[i].size(); j++){
                // Traverse all pairs of this distance
                int workerid = buckets[i][j].first, bikeid = buckets[i][j].second;
                if(res[workerid] == -1 && visitedbike[bikeid] == false){
                    res[workerid] = bikeid;
                    visitedbike[bikeid] = true;
                }
            }
        }
        return res;
    }
};
