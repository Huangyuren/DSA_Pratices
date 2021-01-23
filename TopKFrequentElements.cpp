#define pi pair<int, int>
class Solution {
public:
    bool sort_criterion(pair<int, int> a, pair<int, int> b){
        return a.second > b.second;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> mymap;
        vector<pi> invert_vec;
        vector<int> ans;
        for(int i=0; i<nums.size(); i++){
            mymap[nums[i]]++;
        }
        for(auto& x : mymap){
            invert_vec.push_back(make_pair(x.first, x.second));
        }
        sort(invert_vec.begin(), invert_vec.end(), [this](pi a, pi b) { return sort_criterion(a, b); });
        for(auto& x : invert_vec){
            if(k > 0)
                ans.push_back(x.first);
            k--;
        }
        return ans;
    }
};
