// Rank based solution. The idea is all descendant nodes are with larger rand than current node
// Hence, we return lowest-rank all the way through DFS explored path
// See whether this return rand is larger than current node's rank or not
// Explained in comments
class Solution {
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> graph(n, vector<int>()); // adjacence list graph
        for(auto& x : connections){
            graph[x[0]].push_back(x[1]);
            graph[x[1]].push_back(x[0]);
        }
        vector<int> rankvec(n, -2);
        vector<vector<int>> res;
        dfsutil(graph, n, 0, 0, rankvec, res);
        return res;
    }
    int dfsutil(vector<vector<int>>& graph, int n, int currnode, int currank, vector<int>& rankvec, vector<vector<int>>& res){
        if(rankvec[currnode] != -2){ // if already visited, just return its rank
            return rankvec[currnode];
        }
        rankvec[currnode] = currank;
        int lowestrank = currank;
        for(auto& x : graph[currnode]){
            // Check records first
            if(rankvec[x] == currank-1 || rankvec[x] == n){
                // currank-1 == its parent node
                // n, scenario: this path contains cycle, and we are back at origin node, so this neighbor has been visited by us
                continue;
            }
            // At this point, will we start out dfs searching
            int neighborank = dfsutil(graph, n, x, currank+1, rankvec, res);
            lowestrank = min(lowestrank, neighborank); // record the lowest rank of all time
            if(neighborank > currank){
                // the returned lowest-rank of this path is larger than currank, ans is it
                res.push_back({currnode, x});
            }
        }
        rankvec[currnode] = n; // Marked as node's completion. Otherwise, when we backtrack to the origin node, may start duplicated path
        return lowestrank;
    }
};
