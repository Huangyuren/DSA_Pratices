#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    struct node {
        int rowid, colid, passvalue;
        node(int a, int b, int c) : rowid(a), colid(b), passvalue(c) {}
    };
    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();
        int rowp, colp, passvaluep;
        int direction[5] = {0, -1, 0, 1, 0};
        vector<vector<int>> distance(rows, vector<int>(cols, INT_MAX));
        auto cmp = [&](const node &a, const node &b) { return a.passvalue > b.passvalue; };
        priority_queue<node, vector<node>, decltype(cmp)> pq(cmp);
        pq.push(node(0,0,0));
        distance[0][0] = 0;
        while(!pq.empty()) {
            node tmp = pq.top();
            rowp = tmp.rowid, colp = tmp.colid, passvaluep = tmp.passvalue;
            pq.pop();
            if(rowp == rows-1 && colp==cols-1) break; // ???!
            if(passvaluep > distance[rowp][colp]) continue;
            for(int i=0; i<4; ++i) {
                int rowidx = rowp + direction[i];
                int colidx = colp + direction[i+1];
                if(rowidx>=0 && rowidx<rows && colidx>=0 && colidx<cols) {
                    int local_max = max(passvaluep, abs(heights[rowidx][colidx] - heights[rowp][colp]));
                    if(distance[rowidx][colidx] > local_max) {
                        distance[rowidx][colidx] = local_max;
                        pq.push(node(rowidx, colidx, local_max));
                    }
                }
            }
        }
        return distance[rows-1][cols-1];
    }
};
