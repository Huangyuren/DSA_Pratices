// bits manipulation, moving around bits to *2
class Solution {
public:
    int divide(int dividend, int divisor) {
        int sign = (dividend>0) == (divisor>0)? 1: -1;
        long a = labs(dividend), b = labs(divisor), res = 0, counter = 0; // using long whatever, otherwise this will become very hard
        if(dividend == INT_MIN && divisor==-1) return INT_MAX; // to avoid overflow
        if(a == INT_MAX && b == 1) return INT_MAX;
        while(a >= b){
            for(counter = 0; a - (b << counter << 1) >= 0; counter++); // b shift left for counter# times PLUS additional once
            res += 1 << counter;
            a -= b << counter;
        }
        return res*sign;
    }
};
