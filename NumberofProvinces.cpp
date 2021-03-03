// Beware of DFS structure
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> color(n, 0); // 0:white, 1: grey, 2: black
        int res = 0;
        for(int i=0; i<n; i++){
            if(color[i] == 0){
                dfs(isConnected, color, i, res);
                res++; // Beware of res++ position
            }
        }
        return res;
    }
private:
    void dfs(vector<vector<int>>& isConnected, vector<int>& color, int index, int& res){
        color[index] = 1;
        for(int i=0; i<isConnected.size(); i++){
            if(isConnected[index][i] == 1 && color[i] == 0){
                dfs(isConnected, color, i, res);
            }
        }
        color[index] = 2;
        return;
    }
};
