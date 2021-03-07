// Point: left bracket <= n, and right bracket == left
// Recursive & logical thinking
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string currstr="";
        solver(res, currstr, 0, 0, n);
        return res;
    }
    void solver(vector<string>& res, string currstr, int leftcount, int rightcount, int lim){
        // printf("Left count: %d, right count: %d, currstr: %s\n", leftcount, rightcount, currstr.c_str());
        if(leftcount == lim && rightcount == lim){
            res.push_back(currstr);
            return;
        }
        if(leftcount < lim){
            solver(res, currstr+'(', leftcount+1, rightcount, lim); // Directly pass into function parameters, not modifying variables
        }
        if(rightcount < leftcount){
            solver(res, currstr+')', leftcount, rightcount+1, lim); // Directly pass into function parameters, not modifying variables
        }
        return;
    }
};
