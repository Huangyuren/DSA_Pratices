class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int mask = 0;
        int res = 0;
        for(int i=31; i>=0; i--){
            mask = mask | (1<<i); // Ex. 100..0, then 110..0, then 111..0 and so on
            unordered_set<int> currset;
            for(int x : nums){
                currset.insert(x & mask);
            }
            // Tricky part
            int currdesired = res | (1<<i); // Whether we can move res lefter or not
            for(int x : currset){
                int tmp = x ^ currdesired;
                if(currset.count(tmp)){ // Find two elements in set that can be xored as currdesired
                    res = currdesired;
                    break;
                }
            }
        }
        return res;
    }
};
