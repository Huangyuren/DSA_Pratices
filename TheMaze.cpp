class Solution {
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        m = maze.size(); n=maze[0].size();
        // Separate map for recording visited or not, either we can record on the fly
        vector<vector<bool>> visited(m, vector<bool>(n, false)); // default is false
        queue<pair<int, int>> myqu;
        myqu.push({start[0], start[1]});
        while(myqu.size()){
            int tmpsize = myqu.size();
            for(int i=0; i<tmpsize; i++){
                auto curr = myqu.front(); myqu.pop();
                if(curr.first == destination[0] && curr.second == destination[1]) return true;
                visited[curr.first][curr.second] = true;
                for(int j=0; j<4; j++){
                    int tmpi = curr.first, tmpj = curr.second;
                    while(helper(maze, tmpi+dir[j], tmpj+dir[j+1])){
                        // maze[tmpi][tmpj] = 2; // We can ONLY record END points of rolling, all mid points are don't care
                        tmpi += dir[j]; tmpj += dir[j+1];
                    }
                    if(visited[tmpi][tmpj] == false) myqu.push({tmpi, tmpj});
                }
            }
        }
        return false;
    }
    bool helper(vector<vector<int>>& maze, int i, int j){
        if(i>=0 && i<m && j>=0 && j<n && maze[i][j] == 0) return true;
        return false;
    }
private:
    int m, n;
    vector<int> dir = {-1,0,1,0,-1};
};
// Faster technique is to place visited on the fly and inside the for loop of direction
class Solution {
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        m = maze.size(); n=maze[0].size();
        queue<pair<int, int>> myqu;
        myqu.push({start[0], start[1]});
        maze[start[0]][start[1]] = -1;
        while(myqu.size()){
            auto curr = myqu.front(); myqu.pop();
            if(curr.first == destination[0] && curr.second == destination[1]) return true;
            for(int j=0; j<4; j++){
                int tmpi = curr.first + dir[j], tmpj = curr.second + dir[j+1];
                bool isin = false;
                while(tmpi>=0 && tmpi<m && tmpj>=0 && tmpj<n && maze[tmpi][tmpj] <= 0){
                    isin = true;
                    tmpi += dir[j]; tmpj += dir[j+1];
                }
                if(isin){
                    tmpi -= dir[j], tmpj -= dir[j+1];
                    if(tmpi == destination[0] && tmpj == destination[1]) return true;
                    if(maze[tmpi][tmpj] == 0) {
                        maze[tmpi][tmpj] = -1;
                        myqu.push({tmpi, tmpj});
                    }
                }
            }
        }
        return false;
    }
private:
    int m, n;
    vector<int> dir = {-1,0,1,0,-1};
};
