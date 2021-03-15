// Backtracking algo + dfs, but can be shorten and more clean
class Solution {
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int res = INT_MIN, itermax = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] != 0){
                    dfs(i, j, itermax, res, grid, m, n);
                }
            }
        }
        return res;
    }
    void dfs(int rowid, int colid, int& itermax, int& res, vector<vector<int>>& grid, const int m, const int n){
        int backup = grid[rowid][colid];
        itermax += backup;
        grid[rowid][colid] = -1;
        for(int i=0; i<4; i++){
            int nextrow = rowid + direction[i][0];
            int nextcol = colid + direction[i][1];
            if(nextrow>=0 && nextrow<m && nextcol>=0 && nextcol<n && grid[nextrow][nextcol]>0){
                dfs(nextrow, nextcol, itermax, res, grid, m, n);
            }
        }
        res = max(res, itermax);
        itermax -= backup;
        grid[rowid][colid] = backup;
        return;
    }
private:
    vector<vector<int>> direction = {{-1,0},{0,1},{1,0},{0,-1}};
};
// Pure DFS thinking & backtrack, shorter code
class Solution {
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int res = INT_MIN;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                res = max(res, dfs(i, j, grid)); // no need to place res into params
            }
        }
        return res;
    }
    int dfs(int i, int j, vector<vector<int>>& grid){
        // Checking code write at the begining
        if(i>=0 && i<grid.size() && j>=0 && j<grid[0].size() && grid[i][j]>0){
            grid[i][j] = -grid[i][j]; // Simply multiply by -1, easy to restore
            int res = max({dfs(i-1, j, grid), dfs(i, j+1, grid), dfs(i+1, j, grid), dfs(i, j-1, grid)});
            grid[i][j] = -grid[i][j];
            return res + grid[i][j];
        }else{
            return 0;
        }
    }
};
