class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(s=="") return {};
        if(p.length() > s.length()) return {};
        vector<int> ans;
        vector<int> svec(26, 0);
        vector<int> pvec(26, 0);
        int p_size = p.length();
        for(int i=0; i<p_size; i++){
            svec[s[i] - 'a']++;
            pvec[p[i] - 'a']++;
        }
        if(svec == pvec) ans.push_back(0);
        for(int i=p_size; i<s.length(); i++){
            svec[s[i] - 'a']++;
            svec[s[i - p_size] - 'a']--;
            if(svec == pvec) ans.push_back(i - p_size + 1);
        }
        return ans;
    }
};
