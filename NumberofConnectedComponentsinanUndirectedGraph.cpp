class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> color(n, 0);
        int res = 0;
        unordered_map<int, vector<int>> graph;
        for(int i=0; i<edges.size(); i++){
            int row = edges[i][0], col = edges[i][1];
            graph[row].push_back(col);
            graph[col].push_back(row);
        }
        for(auto x : graph){
            if(color[x.first] == 0){
                dfs(graph, color, x.first);
                res++;
            }
        }
        // last check for isolated nodes
        for(int i=0; i<color.size(); i++){
            if(color[i] == 0) res++;
        }
        return res;
    }
    void dfs(unordered_map<int, vector<int>>& graph, vector<int>& color, int pos){
        color[pos] = 1;
        for(int i=0; i<graph[pos].size(); i++){
            if(color[graph[pos][i]] == 0){
                dfs(graph, color, graph[pos][i]);
            }
        }
        color[pos] = 2;
    }
};
