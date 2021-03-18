// Two methods to encode hash_table's key, we should avoid using map since that is BST
// 1. encode by string, using gcd
// 2. write custom hash function
// Same starting point, hence slope can determine the only line
struct myhash {
    // custom hashing function
    size_t operator()(const pair<int, int>& p) const {
        return p.first ^ p.second;
    }
};
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size(), res = 1;
        for(int i=0; i<n; i++){
            int currx = points[i][0], curry = points[i][1];
            unordered_map<pair<int, int>, int, myhash> mymap; // another parameter for custom hashing func
            for(int j=i+1; j<n; j++){
                int dx = points[j][0] - currx, dy = points[j][1] - curry, currgcd = gcd(dx, dy);
                mymap[{dx/currgcd, dy/currgcd}] += 1; // still need to divided by gcd
            }
            for(auto& x : mymap){
                res = max(res, x.second+1);
            }
        }
        return res;
    }
    int gcd(int x, int y){
        return y==0 ? x : gcd(y, x%y);
    }
};
