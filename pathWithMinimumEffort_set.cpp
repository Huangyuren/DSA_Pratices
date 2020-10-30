struct obj {
        int r, c, dis;
        obj(int x, int y, int z) : r(x), c(y), dis(z) {}
};
bool operator<(const obj &a, const obj &b) { 
    if(a.dis == b.dis) {
        if(a.r != b.r) return a.r < b.r;
        return a.c < b.c;
    }
    return a.dis < b.dis;
}
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();
        int row, col, dist;
        vector<vector<int>> distance(rows, vector<int>(cols, INT_MAX));
        vector<int> direction = {0, -1, 0, 1, 0};
        set<obj> st;
        st.insert(obj(0,0,0));
        distance[0][0] = 0;
        while(!st.empty()) {
            obj tmp = *(st.begin());
            st.erase(st.begin());
            row = tmp.r, col = tmp.c, dist = tmp.dis;
            if(row == rows - 1 && col == cols - 1){
                break;  
            }
            if(dist < distance[row][col]) continue;
            for(int i=0; i<4; ++i) {
                int rowtmp = row + direction[i];
                int coltmp = col + direction[i+1];
                if(rowtmp < 0 || rowtmp >= rows || coltmp < 0 || coltmp >= cols) continue;
                int local_max_diff = max(dist, abs(heights[rowtmp][coltmp] - heights[row][col]));
                if(local_max_diff >= distance[rowtmp][coltmp]) continue;
                if(distance[rowtmp][coltmp] != INT_MAX) st.erase(st.find(obj(rowtmp, coltmp, distance[rowtmp][coltmp])));
                distance[rowtmp][coltmp] = local_max_diff;
                st.insert(obj(rowtmp, coltmp, local_max_diff));
            }
        }
        return distance[rows-1][cols-1];
    }
};
