// Find a way to filter out as many indexs as possible in every run
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size()<1 || matrix[0].size()<1) return false;
        int row = 0;
        int col = matrix[0].size()-1;
        while(row < matrix.size() && col >=0){
            int tmp = matrix[row][col];
            if(target == tmp) return true;
            if(target > tmp){
                row++;
            }
            else
            {
                col--;
            }
        }
        return false;
    }
};
