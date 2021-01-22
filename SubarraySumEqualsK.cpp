// Same concepy as LeetCode 437, PathSumIII.
// Maintaining a hashmap for all interval's counter.
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mymap;
        mymap[0] = 1;
        int currsum = 0;
        int ans = 0;
        for(int i=0; i<nums.size(); i++){
            currsum += nums[i];
            if(mymap.find(currsum - k) != mymap.end()){
                ans += mymap[currsum - k];
            }
            mymap[currsum] += 1;
        }
        return ans;
    }
};
