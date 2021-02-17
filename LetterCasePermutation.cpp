// Backtracking algorithm
// Lazily toggling character!
class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        if(S.empty()) return {};
        vector<string> res;
        solver(S, res, 0);
        return res;
    }
    void solver(string& s, vector<string>& res, int pos){
        if(pos >= s.size()){
            res.push_back(s);
            return;
        }
        solver(s, res, pos+1);
        if(isalpha(s[pos])){ // lazily check whether needs char toggling
            // character toggling
            s[pos] ^= (1<<5); // Since in ASCii, upper & lower diff in +-32!
            solver(s, res, pos+1);
        }
        return;
    }
};
