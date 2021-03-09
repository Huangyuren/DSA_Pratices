// KMP algorithm
// Example:
// Haystack: abxabcabcaby
// Needle:   abcaby-------with lps=[0,0,0,1,2,0]
class Solution {
public:
    int strStr(string haystack, string needle){
        if(needle.empty()) return 0;
        int m = haystack.size(), n = needle.size();
        vector<int> lps = kmprocess(needle);
        int i, j;
        for(i=0, j=0; i<m;){
            if(haystack[i] == needle[j]){
                i++; j++;
            }
            if(j == n) return i-j;
            if(haystack[i] != needle[j]){
                if(j > 0){
                    j = lps[j-1]; // Next index in needle to compare (start from)
                }
                else{
                    i++; // Only increment on i
                }
            }
        }
        return -1;
    }
private:
    vector<int> kmprocess(string needle){
        int n = needle.size();
        int i,j; // i will run faster
        vector<int> lps(n, 0);
        for(i=1, j=0; i<n;){
            if(needle[i] == needle[j]){
                lps[i] = j+1;
                i++; j++;
            }
            else if(j>0){
                j = lps[j-1]; // This equation is the same as above function, same way
            }else{
                i++;
            }
        }
        return lps;
    }
};
