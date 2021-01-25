class Solution {
public:
    // int uniquePaths(int m, int n) {
    //     vector<vector<int>> map(m, vector<int>(n, 1));
    //     for(int i=1; i<m; i++){
    //         for(int j=1; j<n; j++){
    //             map[i][j] = map[i-1][j] + map[i][j-1];
    //         }
    //     }
    //     return map[m-1][n-1];
    // }
    // more space conservative
    int uniquePaths(int m, int n) {
        // vector<int> prevec(n, 1);
        vector<int> currvec(n, 1);
        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                // currvec[j] = prevec[j] + currvec[j-1];
                // prevec is exactly equal to last iteration's currvec
                currvec[j] += currvec[j-1];
            }
            // swap(currvec, prevec);
        }
        // return prevec[n-1];
        return currvec[n-1];
    }
};
