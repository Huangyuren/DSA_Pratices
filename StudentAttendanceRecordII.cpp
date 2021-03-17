// Thinking: https://leetcode.com/problems/student-attendance-record-ii/discuss/101651/Python-Straightforward-DP-with-Explanation
// Explain:
// Initial conditions, a, b, c stands for without Absent, and d, e, f stands for with Absent, and gradually respectively no-L, L, LL
// Consider three attendance possibilities: Present, Late, Absent, logical thinking above 6 cases will evolve.
// (Late is only effective with keyword consecutive)
// Use long to prevent overflow
class Solution {
public:
    int checkRecord(int n) {
        long baselimit = pow(10, 9) + 7;
        // Round 1
        long a = 1, b=1, d=1; // P, L, A respectively
        long c = 0, e=0, f=0; // LL, AL(possible), LLA cannot fit into round 1, so skip, 0
        for(int i=1; i<n; i++){
            long prea=a, preb=b, prec=c, pred=d, pree=e, pref=f; // backup value
            a = (prea+preb+prec) % baselimit; // Present, because additional present will cause Late non-consecutive
            b = prea; // Present
            c = preb; // Late
            d = (prea+preb+prec + pred+pree+pref) % baselimit; // abc + Absent and def + Present, note that in both cases, Late will be broke
            e = pred; // Late
            f = pree; // Late
        }
        return int((a+b+c+d+e+f) % baselimit);
    }
};
