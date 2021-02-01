class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits == "") return {};
        vector<string> letter = {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> res;
        string currstr = "";
        solver(res, letter, currstr, digits, 0);
        return res;
    }
    void solver(vector<string>& res, vector<string>& letter, string currstr, string& digits, int start){
        // printf("Current string: %s, start: %d\n", currstr.c_str(), start);
        if(start == digits.size()){
            res.push_back(currstr);
            return;
        }
        int currpos = digits[start] - '0';
        for(int i=0; i < letter[currpos].size(); i++){
            solver(res, letter, currstr+letter[currpos][i], digits, start+1);
        }
        return;
    }
};
