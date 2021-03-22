// Similar idea as mutable problem, except we can use array range sum instead of binary index tree
class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        areadp = vector<vector<int>>(m+1, vector<int>(n+1, 0)); // add one is really convenient
        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                // think of set combination on area
                areadp[i][j] = areadp[i-1][j] + areadp[i][j-1] - areadp[i-1][j-1] + matrix[i-1][j-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        // O(1) operation area calculation, beware of the index
        return areadp[row2+1][col2+1] - areadp[row2+1][col1] - areadp[row1][col2+1] + areadp[row1][col1];
    }
private:
    vector<vector<int>> areadp;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
