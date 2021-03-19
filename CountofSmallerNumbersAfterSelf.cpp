// by counting how many elements swapped from current val's right to left, we will get the answer
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
		vector<int> res(n, 0);
		vector<pair<int, int>> vecpair(n);
		for(int i=0; i<n; i++){
			vecpair[i] = {nums[i], i};
		}
        solver(vecpair, res, 0, n-1); // do custom merge sort here
        return res;
    }
    void solver(vector<pair<int, int>>& vecpair, vector<int>& res, int left, int right){
        if(left >= right) return;
        int mid = (left+right)/2;
        solver(vecpair, res, left, mid);
        solver(vecpair, res, mid+1, right);
        // Count how many elements swap from right to left?
        auto mycomp = [&](const pair<int, int>& a, const pair<int, int>& b) { return a.first < b.first; };
        for(int i=mid; i>=left; i--){
            // Starting from left half's largest element, since we can early stopping
            auto curr = lower_bound(vecpair.begin()+mid+1, vecpair.begin()+right+1, vecpair[i], mycomp);
            int elementcounts = distance(vecpair.begin()+mid+1, curr);
            // int elementcounts = curr - (vecpair.begin()+mid+1); // also ok
            if(elementcounts == 0) break; // early stopping, since left part's largest element is larger than all of right part
            res[vecpair[i].second] += elementcounts;
        }
        // C++ STL, merge two consecutive sorted range: [first, middle) & [middle, last), nice!
        inplace_merge(vecpair.begin()+left, vecpair.begin()+mid+1, vecpair.begin()+right+1);
        return;
    }
};
