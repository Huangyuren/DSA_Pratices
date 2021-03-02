// DP solution
// The idea is that we will gradually segment out all words
// exist both in wordDict & s.
// For example, s = "garbages", wordDict={"garbage", "garb", "ages"}
// Resultant dp would be like: {true, false, false, false, true, false, false, true, true}
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        if(wordDict.size()==0) return false;
        if(s.size()==0) return true;
        unordered_map<string, int> mymap;
        for(int i=0; i<wordDict.size(); i++){
            mymap.emplace(wordDict[i], 1);
        }
        vector<bool> dp(s.size()+1, false); // With length s.size()+1, because of s.substr starting index
        dp[0] = true; // initial condition
        for(int i=1; i<=s.size(); i++){ // Since true will be assigned to dp[i]
            for(int j=i-1; j>=0; j--){
                if(dp[j]){
                    string tmp = s.substr(j, i-j);
                    if(mymap.find(tmp) != mymap.end()){
                        dp[i] = true;
                        break;
                    }
                }
            }
        }
        return dp[s.size()];
    }
};
