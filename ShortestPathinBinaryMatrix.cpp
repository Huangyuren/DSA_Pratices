// BFS can solve this single point shortest path problem, since there is no weight on this matrix
// BFS and dijkstra are conceptually same except dijkstra is for graph with unequal weight.
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] || grid[n-1][n-1]) return -1;
        queue<pair<int, int>> myqu;
        myqu.push({0, 0});
        int res = 0;
        while(myqu.size()){
            res++;
            int tmp = myqu.size();
            for(int i=0; i<tmp; i++){
                auto curr = myqu.front(); myqu.pop();
                int r = curr.first, c = curr.second;
                if(r==n-1 && c==n-1) return res;
                for(int j=-1; j<2; j++){
                    int tmpr = r+j;
                    for(int k=-1; k<2; k++){
                        if(j==0 && k==0) continue;
                        int tmpc = c+k;
                        if(tmpr>=0 && tmpr<n && tmpc>=0 && tmpc<n && grid[tmpr][tmpc]==0){
                            myqu.push({tmpr, tmpc});
                            grid[tmpr][tmpc] = 1;
                        }
                    }
                }
            }
        }
        return -1;
    }
};
