#include <bits/stdc++.h>
using namespace std;

struct node {
    int opp=0, weights=0;
    node(int a, int b) : opp(a), weights(b) {}
};
class Solution {
public:
    void printvec(vector<vector<node>>& input){
        for(int i=0; i<input.size(); i++){
            for(int j=0; j<input[i].size(); j++){
                printf("%d, ", input[i][j].opp);
            }
            printf("\n");
        }
    }
    void initweights(int m, int n, vector<vector<int>>& grid, vector<vector<node>>& adj){
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(j+1 < n) {
                    adj[i*n+j].push_back(node(i*n+j+1, grid[i][j+1]));
                }
                if(i+1 < m) {
                    adj[i*n+j].push_back(node((i+1)*n+j, grid[i+1][j]));
                }
            }
        }
    }
    void dijkstra(int startpoint, vector<vector<node>>& adj, vector<int>& dist){
        queue<int> qu;
        qu.push(startpoint);
        dist[startpoint] = 0;
        while(qu.size()){
            int curr = qu.front();
            qu.pop();
            for(node tmpnode : adj[curr]){
                if(dist[tmpnode.opp] > dist[curr] + tmpnode.weights){
                    dist[tmpnode.opp] = dist[curr] + tmpnode.weights;
                    qu.push(tmpnode.opp);
                }
            }
        }
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<node>> adj(m*n, vector<node>());
        vector<int> dist(m*n, INT_MAX);
        initweights(m, n, grid, adj);
        // printvec(adj);
        dijkstra(0, adj, dist);
        return dist[m*n-1]+grid[0][0];
    }
};
