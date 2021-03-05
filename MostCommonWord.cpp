// Remove all punctuation using isalpha()
// Convert to lower case using tolower()
class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        for(auto& x : paragraph){
            if(!isalpha(x)) x = ' ';
            else x = tolower(x);
        }
        unordered_set<string> mybanned(banned.begin(), banned.end());
        unordered_map<string, int> mymap;
        pair<string, int> dummy{"", 0}; // Used to track our answer, so that we don't need (ordered)map
        istringstream iss(paragraph);
        string tmp;
        while(iss >> tmp){
            if(mybanned.find(tmp) == mybanned.end()){
                mymap[tmp]++;
                if(mymap[tmp] > dummy.second){
                    dummy = {tmp, mymap[tmp]};
                }
            }
        }
        return dummy.first;
    }
};
