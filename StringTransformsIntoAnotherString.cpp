// All about transformation, if the map has recorded a {a, b} match
// When we discover a again, the corresponding str2[x] should be b, othrewise false
// Really challenging thinking
class Solution {
public:
    bool canConvert(string str1, string str2) {
        if(str1 == str2) return true;
        if(str1.size() != str2.size()) return false;
        unordered_map<char, char> mymap;
        for(int i=0; i<str1.size(); i++){
            if(mymap.count(str1[i]) && mymap[str1[i]] != str2[i]){
                return false; // case mentioned above, since these two str1[i] are bounded together
            }
            mymap[str1[i]] = str2[i];
        }
        return set(str2.begin(), str2.end()).size() < 26; // if str2's size is 26, then there has no temporary char for substitution
    }
};
