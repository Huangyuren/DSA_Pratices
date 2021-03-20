// Sliding window solution, firstly we plug whole window into cardPoints
// Then gradually delete from end, replace front with cardPoints' end
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int currsum = 0, res = 0;
        for(int i=0; i<k; i++){
            currsum += cardPoints[i];
        }
        res = max(res, currsum);
        for(int i=0; i<k; i++){
            currsum -= cardPoints[k-1-i]; // moving sliding window, delete one
            currsum += cardPoints[n-1-i]; // moving sliding window, add one
            res = max(res, currsum);
        }
        return res;
    }
};
