// Not ordinary BFS problem, since there may be multiple oranges in the very first iteration
// We should scan through grid at first and find rotten oranges
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> myqu;
        int freshcount = 0; // count for fresh ones, edge cases
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==2){
                    myqu.push({i,j});
                }
                if(grid[i][j]==1){
                    freshcount++; // Count all fresh oranges
                }
            }
        }
        if(freshcount == 0) return 0; // There has no fresh oranges
        int res = 0;
        while(myqu.size()){
            int tmpsize = myqu.size();
            bool hasprogress = false; // minutes count only when there is orange turned rotted in this iteration
            for(int k=0; k<tmpsize; k++){
                int row = myqu.front().first, col = myqu.front().second; 
                myqu.pop();
                for(int i=0; i<4; i++){
                    int rownew = row+direction[i][0], colnew = col+direction[i][1];
                    if(rownew>=0 && rownew<grid.size() && colnew>=0 && colnew<grid[0].size() && grid[rownew][colnew]==1){
                        grid[rownew][colnew] = 2;
                        freshcount--; // Decrement in fresh oranges
                        hasprogress = true;
                        myqu.push({rownew, colnew});
                    }
                }
            }
            if(hasprogress) res++;
        }
        if(freshcount > 0) return -1;
        return res;
    }
private:
    vector<vector<int>> direction = {{-1,0},{0,1},{1,0},{0,-1}};
};
