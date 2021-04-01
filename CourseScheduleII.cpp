// Same solution as Course Schedule I
// Since for those unrelated courses, we can place them at any places, all are valid!
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses, vector<int>());
        vector<int> degree(numCourses, 0);
        vector<int> res; // resultant vector for whether can we traverse all nodes
        for(auto x : prerequisites){
            graph[x[1]].push_back(x[0]); // Concept is that x[1] is prerequisite, so we should know how many courses need this x[1]
            degree[x[0]]++;
        }
        int n = numCourses; // checking for traversing all or not
        queue<int> myqu;
        for(int i=0; i<n; i++){
            if(degree[i]==0) myqu.push(i);
        }
        while(myqu.size()){
            int tmp = myqu.front(); myqu.pop(); 
            n--; // traverse this node, so subtraction
            res.push_back(tmp);
            for(auto x : graph[tmp]){
                // for all courses that need this x course as prerequisite
                // Now x is popped, so their degree should -1
                degree[x]--;
                if(degree[x] == 0){
                    myqu.push(x);
                }
            }
        }
        return n==0 ? res : vector<int>();
    }
};
