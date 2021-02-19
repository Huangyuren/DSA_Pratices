// Nice BFS structure, deem words with exactly one char difference as adjancent nodes!
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> myset(wordList.begin(), wordList.end());
        if(myset.find(endWord) == myset.end()) return 0;
        queue<string> myqu;
        myqu.push(beginWord);
        int res = 1;
        while(myqu.size()) {
            // printf("Counter: %d\n", res);
            int tmpsize = myqu.size();
            for(int i=0; i<tmpsize; i++){
                string currstr = myqu.front();
                myqu.pop();
                if(currstr == endWord){
                    return res;
                }
                for(int j=0; j<currstr.size(); j++){
                    char currchar = currstr[j];
                    for(int k=0; k<26; k++){
                        char iterchar = 'a' + k;
                        if(iterchar == currchar) continue;
                        currstr[j] = iterchar;
                        if(myset.find(currstr) != myset.end()){
                            myqu.push(currstr);
                            myset.erase(currstr);
                        }
                    }
                    currstr[j] = currchar;
                }
            }
            res++;
        }
        return 0;
    }
};
