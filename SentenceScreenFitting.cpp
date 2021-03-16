// (If naively using iterative method will TLE)
// See: https://leetcode.com/problems/sentence-screen-fitting/discuss/90845/21ms-18-lines-Java-solution
// start is current valid number of characters
// so we have to proactively finding word break in each row
class Solution {
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        string gatherstr;
        for(string& x : sentence) gatherstr += (" " + x);
        int start = 1; // escape first redundant " ", representing valid char nums
        int len = gatherstr.size();
        for(int i=0; i<rows; i++){
            start += cols;
            // We have to examine current start position is a empty character or not
            // If it is, then we can fitted into this row.
            // Otherwise, is previous a empty char? if yes, then it can fitted also.
            // If not, then --start and go into while loop for trying
            if(gatherstr[start % len] == ' '){
                start++; // proceed to next char
            }else{
                while(start && gatherstr[(start - 1) % len] != ' '){
                    start--; // adjust start by minus one valid char
                }
            }
        }
        start--; // first empty char
        return start / len;
    }
};
