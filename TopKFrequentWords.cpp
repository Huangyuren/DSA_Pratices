// Using both unordered_map & priority_queue to solve it
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> res;
        unordered_map<string, int> mymap;
        for(auto x : words){
            mymap[x] += 1;
        }
        // auto comp = [&](const pair<string, int>& a, const pair<string, int>& b) {
        //     return a.second > b.second || (a.second == b.second && a.first < b.first);
        // };
        // priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(comp)> mypq(comp);
        //
        // Or this method
        //
        priority_queue<pair<string, int>, vector<pair<string, int>>, mycomp> mypq;
        for(auto x : mymap){
            mypq.push({x.first, x.second});
            if(mypq.size() > k) mypq.pop();
        }
        while(mypq.size()){
            // res.push_back(mypq.top().first);
            res.insert(res.begin(), mypq.top().first);
            mypq.pop();
        }
        return res;
    }
private:
    struct mycomp {
        bool operator()(const pair<string, int>& a, const pair<string, int>& b){
            return a.second > b.second || (a.second == b.second && a.first < b.first);
        }
    };
};
