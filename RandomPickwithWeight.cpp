// Add up all elements respectively, and get help from upper_bound, solve this in space friendly way
class Solution {
public:
    Solution(vector<int>& w) {
        // Using std, partial_sum
        partial_sum(w.cbegin(), w.cend(), back_inserter(myvec));
        // learned, cbegin == const begin, back_inserter == push_back
    }
    
    int pickIndex() {
        int range = myvec.back();
        int curr = rand() % range;
        auto x = upper_bound(myvec.begin(), myvec.end(), curr);
        return x - myvec.begin();
        // Explanation on upper_bound:
        // Ex. curr = 5, which is the 6th number, and now myvec = {5, 5, 6}
        // So we should return index 1
    }
private:
    vector<int> myvec;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
