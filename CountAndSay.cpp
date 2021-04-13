// Simple solution that iteratively counts
class Solution {
public:
    string countAndSay(int n) {
        if(n==1) return "1"; // initial stat
        if(n==2) return "11"; // initial stat
        string prevstr = countAndSay(n-1);
        string res = "";
        int count=1;
        for(int i=1; i<prevstr.size(); i++){
            if(prevstr[i-1] == prevstr[i]){
                count++;
            }else{
                res += (to_string(count)+prevstr[i-1]);
                count = 1;
            }
            if(i == prevstr.size()-1){
                res += (to_string(count)+prevstr[i]);
            }
        }
        return res;
    }
};
