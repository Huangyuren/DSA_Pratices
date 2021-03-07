// Using sliding window speeds up many times
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.empty()) return 0;
        int left = 0, right=0, res=1, n=s.size();
        unordered_set<char> record;
        while(left < n && right < n){
            if(record.count(s[right]) == 0){
                record.insert(s[right]); // Remember to insert element
                res = max(res, right-left+1);
                right++;
            }
            else
            {
                record.erase(s[left]); // Remembera to delete element
                left++;
            }
        }
        return res;
    }
};
