// Binary indexed tree, see:
// https://leetcode.com/problems/range-sum-query-2d-mutable/discuss/75913/C%2B%2B-Binary-indexed-Tree-implementation
class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        _row = m; _col = n;
        nums = vector<vector<int>>(matrix);
        bitree = vector<vector<int>>(_row+1, vector<int>(_col+1, 0)); // since root is dummy node, biTree is [1...n]
        // Building my binary index tree
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                updateTree(i, j, nums[i][j]);
            }
        }
    }
    
    void update(int row, int col, int val) {
        updateTree(row, col, val - nums[row][col]);
        nums[row][col] = val;
        return;
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        // Think of as rectangle area
        return readTree(row2, col2) - readTree(row1-1, col2) - readTree(row2, col1-1) + readTree(row1-1, col1-1);
    }
private:
    vector<vector<int>> nums;
    vector<vector<int>> bitree;
    int _row;
    int _col;
    void updateTree(int idr, int idc, int val){
        for(int i=idr+1; i<=_row; i += (i & -i)){
            for(int j=idc+1; j<=_col; j += (j & -j)){
                bitree[i][j] += val;
            }
        }
    }
    int readTree(int rowrange, int colrange){
        int currsum = 0;
        // Beware that 0 is dummy node
        for(int i=rowrange+1; i>0; i -= (i & -i)){
            for(int j=colrange+1; j>0; j -= (j & -j)){
                currsum += bitree[i][j];
            }
        }
        return currsum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * obj->update(row,col,val);
 * int param_2 = obj->sumRegion(row1,col1,row2,col2);
 */
