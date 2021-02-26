// We can solve it using topological sort on defined DAG
// The defined DAG here is that the edge's direction will be {smaller --> larger} node
// Point from smaller elements to larger elements
// Once the DAG is determined, we can find longest path on this DAG
class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.empty()) return 0;
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> degree(m, vector<int>(n, 0));
        vector<int> direction = {-1, 0, 1, 0, -1};
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                for(int k=0; k<direction.size()-1; k++){
                    int tmprow = i+direction[k];
                    int tmpcol = j+direction[k+1];
                    if(tmprow>=0 && tmprow<m && tmpcol>=0 \
                        && tmpcol<n && matrix[tmprow][tmpcol] > matrix[i][j]){
                        degree[i][j] += 1;
                    }
                }
            }
        }
        queue<pair<int, int>> myqu;
        int res = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(degree[i][j] == 0){
                    myqu.push({i, j});
                }
            }
        }
        while(myqu.size()){
            int currsize = myqu.size(); // Beware of BFS pattern
            for(int i=0; i<currsize; i++){
                auto currpos = myqu.front(); myqu.pop();
                for(int j=0; j<direction.size()-1; j++){
                    int tmprow = currpos.first + direction[j];
                    int tmpcol = currpos.second + direction[j+1];
                    if(tmprow>=0 && tmprow<m && tmpcol>=0 && tmpcol<n){
                        if(matrix[tmprow][tmpcol] < matrix[currpos.first][currpos.second] && \
                           --degree[tmprow][tmpcol] == 0){
                            // Beware that since now we are tracking from deg(node)==0, the relation is "<"
                            myqu.push({tmprow, tmpcol});
                        }
                    }
                }
            }
            res++;
        }
        return res;
    }
};
