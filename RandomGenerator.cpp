// Description as https://leetcode.com/discuss/interview-question/619524/Google-or-Onsite-or-Random-Generator
// Want to generate non-repeated random number in range(n)
// Let all return value be restricted in myvec[] where myvec[i] = i, and actively swap, so that we wont return
// repeated value.
class RandomGenerator {

private:
    // unordered_map<int,int>mymap;
    vector<int> myvec;
    int N;
    int num_call;
public:
    RandomGenerator(int n) {
        N=n;
        num_call=0;
        srand(time(NULL));
        for(int i=0; i<=n; i++){
            myvec.push_back(i);
        }
    }
    
    int generate() {
        if(num_call >= N)return -1;

        int pos = N-num_call+1; // pos = 11
        int gen = rand()%pos + num_call; // [0, 10]
        int res = myvec[gen];
        swap(myvec[pos],myvec[gen]);
        num_call++;

        return res;
    }
};

[0, ..., 10]

