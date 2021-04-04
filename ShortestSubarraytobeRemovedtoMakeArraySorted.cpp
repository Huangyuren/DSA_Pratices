// Many index tricks, start from right part for res convenience
class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();
        int r = n-1;
        for(; r>0 && arr[r-1] <= arr[r]; r--) ; // start from right is good
        int res = r; // now right pointer should just be the initial res
        for(int l=0; l<r && (l==0 || arr[l-1]<=arr[l]); l++){ 
            // l==0 || arr[l-1] <= arr[l], l should get into comparison at least once
            while(r<n && arr[r] < arr[l]){
                r++;
            }
            res = min(res, r-l-1);
        }
        return res;
    }
};
