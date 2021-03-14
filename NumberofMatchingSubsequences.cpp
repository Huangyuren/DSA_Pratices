// Optimal solution:
// Parallel progress in each string of words
// We will actively keep track of each string's index until the index comes to the end of that string
class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        // Advancing char pointer in strings of words
        // Note that we should use const
        vector<const char*> waiting[128]; // since "z" is 122 in ASCII table
        // Or explicitly declare two vectors
        // vector<vector<const char*>> waiting(128); // prefer former, aware of [] bracket
        for(auto& x : words){
            waiting[x[0]].push_back(x.c_str());
        }
        for(char& c : s){
            auto tmp = waiting[c]; // vectors of char* pointers: {ptr1}, {ptr2},......
            waiting[c].clear(); // clean up
            for(auto& it : tmp){
                waiting[*++it].push_back(it);
            }
        }
        return waiting[0].size(); // once it goes to the end, *it will be 0
    }
};
