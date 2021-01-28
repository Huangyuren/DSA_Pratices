// DFS for detecting cycle
// color: 
// 1: white
// 2: gray
// 3: black
// dfscycle: true: cycle exist, false: acyclic
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> color(numCourses, 1);
        buildgraph(graph, prerequisites);
        return !dfscycle(graph, color);
    }
    void buildgraph(vector<vector<int>>& graph, vector<vector<int>>& prerequisites){
        for(int i=0; i<prerequisites.size(); i++){
            graph[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
    }
    bool dfscycle(vector<vector<int>>& graph, vector<int>& color){
        for(int i=0; i<graph.size(); i++){
            if(color[i]==1){
                if(dfsutil(graph, color, i)){
                    return true;
                }
            }
        }
        return false;
    }
    bool dfsutil(vector<vector<int>>& graph, vector<int>& color, int start){
        color[start] = 2;
        for(auto& x : graph[start]){
            if(color[x] == 1){
                if(dfsutil(graph, color, x))
                    return true;
            }
            else if(color[x] == 2) // if gray met again, then cycle exists.
            {
                return true;
            }
        }
        color[start] = 3;
        return false;
    }
};
