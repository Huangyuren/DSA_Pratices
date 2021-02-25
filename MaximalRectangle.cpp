// The key point is to use three array to store global & local information
// left[] records all reasonable indexes
// right[] does same thing
// height[] does same thing
// currleft & curight will record local information !
// And will do O(n^2) maximum area checking.

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty()) return 0;
        int row = matrix.size();
        int col = matrix[0].size();
        vector<int> right(col, col);
        vector<int> left(col, 0);
        vector<int> height(col, 0);
        int maxarea = 0;
        for(int i=0; i<row; i++){
            int curleft=0, curight=col;
            for(int j=0; j<col; j++){ // left
                if(matrix[i][j] == '1'){
                    left[j] = max(left[j], curleft); //tightest
                }
                else
                { // reset
                    curleft = j+1; // Since we calculate area as right-left without + 1
                    left[j] = 0;
                }
            }
            for(int j=0; j<col; j++){ //height
                if(matrix[i][j] == '1'){
                    height[j] += 1;
                }
                else
                { // reset
                    height[j] = 0;
                }
            }
            for(int j=col-1; j>=0; j--){ //right, right->left, since right should > left
                if(matrix[i][j] == '1'){
                    right[j] = min(right[j], curight); // tightest
                }
                else
                { // reset, 
                    curight = j;  // Since we calculate area as right-left without + 1
                    right[j] = col;
                }
            }
            for(int j=0; j<col; j++){
                maxarea = max(maxarea, (right[j] - left[j])*height[j]);
            }
        }
        return maxarea;
    }
};
