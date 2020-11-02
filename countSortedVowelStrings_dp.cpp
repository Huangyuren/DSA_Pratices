class Solution {
    public:
        int countVowelStrings(int n) {
            map<char, int> mp;
            const char vowel[5] = {'a', 'e', 'i', 'o', 'u'};
            for(int i=0; i<5; ++i) {
                mp[vowel[i]] = 1;
            }
            for(int i=2; i<=n; ++i) {
                // for(int j=0; j<5; ++j) {
                //     int tmp=0;
                //     for(int k=j; k<5; ++k) {
                //         tmp += mp[vowel[k]];
                //         mp[vowel[j]] = tmp;
                //     }
                // }
                // or
                mp['a'] = mp['a']+mp['e']+mp['i']+mp['o']+mp['u'];
                mp['e'] = mp['e']+mp['i']+mp['o']+mp['u'];
                mp['i'] = mp['i']+mp['o']+mp['u'];
                mp['o'] = mp['o']+mp['u'];
            }
            int ans=0;
            for(int i=0; i<mp.size(); ++i) {
                ans += mp[vowel[i]];
            }
            return ans;
        }
};
