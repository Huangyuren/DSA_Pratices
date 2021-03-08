// Moving three pointers: first, second, third --> first, second, ......, third
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int currclosest = nums[0]+nums[1]+nums[2];
        for(int i=0; i<n-2; i++){
            if(i && nums[i] == nums[i-1]) continue;
            int j = i+1, k = n-1;
            while(j < k){
                int currsum = nums[i]+nums[j]+nums[k];
                if(currsum == target) return currsum;
                if(abs(target - currsum) < abs(target - currclosest)){
                    currclosest = currsum;
                }
                if(currsum < target){
                    j++;
                }
                if(currsum > target){
                    k--;
                }
            }
        }
        return currclosest;
    }
};
