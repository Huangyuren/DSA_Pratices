// Greedy approach
class Solution {
public:
    bool static mycompare(vector<int>& a, vector<int>& b){
        return a[1] > b[1]; // decreasing sequence by number of units
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), mycompare);
        int res = 0;
        for(auto& x : boxTypes){
            int tmp = min(truckSize, x[0]);
            res += tmp * x[1];
            truckSize -= tmp;
            if(truckSize == 0) return res;
        }
        return res;
    }
};
