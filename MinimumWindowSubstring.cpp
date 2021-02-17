// Varied-length window.
// Firstly we go through till the end of s,
// In this process, we dynamically adjust start position for finding smallest len.
class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size() < t.size()) return "";
        for(auto x : t){
            tmap[x] += 1;
        }
        int slen = s.size();
        int tcounter = t.size();
        int end=0, start=0;
        int res_start=0, res_length=INT_MAX;
        while(end < slen){
            tmap[s[end]]--;
            if(tmap[s[end]] >= 0){
                tcounter--;
            }
            end++;
            while(tcounter == 0){ // indicates that t are all in s
                if(end - start < res_length){
                    res_start = start;
                    res_length = end - start;
                }
                if(tmap[s[start]] >= 0){
                    tcounter++;
                }
                tmap[s[start]]++;
                start++;
            }
        }
        if(res_length == INT_MAX) return "";
        return s.substr(res_start, res_length);
    }
private:
    unordered_map<char, int> tmap; // t map: value, counter
};
