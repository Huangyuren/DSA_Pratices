// Using modified binary search to do this.
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.empty()) return {-1, -1};
        int n = nums.size();
        vector<int> res;
        binarysearch(nums, target, 0, n/2, res);
        binarysearch(nums, target, n/2 + 1, n-1, res);
        sort(res.begin(), res.end());
        if(res.size()==0){
            res.push_back(-1);
            res.push_back(-1);
        }
        else if(res.size()==1)
        {
            res.push_back(res[0]);
        }
        else
        {
            int front = res[0];
            int end = res[res.size()-1];
            res.clear();
            res.push_back(front);
            res.push_back(end);
        }
        return res;
    }
    void binarysearch(vector<int>& nums, int target, int left, int right, vector<int>& res){
        if(left > right || (left == right && nums[left] != target)) return;
        int mid = (left + right) / 2;
        if(nums[mid] == target){
            res.push_back(mid);
            binarysearch(nums, target, left, mid-1, res);
            binarysearch(nums, target, mid+1, right, res);
        }
        else if(nums[mid] > target)
        {
            binarysearch(nums, target, left, mid-1, res);
        }
        else
        {
            binarysearch(nums, target, mid+1, right, res);
        }
    }
};
