class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0) return 1;
        if(n == INT_MIN){
            // INT_MIN handling for -INT_MIN will > INT_MAX, so do / 2 first
            n = n/2;
            x = x*x;
        }
        else if(n < 0){
            n *= -1;
            x = 1/x;
        }
        return n%2==0 ? myPow(x*x, n/2) : x * myPow(x*x, n/2);
    }
};
