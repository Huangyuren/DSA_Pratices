class Solution {
public:
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        m = maze.size(); n=maze[0].size();
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX)); // distance matrix for dijkstra algorithm
        dist[start[0]][start[1]] = 0;
        queue<pair<int, int>> myqu; // using queue is enough, since distance information can be stored at dist matrix
        myqu.push({start[0], start[1]});
        while(myqu.size()){
            auto curr = myqu.front(); myqu.pop();
            for(int j=0; j<4; j++){
                int tmpi = curr.first, tmpj = curr.second;
                int l = dist[tmpi][tmpj];
                while(tmpi + dir[j]>=0 && tmpi + dir[j]<m && tmpj + dir[j+1]>=0 && tmpj + dir[j+1]<n && \
                      maze[tmpi + dir[j]][tmpj + dir[j+1]] == 0){
                    l++;
                    tmpi += dir[j]; tmpj += dir[j+1];
                }
                if(dist[tmpi][tmpj] > l){
                    // relax
                    dist[tmpi][tmpj] = l;
                    myqu.push({tmpi, tmpj});
                }
            }
        }
        return dist[destination[0]][destination[1]]==INT_MAX ? -1 : dist[destination[0]][destination[1]];
    }
private:
    int m, n;
    vector<int> dir = {-1,0,1,0,-1};
};
