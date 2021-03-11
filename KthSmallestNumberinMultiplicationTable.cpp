// Index management is tricky, with wise partition function
class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        int left = 0;
        int right = m*n+1; // right should be larger enough, othrewise left will easily exceed right
        int mid = 0;
        while(left < right){ // no =
            mid = left + (right-left)/2;
            int tmp = partition(mid, m, n);
            // We cannot simply return mid when tmp == k, since mid may not in multiplication table
            if(tmp >= k){
                right = mid; // right without +1
            }else{
                left = mid+1; // left with mid + 1
            }
        }
        return right;
    }
    int partition(int mid, int m, int n){
        int res = 0;
        for(int i=1; i<=m; i++){
            int tmp = min(n, mid/i); // We only need to count "how many elements can be divided by current row number"
            res += tmp;
        }
        return res; // This return number includes itself(mid) and all its duplicates
    }
};
