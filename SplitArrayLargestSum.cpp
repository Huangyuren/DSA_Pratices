// New thing, lower bound binary search
// When we cannot perform binary search, that lower bound is our limit, thus return it
// For binary search, the range will be like [max element, currsum]
class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int minval = 0; // curr max element, binary search lower bound
        int maxval = 0; // curr summation, binary search upper bound
        int n = nums.size();
        for(int i=0; i<n; i++){
            minval = max(nums[i], minval);
            maxval += nums[i];
        }
        while(minval < maxval){
            int mid = minval + (maxval-minval)/2;
            if(cansplit(mid, nums, m)){
                maxval = mid;
            }
            else
            {
                minval = mid+1;
            }
        }
        return minval;
    }
    bool cansplit(int mid, vector<int>& nums, int m){
        int currsum = 0; // current summation
        int counter = 1; // should start from 1
        for(int i=0; i<nums.size(); i++){
            currsum += nums[i];
            if(currsum > mid){ // Finish one subarray parsing
                counter++;
                currsum = nums[i]; // Restart accumulation for another subarray!
                if(counter > m){
                    return false;
                }
            }
        }
        return true;
    }
};
