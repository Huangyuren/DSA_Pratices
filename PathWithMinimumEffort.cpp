// The goal is to find a path with all-time minimum difference
// between two consecutive nodes.
// We can use dijkstra + priority queue to solve this.
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<int>> receffort(m, vector<int>(n, INT_MAX));
        vector<int> direction = {-1, 0, 1, 0, -1};
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        receffort[0][0] = 0;
        pq.push(make_pair(0, 0));
        int local_max = 0;
        while(pq.size()){
            int curreff = pq.top().first;
            int rowid = pq.top().second / 100, colid = pq.top().second % 100;
            pq.pop();
            if(rowid == m-1 && colid == n-1) return receffort[rowid][colid];
            for(int i=0; i<4; i++){
                int nrow = rowid + direction[i];
                int ncol = colid + direction[i+1];
                if(nrow >=0 && nrow < m && ncol>=0 && ncol<n){
                    local_max = max(curreff, abs(heights[rowid][colid] - heights[nrow][ncol]));
                    if(local_max < receffort[nrow][ncol]){ // if there is another path that shorter than current
                        receffort[nrow][ncol] = local_max;
                        pq.push(make_pair(local_max, nrow*100 + ncol));
                    }
                }
            }
        }
        return receffort[m-1][n-1];
    }
};
