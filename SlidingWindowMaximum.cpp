// Maintaining a deque that stores indexes whose corresponding \
// elements are all larger than current considering \
// element: nums[i].
// Since all indexes will enter into deque exactly once, 
// Time complexity: O(n)
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(k > nums.size()) return {};
        vector<int> res;
        if(k == nums.size()){
            res.push_back(*max_element(begin(nums), end(nums)));
            return res;
        }
        deque<int> dq;
        for(int i=0; i<nums.size(); i++){
            if(dq.front() == i-k) dq.pop_front();// Pop out if needed.
            while(dq.size() && nums[dq.back()] < nums[i]){ // Ensuring that all elements in dq are larger than current.
                dq.pop_back();
            }
            dq.push_back(i);
            if(i-k+1 >= 0) res.push_back(nums[dq.front()]); // After certain duration, then we can push into res vector.
        }
        return res;
    }
};
