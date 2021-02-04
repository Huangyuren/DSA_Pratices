// Maintain a count map of all elements in nums!
// Since this is subsequence, good idea.
class Solution {
public:
    int findLHS(vector<int>& nums) {
        if(nums.size()==0) return 0;
        unordered_map<int, int> mymap;
        for(int i=0; i<nums.size(); i++){
            mymap[nums[i]]++;
        }
        int key;
        int res = INT_MIN;
        for(auto& x : mymap){
            key = x.first;
            if(mymap.count(key+1)){
                // Check one way is enough
                res = max(res, x.second + mymap[key+1]);
            }
        }
        if(res == INT_MIN) res = 0;
        return res;
    }
};
