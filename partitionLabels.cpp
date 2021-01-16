/*
    Technique: using one set to represent current partition
    elements, and the key point is that once this set is
    empty, which means that there comes a minimalist set, so
    we can parse out this partition safely. Nice.
 */
class Solution {
public:
    vector<int> partitionLabels(string S) {
        unordered_map<char, int> mymap;
        vector<int> ans;
        for(int i=0; i<S.size(); i++){
            mymap[S[i]]++;
        }
        set<char> pool;
        int res=0;
        for(int i=0; i<S.size(); i++){
            res++;
            mymap[S[i]]--;
            if(pool.find(S[i]) == pool.end()){
                pool.insert(S[i]);
            }
            if(mymap[S[i]] == 0){
                pool.erase(S[i]);
            }
            if(pool.empty()){
                ans.push_back(res);
                res = 0;
            }
        }
        return ans;
    }
};
