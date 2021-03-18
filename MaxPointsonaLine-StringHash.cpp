// Two methods to encode hash_table's key, we should avoid using map since that is BST
// 1. encode by string, using gcd
// 2. write custom hash function
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size(), res = 0;
        for(int i=0; i<n; i++){
            int currx = points[i][0], curry = points[i][1], dupli = 1;
            unordered_map<string, int> mymap;
            for(int j=i+1; j<n; j++){
                if(points[j][0] == currx && points[j][1] == curry){
                    // for avoiding divide by zero
                    dupli++;
                }else{
                    int dx = points[j][0] - currx, dy = points[j][1] - curry;
                    int currgcd = gcd(dx, dy);
                    mymap[to_string(dx/currgcd) + "_" + to_string(dy/currgcd)] += 1;
                }
            }
            res = max(res, dupli);
            for(auto& x : mymap){
                res = max(res, x.second + dupli); // Because duplication is shared by everyone (duplicate == current point i)
            }
        }
        return res;
    }
    int gcd(int x, int y){
        while(y){
            x = x % y;
            swap(x, y);
        }
        return x;
    }
};
