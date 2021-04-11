// Overflow correction: distangle res's formulation
class Solution {
public:
    int reverse(int x) {
        if(x==0) return 0;
        int sign = x>0 ? 1 : -1;
        x = abs(x); // Important, INT_MIN after absed, is still INT_MIN since overflow
        int res = 0;
        while(x > 0){
            // Hence, the condition should not be x != 0
            if(INT_MAX / 10 < res || (INT_MAX-x%10) < res*10) return 0; // 2 conditions according to next line of code
            res = res * 10 + x%10; // Firstly cleanup one digit room for x%10, then addup together
            x = x/10;
        }
        return res * sign;
    }
};
