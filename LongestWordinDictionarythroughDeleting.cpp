// Conditions:
// d[i] should be fully embraced by current string s, so matchindex==d[i].size()
// d[i]'s length should > res
// d[i] should be lexicographically larger, ex. a>b --> ASCii a(97) < b(98)
class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        string res;
        for(int i=0; i<d.size(); i++){
            int matchindex = 0;
            for(int j=0; j<s.size(); j++){
                if(s[j] == d[i][matchindex]){
                    matchindex++;
                }
            }
            if(matchindex == d[i].size() && (d[i].size() > res.size() || \
                                             d[i].size()==res.size() && d[i] < res)){
                res = d[i];
            }
        }
        return res;
    }
};
