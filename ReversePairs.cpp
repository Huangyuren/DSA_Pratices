class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int res = 0;
        solver(nums, 0, nums.size()-1, res);
        return res;
    }
    void solver(vector<int>& nums, int left, int right, int& res){
        if(left >= right) return;
        int mid = (left+right) / 2;
        solver(nums, mid+1, right, res);
        solver(nums, left, mid, res);
        // catch all elements that swap from right to left
        for(int i=left, j=mid+1; i<=mid; i++){
            while(j <= right && (long) nums[i] > (long) 2 * nums[j]){
                // Since both left & right sides are all sorted
                j++;
            }
            res += j - (mid+1);
        }
        inplace_merge(nums.begin()+left, nums.begin()+mid+1, nums.begin()+right+1);
    }
};
