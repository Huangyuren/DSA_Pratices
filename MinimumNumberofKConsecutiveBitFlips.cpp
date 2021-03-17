// Hard & tricky problem, hope to remember the process
// Flip is a XOR operation, so we only care about even or odd, that is, we don't really need to do flip
// By maintaining a flips counter, we can do %2 to get even or odd flips in current window
class Solution {
public:
    int minKBitFlips(vector<int>& A, int K) {
        int res = 0, flips = 0, n = A.size();
        for(int i=0; i<n; i++){
            if(A[i] == flips % 2){
                if(i+K > n) return -1; // cannot perform any flips, but here requires flipping, invalid
                res++; flips++;
                A[i] -= 2; // To mark that this index has been flipped, for afterwards checking
            }
            if(i >= K-1 && A[i-K+1] < 0){
                // We are about to go into new window range, check the very last window has been flipped
                // or not? Using A[i-k+1] --> front element of last window
                flips--;
                A[i-K+1] += 2;
            }
        }
        return res;
    }
};
