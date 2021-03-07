// XORing all nums indexes & elements can obtain who is the missing value
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int xorres = n; // To complement the missed index, so that now all indexes are there
        for(int i=0; i<n; i++){
            xorres ^= i ^ nums[i];
        }
        return xorres; // This is the missing element
    }
};
