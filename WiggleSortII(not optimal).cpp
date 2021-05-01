class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> sorted(nums);
        sort(sorted.begin(), sorted.end());
        int n = nums.size();
        // k = (n+1) / 2, Ex. n=7 or 8, create interleaving sense
        for(int i=n-1, k=(n+1)/2, j=0; i>=0; i--){
            if(i & 1){
                nums[i] = sorted[k++];
            }else{
                nums[i] = sorted[j++];
            }
        }
    }
};

// For example
// nums   = [1,3,2,2,3,1], n = 6
// sorted = [1,1,2,2,3,3], k = (n+1)/2 = 3
// larger part (with indices >= k) has 2,3,3 three elements, which are enough for odd positions

// nums   = [1,3,2,2,3,1,4], n = 7
// sorted = [1,1,2,2,3,3,4], k = (n+1)/2 = 4
// larger part (with indices >= k) has 3,3,4 three elements, which are enough for odd positions
