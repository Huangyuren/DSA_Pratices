// Besides backtrack approach, actually it only needs to
// consider 2 steps before, since our strides are 1 or 2
class Solution {
public:
    int climbStairs(int n) {
        if(n==0) return 0;
        if(n==1) return 1;
        vector<int> res(n, 0);
        res[0] = 1;// actually, it is height = 1
        res[1] = 2;// actually, it is height = 2
        for(int i=2; i<n; i++){
            res[i] = res[i-1] + res[i-2];
        }
        return res[n-1];
    }
};
