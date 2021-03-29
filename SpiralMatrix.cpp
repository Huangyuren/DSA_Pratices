class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> graph(m+2, vector<int>(n+2, -1));
        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                graph[i][j] = matrix[i-1][j-1];
            }
        }
        vector<int> res;
        solver(graph, res, 0, 1, 1);
        return res;
    }
    int solver(vector<vector<int>>& graph, vector<int>& res, int currdir, int i, int j){
        if(j == n+1 || (currdir==0 && graph[i][j]==-101)) return 1; // turn down
        if(i == m+1 || (currdir==1 && graph[i][j]==-101)) return 2; // turn left
        if(j == 0 || (currdir==2 && graph[i][j]==-101)) return 3; // turn up
        if(i == 0 || (currdir==3 && graph[i][j]==-101)) return 0; // turn right
        res.push_back(graph[i][j]);
        graph[i][j] = -101;
        int signalback = solver(graph, res, currdir, i+dir[currdir], j+dir[currdir+1]); // aim for detecting turning direction
        if(signalback == -1) return -1;
        if(graph[i+dir[signalback]][j+dir[signalback+1]] == -101) return -1; // detect for last element
        solver(graph, res, signalback, i+dir[signalback], j+dir[signalback+1]); // proceed on next direction exploring
        return -1; // exactly never executed
    }
private:
    int m, n;
    vector<int> dir = {0,1,0,-1,0}; // right, down, left, up
};
