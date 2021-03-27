class Solution {
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        m = maze.size(); n=maze[0].size();
        queue<pair<int, int>> myqu;
        myqu.push({start[0], start[1]});
        maze[start[0]][start[1]] = -1; // trick
        while(myqu.size()){
            auto curr = myqu.front(); myqu.pop();
            if(curr.first == destination[0] && curr.second == destination[1]) return true;
            for(int j=0; j<4; j++){
                int tmpi = curr.first, tmpj = curr.second;
                while(tmpi + dir[j]>=0 && tmpi + dir[j]<m && tmpj + dir[j+1]>=0 && tmpj + dir[j+1]<n && \
                      maze[tmpi + dir[j]][tmpj + dir[j+1]] <= 0){
                    tmpi += dir[j]; tmpj += dir[j+1];
                }
                if(tmpi == destination[0] && tmpj == destination[1]) return true;
                if(maze[tmpi][tmpj] == 0) {
                    maze[tmpi][tmpj] = -1;
                    myqu.push({tmpi, tmpj});
                }
            }
        }
        return false;
    }
private:
    int m, n;
    vector<int> dir = {-1,0,1,0,-1};
};
