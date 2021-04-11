// Using 2 bits to represent dead or live
// [2nd, 1st], since initially they are either 00(0) or 01(1)
// We only need to know when will 2nd state becomes live(1x)
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size(), n = board[0].size();
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                int currlive = 0;
                for(int k=-1; k<2; k++){
                    for(int l=-1; l<2; l++){
                        if(k==0 && l==0) continue;
                        int ni = i+k, nj = j+l;
                        if(ni>=0 && ni<m && nj>=0 && nj<n){
                            currlive += (board[ni][nj] & 1);
                        }
                    }
                }
                if(board[i][j]==1 && (currlive == 2 || currlive == 3)){
                    board[i][j] = 3; // [11]
                }else if(board[i][j] == 0 && currlive == 3){
                    board[i][j] = 2; // [10]
                }
            }
        }
        // All happened simultaneously
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                board[i][j] = board[i][j] >> 1;
            }
        }
        return;
    }
};
