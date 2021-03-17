// DFS approach
// res will be updated upon one tree's searching reaches the end
class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        int res = 0;
        for(int i=0; i<manager.size(); i++){
            res = max(res, dfs(i, manager, informTime));
        }
        return res;
    }
    int dfs(int currid, vector<int>& manager, vector<int>& timelst){
        if(manager[currid] == -1){
            return timelst[currid]; // Reach boss, immediately return its time
        }else{
            // dfs till manager
            timelst[currid] += dfs(manager[currid], manager, timelst);
        }
        manager[currid] = -1; // recursion back at here, turning boss
        return timelst[currid];
    }
};
