struct mynode{
    int i;
    int j;
    int dist;
    string path;
    mynode(int a, int b, int c, string d) : i(a), j(b), dist(c), path(d) {}
};
struct mycompare{
    bool operator()(const mynode& a, const mynode& b) {
        if(a.dist == b.dist){
            return a.path > b.path; // reversed order
        }
        return a.dist > b.dist;
    }
};
class Solution {
public:
    string findShortestWay(vector<vector<int>>& maze, vector<int>& ball, vector<int>& hole) {
        m = maze.size(); n=maze[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false)); // using one visited array to check validity
        priority_queue<mynode, vector<mynode>, mycompare> mypq;
        mypq.push(mynode(ball[0], ball[1], 0, ""));
        while(mypq.size()){
            auto curr = mypq.top(); mypq.pop();
            visited[curr.i][curr.j] = true; // Should set visited to true ONLY when item is popped from pq
            if(curr.i == hole[0] && curr.j == hole[1]) return curr.path;
            for(int j=0; j<4; j++){
                int tmpi = curr.i, tmpj = curr.j, tmpdist = curr.dist;
                string tmpstr = curr.path;
                while(tmpi + dir[j]>=0 && tmpi + dir[j]<m && tmpj + dir[j+1]>=0 && tmpj + dir[j+1]<n && \
                      maze[tmpi + dir[j]][tmpj + dir[j+1]] == 0){
                    tmpdist++;
                    tmpi += dir[j]; tmpj += dir[j+1];
                    if(tmpi == hole[0] && tmpj == hole[1]){
                        break; // maze III is hole, so we cannot just pass by the end
                    }
                }
                if(!visited[tmpi][tmpj]){
                    mypq.push(mynode(tmpi, tmpj, tmpdist, tmpstr + mapping[j]));
                    // NO visited[tmpi][tmpj] = true; here, since it will mislead shortest path criteria
                }
            }
        }
        return "impossible";
    }
private:
    int m, n;
    vector<int> dir = {-1,0,1,0,-1};
    vector<char> mapping = {'u', 'r', 'd', 'l'};
};
