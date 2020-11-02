class Solution {
public:
    const char vowel[5] = {'a','e','i','o','u'};
    int permu(int n, char input) {
        int tmpans=0;
        if(n != 1) {
            for(int i=0; i<5; ++i) {
                if(vowel[i] >= input) {
                    tmpans += permu(n-1, vowel[i]);
                }
            }
        }
        else {
            for(int i=0; i<5; ++i) {
                if(vowel[i] >= input) return 5-i;
                else continue;
            }
        }
        return tmpans;
    }
    int countVowelStrings(int n) {
        int ans = permu(n, 'a');
        return ans;
    }
};
