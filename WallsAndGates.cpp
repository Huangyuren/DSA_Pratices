// Solved using dijkstra algo
class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        int m = rooms.size(), n = rooms[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        priority_queue<pair<int, int>, vector<pair<int, int>>, mycomp> mypq;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(rooms[i][j] == -1) visited[i][j] = true;
                else if(rooms[i][j] == 0){
                    visited[i][j] = true;
                    mypq.push({i*300+j, 0});
                } 
            }
        }
        while(mypq.size()){
            auto curr = mypq.top(); mypq.pop();
            int i=curr.first / 300, j = curr.first % 300;
            for(int k=0; k<4; k++){
                int tmpi = i+dir[k], tmpj = j+dir[k+1];
                if(tmpi<0 || tmpi>=m || tmpj<0 || tmpj>=n || visited[tmpi][tmpj]) continue;
                if(rooms[tmpi][tmpj] > curr.second + 1){
                    // relax
                    rooms[tmpi][tmpj] = curr.second + 1;
                    visited[tmpi][tmpj] = true;
                    mypq.push({tmpi*300+tmpj, rooms[tmpi][tmpj]});
                }
            }
        }
        return;
    }
private:
    vector<int> dir = {-1,0,1,0,-1};
    struct mycomp {
        bool operator()(const pair<int, int>& a, const pair<int, int>& b){
            return a.second > b.second;
        }
    };
};
