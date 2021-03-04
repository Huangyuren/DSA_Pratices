// One equation can be used to explain:
// x % 60 == (60-t) % 60 or more precise, x % 60 == (600-t) % 60, for x&t < 500
// For x + t = multiple of 60
class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int> vec(60, 0);
        int res = 0;
        for(auto x : time){
            res += vec[(600-x) % 60]; // counter part's counter(how many counter parts are there)
            vec[x % 60]++;
        }
        return res;
    }
};
