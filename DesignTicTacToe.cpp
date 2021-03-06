// single rows & cols vector can fulfill 2 player's case
// By ++ and --
// diagonal & antidiagonal check is also delighting
class TicTacToe {
public:
    /** Initialize your data structure here. */
    TicTacToe(int n) {
        _n = n;
        rows.resize(n, 0);
        cols.resize(n, 0);
        diagonal = 0; antidiagonal = 0;
    }
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        if(player == 1){
            rows[row]++; cols[col]++;
            if(row == col){
                diagonal++;
            }
            if(row+col == _n-1){
                antidiagonal++;
            }
            if(rows[row] == _n || cols[col]==_n || diagonal==_n || antidiagonal==_n) return 1;
            return 0;
        }
        else
        {
            rows[row]--; cols[col]--;
            if(row == col){
                diagonal--;
            }
            if(row+col == _n-1){
                antidiagonal--;
            }
            int tmpans = -1 * _n;
            if(rows[row] == tmpans || cols[col]==tmpans || diagonal==tmpans || antidiagonal==tmpans) return 2;
            return 0;
        }
    }
private:
    int _n;
    vector<int> rows, cols;
    int diagonal, antidiagonal;
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */
