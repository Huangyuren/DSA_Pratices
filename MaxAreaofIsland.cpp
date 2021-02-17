// Beaware to set visited symbol & the timing to set it.
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if(grid.empty()) return 0;
        int rows = grid.size();
        int cols = grid[0].size();
        queue<pair<int, int>> myqu;
        vector<int> directions = {-1, 0, 1, 0, -1};
        int res = 0;
        int iterterm = 0;
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(grid[i][j] == 0 || grid[i][j] == 2) continue;
                myqu.push(make_pair(i, j));
                grid[i][j] = 2; // Once pushed, set visited
                iterterm = 0;
                while(myqu.size()){
                    iterterm += 1;
                    int currow = myqu.front().first;
                    int curcol = myqu.front().second;
                    // printf("current count: %d, current row: %d, current col: %d\n", iterterm, currow, curcol);
                    myqu.pop();
                    for(int k=0; k<4; k++){
                        int tmprow = currow + directions[k];
                        int tmpcol = curcol + directions[k+1];
                        if(tmprow>=0 && tmprow<rows && tmpcol>=0 && tmpcol<cols && grid[tmprow][tmpcol]==1){
                            myqu.push(make_pair(tmprow, tmpcol));
                            grid[tmprow][tmpcol] = 2; // Once pushed, set visited
                        }
                    }
                }
                res = max(res, iterterm);
            }
        }
        return res;
    }
};
