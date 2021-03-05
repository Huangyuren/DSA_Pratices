// Using recursive & substitution; plus an outer loop in mother function
// to invoke all possibilities of beginning.
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(word.length() == 0) return false;
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[i].size(); j++){
                if(dfsutil(board, i, j, word))
                    return true;
            }
        }
        return false;
    }
    bool dfsutil(vector<vector<char>>& board, int i, int j, string word){
        if(word.length() == 0) return true;
        bool res = false;
        if(i>=0 && i<board.size() && j>=0 && j<board[i].size() && board[i][j] == word[0]){
            board[i][j] = '*'; // Do substitution
            string sub = word.substr(1);
            res = (dfsutil(board,i-1,j,sub) || dfsutil(board,i,j+1,sub) || \
                        dfsutil(board,i+1,j,sub) || dfsutil(board,i,j-1,sub));
            board[i][j] = word[0]; // DFS reaches the end, restore back
        }
        return res;
    }
};
