// Greedy solution concept
class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        return solver(s, wordDict);
    }
private:
    unordered_map<string, vector<string>> mymap; // memorization
    vector<string> solver(string s, vector<string>& wordDict){
        if(s.empty()) return {" "};
        if(mymap.count(s)) return mymap[s];
        vector<string> rightpart;
        vector<string> res;
        for(auto x : wordDict){
            string curr = s.substr(0, x.size());
            if(curr == x){
                string next = s.substr(curr.size());
                rightpart = solver(next, wordDict); // vector of word sequences with spaces
            }
            else
            {
                continue;
            }
            for(auto y : rightpart){
                if(y == " ") res.push_back(curr);
                else res.push_back(curr+" "+y); // y is another word sequence with spaces
            }
        }
        mymap[s] = res;
        return res;
    }
};
