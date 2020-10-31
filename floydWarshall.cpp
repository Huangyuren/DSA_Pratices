class Solution {
public:
    void printresult(vector<vector<int>> &inputs) {
        for(int i=0; i<inputs.size(); ++i) {
            for(int j=0; j<inputs[i].size(); ++j)  {
                if(inputs[i][j] == INT_MAX) continue;
                printf("%d, ", inputs[i][j]);
            }
            printf("\n");
        }
    }
    void floydWarshall(vector<vector<int>> &weights, vector<vector<int>> &graph, int n) {
        for(int k=0; k<n; ++k) {
            for(int i=0; i<n; ++i) {
                for(int j=0; j<n; ++j) {
                    weights[i][j] = min(weights[i][j], weights[i][k]+weights[k][j]);
                    // if(graph[i][k] && graph[k][j]) {
                        // if(weights[i][j] > weights[i][k]+weights[k][j]) {
                        //     weights[i][j] = weights[i][k]+weights[k][j];
                        //     weights[j][i] = weights[i][k]+weights[k][j];
                        //     graph[i][j] = 1;
                        //     graph[j][i] = 1;
                        // }
                    // }
                }
            }
        }
    }
    void makeMatrix(vector<vector<int>> &edges, vector<vector<int>> &graph, vector<vector<int>> &weights) {
        int rowid, colid;
        for(int i=0; i<graph.size(); ++i) graph[i][i] = 1, weights[i][i] = 0;
        for(int i=0; i<edges.size(); ++i) {
            rowid = edges[i][0], colid = edges[i][1];
            weights[rowid][colid] = edges[i][2];
            weights[colid][rowid] = edges[i][2];
            // graph[colid][rowid] = 1;
            // graph[rowid][colid] = 1;
        }
    }
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        int rows = edges.size();
        // vector<vector<int>> graph(n, vector<int>(n, 0));
        vector<vector<int>> weights(n, vector<int>(n, 10001));
        makeMatrix(edges, graph, weights);
        floydWarshall(weights, graph, n);
        printresult(weights);
        int ans_id=0, local_min = INT_MAX;
        for(int i=0; i<n; ++i) {
            int cnt = 0;
            for(int j=0; j<n; ++j) {
                if(weights[i][j] <= distanceThreshold) {
                    cnt++;
                }
            }
            printf("i: %d, cnt: %d\n", i, cnt);
            if(cnt <= local_min) {
                ans_id = i;
                local_min = cnt;
            }
        }
        return ans_id;
    }
};