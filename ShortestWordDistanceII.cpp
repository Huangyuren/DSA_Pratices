class WordDistance {
public:
    WordDistance(vector<string>& wordsDict) {
        n = wordsDict.size();
        for(int i=0; i<n; i++){
            mymap[wordsDict[i]].push_back(i); // Hint: i is already sorted
        }
    }
    
    int shortest(string word1, string word2) {
        vector<int> a = mymap[word1], b = mymap[word2];
        int res = n;
        // O(m + n) complexity on comparing on 2 sorted array
        for(int i=0, j=0; i<a.size() && j<b.size(); ){
            res = min(res, abs(a[i]-b[j]));
            if(a[i] < b[j]){
                i++;
            }else{
                j++;
            }
        }
        return res;
    }
private:
    unordered_map<string, vector<int>> mymap;
    int n;
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance* obj = new WordDistance(wordsDict);
 * int param_1 = obj->shortest(word1,word2);
 */
