// First we traverse from boarder nodes with 'O'
// Then all nodes left with 'O' can be considered captured!
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if((i==0 || i==m-1 || j==0 || j==n-1) && board[i][j] == 'O'){
                    dfs(board, i, j, 1, m, n);
                }
            }
        }
        for(int i=1; i<m-1; i++){
            for(int j=1; j<n-1; j++){
                if(board[i][j] == 'O'){
                    dfs(board, i, j, 0, m, n);
                }
            }
        }
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(board[i][j] == '*'){
                    board[i][j] = 'O';
                }
            }
        }
        return;
    }
    void dfs(vector<vector<char>>& board, int i, int j, int boardmode, const int m, const int n){
        if(i<0 || i>m-1 || j<0 || j>n-1 || board[i][j] != 'O') return;
        if(boardmode == 1){
            board[i][j] = '*';
        }else{
            board[i][j] = 'X';
        }
        dfs(board, i-1, j, boardmode, m, n);
        dfs(board, i, j+1, boardmode, m, n);
        dfs(board, i+1, j, boardmode, m, n);
        dfs(board, i, j-1, boardmode, m, n);
        return;
    }
};
